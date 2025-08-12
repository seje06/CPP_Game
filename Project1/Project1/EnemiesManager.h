#pragma once
#include"Enemy.h"
#include"Utill.h"
//#include"Time.h"
#include"Player.h"
#define ENEMY_COUNT 10

class EnemiesManager:public Singletone<EnemiesManager>
{
public:
	Enemy* enemies[ENEMY_COUNT];
	float spawnTime;
	int deathCount;
	bool isPartialClear;
	bool isAllClear;

	void Spawn();
	void Controll(const Player& player);
	void Init();
};
//EnemiesManager* EnemiesManager::instance = nullptr;
