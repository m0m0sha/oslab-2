#include <iostream>
#include <Windows.h>

#include "GSI.h" //get system info
#include "MS.h" //memory status
#include "SM.h" //memory state
#include "RR.h" //reserve region
#include "DM.h" //drive memory
#include "RD.h" //recording data
#include "AP.h" //access protection
#include "MR.h" //memory return

using namespace std;

void info(); //menu

int main()
{
	info();
	int ch = 10;
	while (ch != '9')
	{
		system("cls");
		info();
		cin >> ch;
		switch (ch)
		{
		case 1:
			GSI();
			break;
		case 2:
			MS();
			break;
		case 3:
			SM();
			break;
		case 4:
			RR();
			break;
		case 5:
			DM();
			break;
		case 6:
			RD();
			break;
		case 7:
			AP();
			break;
		case 8:
			Return();
			break;
		case 9:
			break;
		default:
			cout << "You entered an invalid value, please try again with a selection from the list" << endl;

			break;
		}
		system("pause");
	}
	return 0;
}

void info()
{
	cout << "Select the desired menu item: \n\n"
		<< "1 - obtaining information about the computer system \n"
		<< "2 - determining the status of virtual memory \n"
		<< "3 - determination of the state of a specific memory area at the address specified from the keyboard \n"
		<< "4 - reservation of the region in automatic mode and in the mode of entering the address of the beginning of the region \n"
		<< "5 - reservation of the region and transfer of physical memory to it in automatic mode and in the mode of entering the address of the beginning of the region \n"
		<< "6 - writing data to memory cells at addresses specified from the keyboard \n"
		<< "7 - setting access protection for a specified (from the keyboard) memory region and checking it \n"
		<< "8 - returning physical memory and freeing the address space region of the keyboard-specified memory region \n"
		<< endl;

}