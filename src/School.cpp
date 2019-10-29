#include "School.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
using namespace std;

School::School()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			classArray[i] = NULL;
		}
	}
}

School::School(char Class)
{
	writeClass = Class;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			classArray[i] = NULL;
		}
	}
}

void School::CreateClass()
{
	string read;
	ifstream readFile("School.txt");
	int counter = 0;
	while (!readFile.eof())
	{
		getline(readFile, read);
		for (int i = 0; i < read.length(); i++)
		{
			if (i == 0)
			{
				classArray[counter] = new Class(read[i]);
				counter++;
			}
			else if (read[i] == ' ')
			{
				i--;
				continue;
			}
			else
			{
				continue;
			}
		}
	}
}

void School::Write()
{
	for (int i = 0; i < 4; i++)   // loop that display classes on the screen
	{
		cout << "Class: " << classArray[i]->className << "        ";
	}
}