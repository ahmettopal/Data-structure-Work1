#include <iostream>
#include <String>
#include "Class.h"
#include "School.h"
#include "Admin.h"
using namespace std;

int main()
{
	Admin *admin = new Admin();
	admin->WriteScreen();

	int selection;
	do
	{
		cout << endl << "1.Change Class" << endl << "2.Change Student" << endl << "3.Exit" << endl << "=> ";
		cin >> selection;
		if (selection == 1)
		{
			admin->ChangeClass();
			admin->WriteScreen();
		}
		else if (selection == 2)
		{
			admin->ChangeStudent();
			admin->WriteScreen();
		}
		
	} while (selection != 3);

	system("pause");
}
