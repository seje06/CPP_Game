#include "LogoScene.h"

LogoScene::LogoScene()
{
	GameManager::GetInstance()->AddScene(this, SCENE_ID::LOGO);
}

void LogoScene::Init()
{
	
}

void LogoScene::Progress()
{
}

//void LogoScene::Render()
//{
//
//}
