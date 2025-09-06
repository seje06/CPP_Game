#pragma once
#include<Windows.h>
#include"StageRelation.h"



#define BULLET_COUNT 10

class Gun
{
public:
	struct Bullet
	{
		Pos pos;
		int dir;
		bool isActive;
	};
	Bullet* bullets[10] = {};

	const Pos* pos;
	const int* dir;
	float speed;
	float reloadTime;
	int ownerHeight;

	Gun(Pos& ownerPos, int& ownerDir, float speed,int ownerHeight,float reloadTime);

	void Init();
	void ControllBullet();
};

