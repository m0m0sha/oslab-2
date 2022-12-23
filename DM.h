#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::cin;
using std::endl;

void DM()
{
	cout << "Select operating mode:" << endl;
	LPVOID Memory;
	int choise;
	cout << "1 - region reservation in automatic mode" << endl << "2 - manual region reservation" << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
		if (Memory = VirtualAlloc(NULL, 4096, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE))
			cout << "A memory area has been reserved at the base address " << Memory << endl;
		else if (GetLastError() == 487)
		{
			if (VirtualAlloc(Memory, 4096, MEM_COMMIT, PAGE_READWRITE))
				cout << "Memory at address " << Memory << " was successfully reserved." << endl;
			else
				cout << "ERROR " << GetLastError() << "\n" << endl;
		}
		break;
	case 2:
		cout << "Enter memory address " << endl;
		cin >> Memory;
		if (VirtualAlloc(Memory, 4096, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE))
			cout << "Memory at address " << Memory << " was successfully reserved." << endl;
		else if (GetLastError() == 487)
		{
			if (VirtualAlloc(Memory, 4096, MEM_COMMIT, PAGE_READWRITE))
				cout << "Memory at address " << Memory << " was successfully reserved." << endl;
			else
				cout << "ERROR" << GetLastError() << "\n" << endl;
		}
		break;
	}
}