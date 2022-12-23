#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::wcin;
using std::endl;

void AP()
{
	MEMORY_BASIC_INFORMATION memInfo;
	PVOID Memory = nullptr;
	DWORD newProtection, oldProtection;
	cout << "Enter an address belonging to the region where you want to change the protection: "; //specify region
	wcin >> std::hex >> Memory >> std::dec;
	wcin.ignore(INT_MAX, '\n');
	if (Memory == nullptr) {
		cout << "Failed to parse address.\n";
		return;
	}
	VirtualQuery(Memory, &memInfo, sizeof(memInfo)); //geting information about region
	if (GetLastError() != 0) { //checking for errors
		cout << "ERROR. " << GetLastError() << ".\n";
		SetLastError(0);
		return;
	}
	cout << "You will change the region protection starting from " << memInfo.BaseAddress << ", with size " << memInfo.RegionSize << " byte." << "\nEnter a new flag security word (hexadecimal)" << endl; //changing protection
	wcin >> std::hex >> newProtection >> std::dec;
	wcin.ignore(INT_MAX, '\n');
	if (VirtualProtect(memInfo.BaseAddress, memInfo.RegionSize, newProtection, &oldProtection))
		cout << "Protection changed successfully.\n"
		<< "Old protection word:" << oldProtection << ".\n";
	else {
		cout << "Failed to change protection." << " ERROR " << GetLastError() << ".\n" << "Possible reasons: no memory was allocated or an invalid protection word.\n";
		SetLastError(0);
	}
}