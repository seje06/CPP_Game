#include "GameManager.h"


void GameManager::ManageScene()
{
	/*if (true)
	{
		int nextId = ((int)id) + 1;
		if (SCENE_MAXIMUM <= nextId)
		{
			nextId -= 1;
		}
		else
		{
			id = (SCENE_ID)nextId;
			sceneManagers[(int)id]->Init();
		}
	}*/

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		int nextId = ((int)id) + 1;
		if (SCENE_MAXIMUM <= nextId)
		{
			nextId -= 1;
		}
		else
		{
			id = (SCENE_ID)nextId;
			sceneManagers[(int)id]->Init();
		}
	}

	sceneManagers[(int)id]->Progress();
	sceneManagers[(int)id]->Render();
	//switch (id)
	//{
	//case SCENE_ID::LOGO:
	//	//ProgressLogo();
	//	break;
	//case SCENE_ID::STAGE:
	//	sceneManagers[(int)id]->Progress();
	//	RenderStage();
	//	break;
	//default:
	//	break;
	//}
}
