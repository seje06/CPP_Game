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
struct JumpeInfo
{
	float time;
	int startJumpY;
	bool isJumpUp;
	bool isJumpDown;
};




