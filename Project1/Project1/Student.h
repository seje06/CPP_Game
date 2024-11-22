#pragma once
class Student
{
public:
	Student(const char* _name, int _year, char _grade)
	{
		name = _name;
		year = _year;
		grade = _grade;
	}

	const char* name;
	int year;
	char grade;
};

