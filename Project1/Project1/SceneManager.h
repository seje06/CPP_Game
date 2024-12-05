#pragma once
#include"Utill.h"
class SceneManager:public Singletone<SceneManager>
{
public:
	virtual void Init() {};
	virtual void Progress() {};
	virtual void Render() {};
};

