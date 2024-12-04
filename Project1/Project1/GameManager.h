#pragma once
#include<Windows.h>
#include"Utill.h"
#include "Enums.h"

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

	void Init(SCENE_ID id)
	{
		this->id = id;
		screenIndex = 0;
	}

	void InitBuffer();
	void WriteBuffer(int x, int y, const char* shape, int color);
    void ReleaseBuffer();
	void FlipBuffer();
	void ClearBuffer();
	
	void ManageScene();
};
GameManager* GameManager::instance = nullptr;
