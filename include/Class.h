#pragma once
#include "Student.h"

class Class
{
public:
	Class();
	Class(char);
	char className;

	Student	*studentArray[15][15];
	
	void CreateStudent();
	void Write();
};
