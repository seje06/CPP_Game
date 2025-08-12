#pragma once
//#include"Enums.h"
#include"SceneManager.h";


class LogoScene:public Singletone<LogoScene>, public SceneManager
{
public:
	LogoScene();
	virtual void Init() override;
	virtual void Progress() override;
};
