#include "EnemiesManager.h"


void EnemiesManager::Spawn()
{
	spawnTime += GameManager::GetInstance()-> deltaTime;
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

void EnemiesManager::Controll(Player* player)
{
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		if (enemies[i]->isActive)
		{
			// x贸府
			float xDif = (player->obj.pos.x - enemies[i]->obj.pos.x);

			if (xDif > 0)
			{
				enemies[i]->obj.dir = RIGHT;
				enemies[i]->obj.pos.x += deltaTime * enemies[i]->obj.speed;
				if (enemies[i]->obj.pos.x == (int)enemies[i]->obj.pos.x)
					enemies[i]->obj.aniIndex = enemies[i]->obj.aniIndex + 1 >= PLAYER_ANI_LENGTH ? 0 : enemies[i]->obj.aniIndex + 1;

			}
			else if (xDif < 0)
			{
				enemies[i]->obj.dir = LEFT;
				enemies[i]->obj.pos.x -= deltaTime * enemies[i]->obj.speed;
				if (enemies[i]->obj.pos.x == (int)enemies[i]->obj.pos.x)
					enemies[i]->obj.aniIndex = enemies[i]->obj.aniIndex + 1 >= PLAYER_ANI_LENGTH ? 0 : enemies[i]->obj.aniIndex + 1;
			}

			if ((!enemies[i]->obj.jumper.isJumpUp && !enemies[i]->obj.jumper.isJumpDown))
			{
				int random = 0;
				//jump贸府
				switch (enemyManager->enemiesType[i])
				{
				case EASY:
					break;
				case GENERAL:
					break;
				case HARD:
					break;
				case FREAKISH:
					random = rand() % 2;
					if (random == 1)
					{
						enemies[i]->obj.jumper.isJumpUp = true;
						enemies[i]->obj.jumper.isJumpDown = false;
						enemies[i]->obj.jumper.startJumpY = enemies[i]->obj.pos.y;
					}
					break;
				case HARD_FREAKISH:
					random = rand() % 2;
					if (random == 1)
					{
						enemies[i]->obj.jumper.isJumpUp = true;
						enemies[i]->obj.jumper.isJumpDown = false;
						enemies[i]->obj.jumper.startJumpY = enemies[i]->obj.pos.y;
					}
					break;
				}
			}
			ProcessGravity(enemies[i]->obj, PLAYER_HEIGHT, 3);
		}
	}
}
