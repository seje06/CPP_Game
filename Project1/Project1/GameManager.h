#pragma once
#include<Windows.h>
#include"Utill.h"
#include "Enums.h"
#include"SceneManager.h"

#define BufferWidth 80	
#define BufferHeight 40	
#define SCENE_MAXIMUM 2



class GameManager:public Singletone<GameManager>
{

public:
	HANDLE hBuffer[2];
	int screenIndex;
	float deltaTime = 0;
	SCENE_ID id;
	Action<void> initFuncs[2];
	SceneManager* sceneManagers[SCENE_MAXIMUM];
	
	GameManager()
	{
		for (int i = 0; i < SCENE_MAXIMUM; i++)
			sceneManagers[i] = nullptr;
	}

	void Init(SCENE_ID id)
	{
		this->id = id;
		screenIndex = 0;

		if (sceneManagers[(int)id] != nullptr) sceneManagers[(int)id]->Init();

	}

	void AddScene(SceneManager* manager, SCENE_ID id)
	{
		if (sceneManagers[(int)id] == nullptr) sceneManagers[(int)id] = manager;
	}

	void InitBuffer();
	void WriteBuffer(int x, int y, const char* shape, int color);
    void ReleaseBuffer();
	void FlipBuffer();
	void ClearBuffer();
	
	void ManageScene();
};
GameManager* GameManager::instance = nullptr;
