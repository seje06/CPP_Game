#include "StageManager.h"

void StageManager::InitStage()
{
	currentStage = 1;
	isPartialClear = true;
	isClear = false;
}

void StageManager::ProgressStage()
{
	if (player->isDie)return;
	if (isClear) return;


}

void StageManager::RenderStage()
{
}

void StageManager::ReleaseStage()
{
}

void StageManager::StageLevelUp()
{
	/*if (enemyManager->deathCount % 5 == 0 && enemyManager->deathCount != 0)
	{
		stageManager->currentStage++;
		enemyManager->deathCount = 0;
		stageManager->isPartialClear = true;
	}

	if (stageManager->isPartialClear)
	{
		int random;
		stageManager->isPartialClear = false;

		for (int i = 0; i < ENEMY_COUNT; i++)
		{
			enemies[i]->isDie = false;
			enemies[i]->hitTime = 0;
			enemies[i]->isHitting = false;
		}

		switch (stageManager->currentStage)
		{
		case 0:

			break;
		case 1:
			for (int i = 0; i < ENEMY_COUNT; i++)
			{
				enemyManager->enemiesType[i] = ENEMY_TYPE::EASY;
			}
			break;
		case 2:
			for (int i = 0; i < ENEMY_COUNT; i++)
			{
				random = rand() % 3;
				if (random == 0) enemyManager->enemiesType[i] = ENEMY_TYPE::EASY;
				else if (random == 1)enemyManager->enemiesType[i] = ENEMY_TYPE::GENERAL;
				else enemyManager->enemiesType[i] = ENEMY_TYPE::FREAKISH;
			}
			break;
		case 3:
			for (int i = 0; i < ENEMY_COUNT; i++)
			{
				random = rand() % 3;
				if (random == 0) enemyManager->enemiesType[i] = ENEMY_TYPE::GENERAL;
				else if (random == 1)enemyManager->enemiesType[i] = ENEMY_TYPE::HARD;
				else enemyManager->enemiesType[i] = ENEMY_TYPE::FREAKISH;
			}
			break;
		case 4:
			for (int i = 0; i < ENEMY_COUNT; i++)
			{
				random = rand() % 3;
				if (random == 0) enemyManager->enemiesType[i] = ENEMY_TYPE::HARD;
				else if (random == 1)enemyManager->enemiesType[i] = ENEMY_TYPE::FREAKISH;
				else enemyManager->enemiesType[i] = ENEMY_TYPE::HARD_FREAKISH;
			}
			break;
		case 5:
			stageManager->isClear = true;
			break;
		}
		stageManager->isPartialClear = false;
	}*/
}
