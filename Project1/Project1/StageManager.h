#pragma once
#include"Utill.h"
#include"Player.h"
#include"Enemy.h"

#define ENEMY_COUNT 10

class StageManager:public Singletone<StageManager>
{
public:
	Player* player;
	Enemy* enemies[ENEMY_COUNT];

	int currentStage;
	bool isPartialClear;
	bool isClear;

	void InitStage();
	void ProgressStage();
	void RenderStage();
	void ReleaseStage();
	void StageLevelUp();
};

