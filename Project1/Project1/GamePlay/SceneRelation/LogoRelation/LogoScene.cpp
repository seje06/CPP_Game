#include "LogoScene.h"
#include "../StageRelation/MapManager.h"
#include "BufferManager.h"
#include "Enums.h"
#include "../../GameManager.h"

LogoScene::LogoScene()
{
	GameManager::GetInstance()->AddSceneManager(this, SCENE_ID::LOGO);
}

void LogoScene::Init()
{
	
}

void LogoScene::Progress()
{
	// 간단 안내 렌더
	int cx = MAP_WIDTH / 2 - 8;
	int cy = MAP_HEIGHT / 2;
	BufferManager::GetInstance()->WriteBuffer(cx, cy - 1, "================", YELLOW);
	BufferManager::GetInstance()->WriteBuffer(cx, cy, "  Press ENTER  ", LIGHTGREEN);
	BufferManager::GetInstance()->WriteBuffer(cx, cy + 1, "================", YELLOW);
}

//void LogoScene::Render()
//{
//
//}
