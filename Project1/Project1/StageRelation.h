#pragma once
#include "Enums.h"
#include <iostream>
#include <string>
using namespace std;

#define G 9.81
#define Vo 10

struct Pos
{
	float x;
	int y;
};
struct Jumper
{
	float time;
	int startJumpY;
	bool isJumpUp;
	bool isJumpDown;
};
class Obj
{
public:
	string** shape[2];
	Jumper jumper;
	Pos pos;
	float speed;
	int weight;
	int dir;
	int aniIndex;
	COLOR color;

	Obj() = default;
	Obj(string** shape[2],Pos pos, COLOR color)
	{
		this->shape[0] = shape[0];
		this->shape[1] = shape[1];
		this->pos = pos;
		this->color = color;
	}
};



