#include "Gun.h"
#include"Time.h"

Gun::Gun(Pos& ownerPos, int& ownerDir, float speed, int ownerHeight,float reloadTime)
{
	pos = &ownerPos;
	dir = &ownerDir;
	this->speed = speed;
	this->ownerHeight = ownerHeight;
	this->reloadTime = reloadTime;

	Init();
}

void Gun::Init()
{
	for (int i = 0; i < BULLET_COUNT; i++)
	{
		bullets[i] = new Bullet();
		bullets[i]->isActive = false;
		bullets[i]->pos = *pos;
	}
}

void Gun::ControllBullet()
{
	reloadTime +=DeltaTime;
	if (GetAsyncKeyState(VK_LCONTROL) && reloadTime >= 0.3)
	{
		reloadTime = 0;
		for (int i = 0; i < BULLET_COUNT; i++)
		{
			if (!bullets[i]->isActive)
			{
				bullets[i]->isActive = true;
				//int addX = player->obj.dir == 0 ? -1 : 1;
				bullets[i]->pos.x =pos->x;
				bullets[i]->pos.y = pos->y + ownerHeight / 2;
				bullets[i]->dir = *dir;
				break;
			}
		}
	}

	for (int i = 0; i < BULLET_COUNT; i++)
	{
		if (bullets[i]->isActive)
		{
			if (bullets[i]->dir == 0) bullets[i]->pos.x -= speed * DeltaTime;
			else bullets[i]->pos.x += speed * DeltaTime;

			if (bullets[i]->pos.x > 30 || bullets[i]->pos.x < 0)  bullets[i]->isActive = false;
		}
	}
}
