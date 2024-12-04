#pragma once
#include"Character.h"

#define ENEMY_ANI_LENGTH 2
#define ENEMY_HEIGHT 3

class Enemy : public Character
{
public:

	void Init(float hitTime, int hp, bool isDie, bool isHitting)
	{
		Character::Init(hitTime, hp, isDie, isHitting);
	}

	virtual ~Enemy() override
	{
		for (int i = 0; i < 2; i++)
		{
			if (shape[i] != nullptr)
			{
				for (int j = 0; j < ENEMY_ANI_LENGTH; j++)
				{
					if (shape[i][j] != nullptr)
					{
						delete shape[i][j];
					}
				}
				delete shape[i];
			}
		}
	}
};

