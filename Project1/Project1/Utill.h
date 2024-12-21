#pragma once
#include <typeinfo>
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
	~Singletone()
	{
		if (instance != nullptr) delete instance;
		instance = nullptr;
	}
};
template<typename T>
T* Singletone<T>::instance = nullptr;


template<typename T>
using Action = T(*)();