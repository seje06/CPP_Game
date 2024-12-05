#pragma once
#include"GameManager.h"
#include"MapManager.h"
#include"Player.h"
#include"EnemiesManager.h"


class StageManager:public SceneManager
{
private:
	Player* player;
	int currentStage;
	

public:
	StageManager();
	virtual void Init() override;
	virtual void Progress() override;
	virtual void Render() override;
	void StageLevelUp();
};

