#include"GameManager.h"


int main()
{
	int frameSpeed=2;

	GameManager::GetInstance()->Init(SCENE_ID::LOGO);

	ULONGLONG time = GetTickCount64();

	while (true)
	{
		if (time + 100 / frameSpeed <= GetTickCount64())
		{
			GameManager::GetInstance()->deltaTime = (GetTickCount64() - time) / 1000.0;
			time = GetTickCount64();
		}
	}

	return 0;
}