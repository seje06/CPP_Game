#pragma once
#include"../Obj.h"

class Character: public Obj
{
public:
	float hitTime;
	int hp;
	bool isDie;
	bool isHitting;

protected:
	void Init(float hitTime,int hp, bool isDie, bool isHitting)
	{
		this->hitTime = hitTime;
		this->hp = hp;
		this->isDie = isDie;
		this->isHitting = isHitting;
	}
public:
	virtual ~Character() override
	{
		
	}
};

