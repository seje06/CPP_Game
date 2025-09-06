#pragma once
#include<Windows.h>
#include"Utill.h"
#include "Enums.h"
#include"SceneRelation/SceneManager.h"

#define SCENE_MAXIMUM 2



class GameManager:public Singletone<GameManager>
{

public:
	SCENE_ID id;
	SceneManager* sceneManagers[SCENE_MAXIMUM] = {};


	void Init(SCENE_ID id)
	{
		this->id = id;

		if (sceneManagers[(int)id] != nullptr) sceneManagers[(int)id]->Init();

	}

	void AddSceneManager(SceneManager* manager, SCENE_ID id)
	{
		sceneManagers[(int)id] = manager;
	}

	
	void ManageScene();
};
//GameManager* GameManager::instance = nullptr;
