#pragma once
#include "Class.h"

class School
{
public:
	School();
	School(char);
	char writeClass;

	Class *classArray[15];
	
	void CreateClass();
	void Write();
};

