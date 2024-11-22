#pragma once
#include"Student.h"


class StudentManager
{
public:
	static  StudentManager*  instance;
public:
	~StudentManager()
	{
		for (int i = 0; i < studentCount; i++)
		{
			if(students[i]!=nullptr)
			delete students[i];
		}
		if(students!=nullptr)
		delete students;
	}
public:	
	Student** students=nullptr;
	
	int studentCount = 0;

	Student* Find(const char* name, int year, char grade)
	{
		for (int i = 0; i < studentCount; i++)
		{
			if (students[i]->name == name && students[i]->year == year && students[i]->grade == grade)
			{
				return students[i];
			}
		}
		return nullptr;
	}
};

StudentManager* StudentManager::instance = nullptr;

