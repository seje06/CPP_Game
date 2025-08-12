#include<iostream>
#include"GameManager.h"
#include"Time.h"
#include "BufferManager.h"
#include "LogoScene.h"
#include "StageManager.h"

using namespace std;

int main()
{
	int frameSpeed=2;
	LogoScene::GetInstance();
	StageManager::GetInstance();
	GameManager::GetInstance()->Init(SCENE_ID::LOGO);

	BufferManager::GetInstance()->InitBuffer();

	ULONGLONG time = GetTickCount64();

	while (true)
	{
		if (time + 100 / frameSpeed <= GetTickCount64())
		{
			//GameManager::GetInstance()->deltaTime = (GetTickCount64() - time) / 1000.0;
			SettableTime::deltaTime = (GetTickCount64() - time) / 1000.0;
			time = GetTickCount64();
			
			BufferManager::GetInstance()->ClearBuffer();
			GameManager::GetInstance()->ManageScene();

			BufferManager::GetInstance()->FlipBuffer();
			//BufferManager::GetInstance()->ClearBuffer();
		}
	}

	BufferManager::GetInstance()->ReleaseBuffer();
	return 0;
}