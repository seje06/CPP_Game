#include "GameManager.h"

void GameManager:: InitBuffer()
{
	screenIndex = 0;

	COORD size = { BufferWidth, BufferHeight };

	SMALL_RECT rect = { 0, 0, BufferWidth - 1, BufferHeight - 1 };

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = FALSE;

	SetConsoleCursorInfo(hBuffer[0], &info);
	SetConsoleCursorInfo(hBuffer[1], &info);
}

void GameManager::WriteBuffer(int x, int y, const char* shape, int color)
{
	COORD pos = { x * 2, y };

	SetConsoleCursorPosition(hBuffer[screenIndex], pos);
	SetConsoleTextAttribute(hBuffer[screenIndex], color);

	DWORD dw;
	WriteFile(hBuffer[screenIndex], shape, strlen(shape), &dw, NULL);
}

void GameManager::ReleaseBuffer()
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}

void  GameManager::FlipBuffer()
{
	SetConsoleActiveScreenBuffer(hBuffer[screenIndex]);

	screenIndex = !screenIndex;
}

void GameManager::ClearBuffer()
{
	COORD pos = { 0,0 };
	DWORD dw;

	FillConsoleOutputCharacter(hBuffer[screenIndex], ' ', BufferWidth * BufferHeight, pos, &dw);
}

void GameManager::ManageScene()
{
	if (GetAsyncKeyState(VK_RETURN))
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
