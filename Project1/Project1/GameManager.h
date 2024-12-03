#pragma once
#include<Windows.h>
#include"Singletone.h"
#include "Enums.h"

#define BufferWidth 80	
#define BufferHeight 40	

class GameManager:public Singletone<GameManager>
{

public:
	HANDLE hBuffer[2];
	float deltaTime;
	int frameSpeed;
	int screenIndex;
	SCENE_ID id;

	void Init(int frameSpeed,SCENE_ID id)
	{
		deltaTime = 0;
		this->frameSpeed = frameSpeed;
		this->id = id;
		screenIndex = 0;
	}

	void InitBuffer();
	void WriteBuffer(int x, int y, const char* shape, int color);
    void ReleaseBuffer();
	void FlipBuffer();
	void ClearBuffer();
};
GameManager* GameManager::instance = nullptr;
