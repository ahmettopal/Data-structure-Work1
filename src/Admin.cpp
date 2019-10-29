#include "Admin.h"
#include "Class.h"
#include "School.h"
#include <iostream>

using namespace std;

School *_school;
Class *_class;
Admin::Admin()
{
	_school = new School();
	_class = new Class();

	_school->CreateClass();
	_class->CreateStudent();
}

void Admin::WriteScreen()
{
	for (int i = 0; i < 15; i++) // the loop that display the classes
	{
		if (_school->classArray[i] != NULL)
		{
			cout << "Class: " << _school->classArray[i]->className << "        ";
		}
	}
	cout << endl;
	for (int i = 0; i < 15; i++)  // the loop that display the students
	{
		for (int j = 0; j < 4; j++)
		{
			if (_class->studentArray[j] != NULL && _class->studentArray[j][i] != NULL)
			{
				cout << _class->studentArray[j][i]->studentName << "  " << "(" << _class->studentArray[j][i] << ")" << "   ";
			}
			else
			{
				cout << "-------------   ";
			}
		}
		cout << endl;
		if (_class->studentArray[i][0] == NULL)
		{
			break;
		}
	}
}

void Admin::ChangeClass()
{
	char one, two;
	cout << "Class Name " << endl;
	cin >> one;
	cout << "Class Name 2 " << endl;
	cin >> two;

	Class *tempClass;
	Student *tempStudent;

	int temp1 = 0, temp2 = 0;
	for (int i = 0; _school->classArray[i] != NULL; i++)
	{
		if (_school->classArray[i]->className == one)
		{
			temp1 = i;
		}
		if (_school->classArray[i]->className == two)
		{
			temp2 = i;
		}
	}

	tempClass = _school->classArray[temp1];  // changing number position of the selected class
	_school->classArray[temp1] = _school->classArray[temp2];
	_school->classArray[temp2] = tempClass;
	
	for (int i = 0; i < 15; i++)  // loop that changes position students inside of the classes
	{
		tempStudent = _class->studentArray[temp1][i];
		_class->studentArray[temp1][i] = _class->studentArray[temp2][i];
		_class->studentArray[temp2][i] = tempStudent;
	}
	cout << endl;
}

void Admin::ChangeStudent()
{
	char one, two;
	int temp, temp2, temp3, temp4;
	cout << "Student Name : " << endl;
	cin >> one;
	cout << "Student Name 2 : " << endl;
	cin >> two;

	Student *studen1;
	Student *studen2;
	Student *studen3;

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (_class->studentArray[j][i] != NULL && one == _class->studentArray[j][i]->studentName)
			{
				studen2 = _class->studentArray[j][i];
				temp = j;
				temp2 = i;

			}
			else if (_class->studentArray[j][i] != NULL && two == _class->studentArray[j][i]->studentName)
			{
				studen3 = _class->studentArray[j][i];
				temp3 = j;
				temp4 = i;
			}
		}
	}

	studen1 = _class->studentArray[temp][temp2];
	_class->studentArray[temp][temp2] = _class->studentArray[temp3][temp4];
	_class->studentArray[temp3][temp4] = studen1;
}