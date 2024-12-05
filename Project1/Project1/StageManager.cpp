#include "StageManager.h"

StageManager::StageManager()
{
	GameManager::GetInstance()->AddScene(this,SCENE_ID::STAGE);
}

void StageManager::Init()
{
	currentStage = 1;
}

void StageManager::Progress()
{
	if (player->isDie)return;
	if (EnemiesManager::GetInstance()->isAllClear) return;
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
				GameManager::GetInstance()->WriteBuffer(x, y, "■", CYAN);
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
		GameManager::GetInstance()->WriteBuffer((int)player->pos.x, player->pos.y + i, player->shape[player->dir][player->aniIndex][i], player->color);
	}
	//플레이어 상태
	for (int i = 0; i < player->hp; i++)
	{
		GameManager::GetInstance()->WriteBuffer(i + 1, 10, "♥", WHITE);
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
				GameManager::GetInstance()->WriteBuffer((int)enemy->pos.x, enemy->pos.y + j, enemy->shape[enemy->dir][enemy->aniIndex][j], enemy->color);

			}
		}
	}

	//총알
	/*int j = 0;
	for (int i = 0; i < BULLET_COUNT; i++)
	{
		if (bulletManager->bullets[i]->isActive)
		{
			WriteBuffer((int)bulletManager->bullets[i]->pos.x, bulletManager->bullets[i]->pos.y, "@", LIGHTMAGENTA);
		}
		else
		{
			WriteBuffer(++j + 20, 10, "@", WHITE);
		}
	}*/
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
