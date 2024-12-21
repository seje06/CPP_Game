#pragma once
#include"Character.h"
#include "Gun.h"
#include "MapManager.h"
#include "StageEnums.h"
#define PLAYER_ANI_LENGTH 2
#define PLAYER_HEIGHT 3
#define PLAYER_MAX_HP 10

class Player : public Character
{
public:
	Gun* gun;
	void Init(float hitTime, int hp, bool isDie, bool isHitting)
	{
		const char*** shape[2];
		shape[0] = new const char**[PLAYER_ANI_LENGTH];
		shape[1] = new const char** [PLAYER_ANI_LENGTH];
		for (int i = 0; i < PLAYER_HEIGHT; i++)
		{
			shape[0][i] = new const char* [PLAYER_HEIGHT];
			shape[1][i] = new const char* [PLAYER_HEIGHT];
		}

		shape[0][0][0] = "〣";
		shape[0][0][1] = "自";
		shape[0][0][2] = "瓦";
		shape[0][1][0] = "〣";
		shape[0][1][1] = "自";
		shape[0][1][2] = "早";
		shape[1][0][0] = "〢";
		shape[1][0][1] = "肌";
		shape[1][0][2] = "瓦";
		shape[1][1][0] = "〢";
		shape[1][1][1] = "肌";
		shape[1][1][2] = "早";

		Pos pos;
		pos.x = 10; pos.y = 25;
		Obj::Init(shape, pos, COLOR::GREEN, 10);

		Character::Init(hitTime,hp, isDie,isHitting);
		gun = new Gun(pos, dir, speed, PLAYER_HEIGHT, 1);
	}

	virtual ~Player() override
	{
		for (int i = 0; i < 2; i++)
		{
			if (shape[i] != nullptr)
			{
				for (int j = 0; j < PLAYER_ANI_LENGTH; j++)
				{
					if (shape[i][j] != nullptr)
					{
						delete shape[i][j];
					}

				}
				delete shape[i];
			}
		}
		for (int i = 0; i < BULLET_COUNT; i++)
		{
			if(gun->bullets[i]!=nullptr)
			delete gun->bullets[i];
		}
	}

	void Controll();
};

