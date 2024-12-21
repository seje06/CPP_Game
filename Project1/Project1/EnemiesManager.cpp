#include "EnemiesManager.h"


void EnemiesManager::Spawn()
{
	spawnTime += DeltaTime;
	if (spawnTime >= 2)
	{
		spawnTime = 0;
		for (int i = 0; i < ENEMY_COUNT; i++)
		{
			if (!enemies[i]->isActive)
			{
				int random = rand() % 2;
				enemies[i]->pos.x = random == 0 ? 1 : 29;

				enemies[i]->isActive = true;
				switch (enemies[i]->type)
				{
				case ENEMY_TYPE::EASY:
					enemies[i]->color = WHITE;
					enemies[i]->speed = 2;
					enemies[i]->hp = 3;
					break;
				case ENEMY_TYPE::GENERAL:
					enemies[i]->color = YELLOW;
					enemies[i]->speed = 4;
					enemies[i]->hp = 4;
					break;
				case ENEMY_TYPE::HARD:
					enemies[i]->color = BLUE;
					enemies[i]->speed = 6;
					enemies[i]->hp = 5;
					break;
				case ENEMY_TYPE::FREAKISH:
					enemies[i]->color = BROWN;
					enemies[i]->speed = 4;
					enemies[i]->hp = 4;
					break;
				case ENEMY_TYPE::HARD_FREAKISH:
					enemies[i]->color = RED;
					enemies[i]->speed = 6;
					enemies[i]->hp = 5;
					break;
				}

				break;
			}
		}
	}
}

void EnemiesManager::Controll(const Player& player)
{
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		if (enemies[i]->isActive)
		{
			// x贸府
			float xDif = (player.pos.x - enemies[i]->pos.x);

			if (xDif > 0)
			{
				enemies[i]->dir = (int)DIR::RIGHT;
				enemies[i]->pos.x +=DeltaTime * enemies[i]->speed;
				if (enemies[i]->pos.x == (int)enemies[i]->pos.x)
					enemies[i]->aniIndex = enemies[i]->aniIndex + 1 >= ENEMY_ANI_LENGTH ? 0 : enemies[i]->aniIndex + 1;

			}
			else if (xDif < 0)
			{
				enemies[i]->dir = (int)DIR::LEFT;
				enemies[i]->pos.x -= DeltaTime * enemies[i]->speed;
				if (enemies[i]->pos.x == (int)enemies[i]->pos.x)
					enemies[i]->aniIndex = enemies[i]->aniIndex + 1 >= ENEMY_ANI_LENGTH ? 0 : enemies[i]->aniIndex + 1;
			}

			if ((!enemies[i]->jumpInfo.isJumpUp && !enemies[i]->jumpInfo.isJumpDown))
			{
				int random = 0;
				//jump贸府
				switch (enemies[i]->type)
				{
				case ENEMY_TYPE::EASY:
					break;
				case ENEMY_TYPE::GENERAL:
					break;
				case ENEMY_TYPE::HARD:
					break;
				case ENEMY_TYPE::FREAKISH:
					random = rand() % 2;
					if (random == 1)
					{
						enemies[i]->jumpInfo.isJumpUp = true;
						enemies[i]->jumpInfo.isJumpDown = false;
						enemies[i]->jumpInfo.startJumpY = enemies[i]->pos.y;
					}
					break;
				case ENEMY_TYPE::HARD_FREAKISH:
					random = rand() % 2;
					if (random == 1)
					{
						enemies[i]->jumpInfo.isJumpUp = true;
						enemies[i]->jumpInfo.isJumpDown = false;
						enemies[i]->jumpInfo.startJumpY = enemies[i]->pos.y;
					}
					break;
				}
			}
			enemies[i]->ProcessGravity(ENEMY_HEIGHT, 3);
		}
	}
}

void EnemiesManager::Init()
{
	for (int i = 0; i < ENEMY_COUNT;i++)
	{
		enemies[i] = new Enemy();

		enemies[i]->isActive = false;
		
		enemies[i]->Init(0, 3, false, false, ENEMY_TYPE::EASY);
	}
}
