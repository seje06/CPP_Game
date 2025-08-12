#pragma once
//#include"GameManager.h"
//#include"BufferManager.h"
//#include"MapManager.h"
#include"Player.h"
//#include"EnemiesManager.h"
#include "SceneManager.h"


class StageManager:public Singletone<StageManager>,public SceneManager
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

	void SensePlayerHit();
	void SenseEnemyHit();

};

