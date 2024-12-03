#pragma once
#include"StageRelation.h"
#include"MapManager.h"
#include"GameManager.h"

class Character: public Obj
{
public:
	float hitTime;
	int hp;
	bool isDie;
	bool isHitting;

	void ProcessGravity(Obj& obj, int objHeight, int weight);
	
	
};

