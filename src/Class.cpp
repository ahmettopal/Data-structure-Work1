#include "Class.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Class::Class()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			studentArray[i][j] = NULL;
		}
	}
}

Class::Class(char _className)
{
	className = _className;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			studentArray[i][j] = NULL;
		}
	}

}

void Class::CreateStudent()
{
	string read;
	ifstream ReadFile("School.txt");
	int line = 0;
	while (!ReadFile.eof())
	{
		getline(ReadFile, read);
		
		for (int i = 0; i < read.length(); i++)
		{
			if (i == 0)
			{
				continue;
			}
			else if (read[i] == ' ')
			{
				i--;
				continue;
			}
			else
			{
				studentArray[line][i - 1] = new Student(read[i]);
			}
		}
		line++;
	}
}

void Class::Write()
{
	for (int i = 0; i < 5; i++) // loop that display students on the screen
	{
		for (int j = 0; j < 4; j++)
		{
			cout << studentArray[j][i]->studentName << "  " << "(" << studentArray[j][i] << ")" << "   ";
		}
		cout << endl;
	}
}