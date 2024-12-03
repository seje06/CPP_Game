#include "Character.h"

void Character::ProcessGravity(Obj& obj, int objHeight, int weight)
{
	int preY = obj.pos.y;
	int nextY;


	//점핑 상태가 아닐시, obj 발밑 체크 후 상태 수정 
	if (MapManager::GetInstance()->map[obj.pos.y + objHeight][(int)obj.pos.x] != 1 && (!obj.jumper.isJumpUp && !obj.jumper.isJumpDown))
	{
		obj.jumper.isJumpDown = true;
		obj.jumper.isJumpUp = false;
		obj.jumper.startJumpY = preY;
	}

	float deltaTime = GameManager::GetInstance()->deltaTime;
	//점핑 상태일때 처리
	if (obj.jumper.isJumpUp || obj.jumper.isJumpDown)
	{
		obj.jumper.time += deltaTime * weight;
		float freeFallDis = -0.5 * G * obj.jumper.time * obj.jumper.time;
		float jumpDis = Vo * obj.jumper.time;

		//위로점프시
		if (obj.jumper.isJumpUp)
		{
			nextY = obj.jumper.startJumpY - (jumpDis + freeFallDis);

			//낙하로 전환시
			if (nextY > preY)
			{
				obj.jumper.isJumpUp = false;
				obj.jumper.isJumpDown = true;
				obj.jumper.startJumpY = preY;
				obj.jumper.time = 0;
				freeFallDis = -0.5 * G * obj.jumper.time * obj.jumper.time;
			}
			else
			{

			}
		}
		//추락시
		if (obj.jumper.isJumpDown)
		{
			nextY = obj.jumper.startJumpY - (freeFallDis);
			//player->pos.y = (int)nextY;

			//발밑 땅 상세 처리
			int yDif = nextY - preY;
			for (int i = 0; i < 1; i++)
			{
				for (int h = 0; h < yDif; h++)
				{

					if (MapManager::GetInstance()->map[preY + h + objHeight][(int)obj.pos.x + i] == 1)
					{
						obj.jumper.isJumpUp = false;
						obj.jumper.isJumpDown = false;
						obj.jumper.time = 0;
						nextY = preY + h;
						//player->pos.y = (int)nextY;
						break;
					}

				}
			}
		}

		obj.pos.y = (int)nextY;
	}
}