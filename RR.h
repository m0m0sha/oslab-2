#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::cin;
using std::endl;

void RR()
{
	cout << "Select operating mode:" << endl;
	LPVOID Memory;
	int choise;
	cout << "1 - region reservation in automatic mode" << endl << "2 - manual region reservation" << endl;
	cin >> choise;
	switch (choise) {
	case 1:
		if (Memory = VirtualAlloc(NULL, 4096, MEM_RESERVE, PAGE_READWRITE))
			cout << "A memory area has been reserved at the base address " << Memory << endl;
		else cout << "ERROR" << GetLastError() << endl;
		break;
	case 2:
		cout << "Enter memory address " << endl;
		cin >> Memory;
		if (VirtualAlloc(Memory, 4096, MEM_RESERVE, PAGE_READWRITE))
			cout << "Memory at address " << Memory << " was successfully reserved." << endl;
		else
			cout << "ERROR" << GetLastError() << endl;
	}
}