#pragma once
#include"StageRelation.h"
#include"StageEnums.h"
#include"MapManager.h"
#include"GameManager.h"
class Obj
{
public:
	string** shape[2];
	JumpeInfo jumpInfo;
	Pos pos;
	float speed;
	int weight;
	int dir;
	int aniIndex;
	COLOR color;
	
	Obj(string** shape[2], Pos pos, COLOR color,float speed)
	{
		this->shape[0] = shape[0];
		this->shape[1] = shape[1];
		this->pos = pos;
		this->color = color;
		this->speed = speed;
		
		jumpInfo.isJumpDown = true;
		jumpInfo.isJumpUp = false;
		jumpInfo.startJumpY = pos.y;
		jumpInfo.time = 0;

		dir = (int)DIR::RIGHT;
		aniIndex = 0;
	}

	virtual ~Obj()
	{

	}

	void ProcessGravity( int objHeight, int weight);
};

