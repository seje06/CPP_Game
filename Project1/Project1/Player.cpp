#include "Player.h"
#include "MapManager.h"
#include "StageEnums.h"
#include "Time.h"

void Player::Controll()
{
	float preX = pos.x;
	if (GetAsyncKeyState(VK_LEFT) && MapManager::GetInstance()->map)
	{
		dir = (int)DIR::LEFT;
		pos.x -= DeltaTime * speed;
		if ((int)preX != (int)pos.x)
			aniIndex = aniIndex + 1 >= PLAYER_ANI_LENGTH ? 0 : aniIndex + 1;
		if (MapManager::GetInstance()->map[pos.y][(int)(pos.x)] == 1 && (int)pos.x == MAP_WIDTH - 1) pos.x++;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		dir = (int)DIR::RIGHT;
		pos.x += DeltaTime * speed;
		if ((int)preX != (int)pos.x)
			aniIndex = aniIndex + 1 >= PLAYER_ANI_LENGTH ? 0 : aniIndex + 1;
		if (MapManager::GetInstance()->map[pos.y][(int)(pos.x)] == 1 && (int)pos.x == MAP_WIDTH - 1) pos.x--;
	}

	if (GetAsyncKeyState(VK_SPACE) && (!jumpInfo.isJumpUp && !jumpInfo.isJumpDown))
	{
		jumpInfo.isJumpUp = true;
		jumpInfo.isJumpDown = false;
		jumpInfo.startJumpY = pos.y;
	}

	ProcessGravity( PLAYER_HEIGHT, 3);
}
