#pragma once
template<typename T>
class Singletone
{
protected:
	static T* instance;
public:
	static T* GetInstance()
	{
		if (instance == nullptr) instance = new T();

		return instance;
	}
};


