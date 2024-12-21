#include "StageManager.h"

StageManager::StageManager()
{
	currentStage = 1;
	player = nullptr;
	GameManager::GetInstance()->AddScene(this,SCENE_ID::STAGE);
}

void StageManager::Init()
{
	currentStage = 1;

	player = new Player();
	player->Init(0, PLAYER_MAX_HP, false, false);
	EnemiesManager::GetInstance()->Init();

}

void StageManager::Progress()
{
	if (player->isDie)return;
	if (EnemiesManager::GetInstance()->isAllClear) return;

	StageLevelUp();
	EnemiesManager::GetInstance()->Spawn();
	player->Controll();
	player->gun->ControllBullet();
	EnemiesManager::GetInstance()->Controll(*player);
	SensePlayerHit();
	SenseEnemyHit();
}

void StageManager::Render()
{
	//맵
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			switch (MapManager::GetInstance()->map[y][x])
			{
			case 1:
				BufferManager::GetInstance()->WriteBuffer(x, y, "■", CYAN);
				break;
			default:
				break;
			}

		}
	}

	//스테이지 정보


	//플레이어
	for (int i = 0; i < PLAYER_HEIGHT; i++)
	{
		BufferManager::GetInstance()->WriteBuffer((int)player->pos.x, player->pos.y + i, player->shape[player->dir][player->aniIndex][i], player->color);
	}
	//플레이어 상태
	for (int i = 0; i < player->hp; i++)
	{
		BufferManager::GetInstance()->WriteBuffer(i + 1, 10, "♥", WHITE);
	}
	//const char* t = player->hitTime >= 1? "1":"0";
	//WriteBuffer(10, 10, t, WHITE);

	//적
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		Enemy* enemy = EnemiesManager::GetInstance()->enemies[i];
		if (enemy->isActive)
		{
			for (int j = 0; j < PLAYER_HEIGHT; j++)
			{
				BufferManager::GetInstance()->WriteBuffer((int)enemy->pos.x, enemy->pos.y + j, enemy->shape[enemy->dir][enemy->aniIndex][j], enemy->color);

			}
		}
	}

	//총알
	int j = 0;
	for (int i = 0; i < BULLET_COUNT; i++)
	{
		if (player->gun->bullets[i]->isActive)
		{
			BufferManager::GetInstance()->WriteBuffer((int)player->gun->bullets[i]->pos.x, player->gun->bullets[i]->pos.y, "@", LIGHTMAGENTA);
		}
		else
		{
			BufferManager::GetInstance()->WriteBuffer(++j + 20, 10, "@", WHITE);
		}
	}
}


void StageManager::StageLevelUp()
{
	
	if (EnemiesManager::GetInstance()->deathCount % 5 == 0 && EnemiesManager::GetInstance()->deathCount != 0)
	{
		currentStage++;
		EnemiesManager::GetInstance()->deathCount = 0;
		EnemiesManager::GetInstance()->isPartialClear = true;
	}

	if (EnemiesManager::GetInstance()->isPartialClear)
	{
		int random;
		EnemiesManager::GetInstance()->isPartialClear = false;

		for (int i = 0; i < ENEMY_COUNT; i++)
		{
			Enemy* enemy = EnemiesManager::GetInstance()->enemies[i];
			enemy->isDie = false;
			enemy->hitTime = 0;
			enemy->isHitting = false;
		}

		switch (currentStage)
		{
		case 0:

			break;
		case 1:
			for (int i = 0; i < ENEMY_COUNT; i++)
			{
				EnemiesManager::GetInstance()->enemies[i]->type = ENEMY_TYPE::EASY;
			}
			break;
		case 2:
			for (int i = 0; i < ENEMY_COUNT; i++)
			{
				Enemy* enemy = EnemiesManager::GetInstance()->enemies[i];
				random = rand() % 3;
				if (random == 0) enemy->type = ENEMY_TYPE::EASY;
				else if (random == 1)enemy->type = ENEMY_TYPE::GENERAL;
				else enemy->type = ENEMY_TYPE::FREAKISH;
			}
			break;
		case 3:
			for (int i = 0; i < ENEMY_COUNT; i++)
			{
				Enemy* enemy = EnemiesManager::GetInstance()->enemies[i];
				random = rand() % 3;
				if (random == 0) enemy->type = ENEMY_TYPE::GENERAL;
				else if (random == 1)enemy->type = ENEMY_TYPE::HARD;
				else enemy->type = ENEMY_TYPE::FREAKISH;
			}
			break;
		case 4:
			for (int i = 0; i < ENEMY_COUNT; i++)
			{
				Enemy* enemy = EnemiesManager::GetInstance()->enemies[i];
				random = rand() % 3;
				if (random == 0) enemy->type = ENEMY_TYPE::HARD;
				else if (random == 1)enemy->type = ENEMY_TYPE::FREAKISH;
				else enemy->type = ENEMY_TYPE::HARD_FREAKISH;
			}
			break;
		case 5:
			EnemiesManager::GetInstance()->isAllClear = true;
			break;
		}
		EnemiesManager::GetInstance()->isPartialClear = false;
	}
}

void StageManager::SensePlayerHit()
{
	if (player->isHitting)
	{
		player->hitTime += DeltaTime;
		if (player->hitTime >= 1) player->isHitting = false;
	}
	if (!player->isHitting)
	{
		for (int i = 0; i < ENEMY_COUNT; i++)
		{
			Enemy* enemy = EnemiesManager::GetInstance()->enemies[i];
			if (EnemiesManager::GetInstance()->enemies[i]->isActive)
			{
				if (enemy->pos.y <= player->pos.y + PLAYER_HEIGHT - 1 && enemy->pos.y + PLAYER_HEIGHT - 1 >= player->pos.y &&
					(int)enemy->pos.x == (int)player->pos.x)
				{
					player->isHitting = true;
					player->hp -= 1;
					player->hitTime = 0;
					if (player->hp <= 0) player->isDie = true;
					break;
				}
			}
		}
	}
}

void StageManager::SenseEnemyHit()
{
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		Enemy* enemy = EnemiesManager::GetInstance()->enemies[i];
		if (enemy->isActive)
		{
			if (enemy->isHitting)
			{
				enemy->hitTime += DeltaTime;
				if (enemy->hitTime >= 0)
				{
					enemy->hitTime = 0;
					enemy->isHitting = false;
				}
			}
			if (!enemy->isHitting)
			{
				for (int j = 0; j < BULLET_COUNT; j++)
				{
					if (enemy->pos.y <= player->gun->bullets[j]->pos.y && enemy->pos.y + PLAYER_HEIGHT - 1 >= player->gun->bullets[j]->pos.y &&
						(int)enemy->pos.x == (int)player->gun->bullets[j]->pos.x && player->gun->bullets[j]->isActive)
					{
						player->gun->bullets[j]->isActive = false;
						enemy->isHitting = true;
						enemy->hp -= 1;
						enemy->hitTime = 0;
						if (enemy->hp <= 0)
						{
							enemy->isDie = true;
							enemy->isActive= false;
							EnemiesManager::GetInstance()->deathCount++;
						}
					}
				}
			}
		}
	}
}

