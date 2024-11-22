#include<iostream>
#include"StudentManager.h"
#define STUDENT_COUNT 6
using namespace std;



void main()
{
	const char* names[STUDENT_COUNT] = {"kim","min","son" ,"nam" ,"bak" ,"pak"};
	int years[STUDENT_COUNT] = {1,1,2,2,3,3};
	char grades[STUDENT_COUNT] = {'A','B', 'B', 'A','C','B'};

	
	StudentManager::instance = new StudentManager;

	StudentManager::instance->students = new Student * [STUDENT_COUNT];
	for (int i = 0; i < STUDENT_COUNT; i++)
	{
		StudentManager::instance->students[i] = new Student(names[i], years[i], grades[i]);
	}

}
