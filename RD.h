#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::wcin;

void RD()
{
	MEMORY_BASIC_INFORMATION memInfo;
	LPVOID Memory = nullptr;
	cout << "Enter the address belonging to the region you want to go to (hexadecimal): "; //specify region
	wcin >> std::hex >> Memory >> std::dec;
	wcin.ignore(INT_MAX, '\n');
	if (Memory == nullptr) {
		cout << "Failed to parse address.\n";
		return;
	}
	VirtualQuery(Memory, &memInfo, sizeof(memInfo)); //getting information about region
	if (GetLastError() != 0) { //checking for errors at getting information
		cout << "ERROR!" << GetLastError() << ".\n";
		SetLastError(0);
		return;
	}
	if (memInfo.State != MEM_COMMIT) { //checking if memory is accessable
		cout << "ERROR: Memory not allocated.\n";
		return;
	}
	SIZE_T maxSize = memInfo.RegionSize - ((SIZE_T)Memory - (SIZE_T)memInfo.BaseAddress); //define max size and desired size of written data
	SIZE_T desiredSize = 0;
	cout << "You can write to this region. " << maxSize << " byte.\n" << "How many bytes do you need to write? ";
	wcin >> desiredSize;
	wcin.ignore(INT_MAX, '\n');
	if (desiredSize == 0 || desiredSize > maxSize) { //checking if input was incorrect
		cout << "You can't write that much data: " << desiredSize << " byte. Operation aborted.\n";
		return;
	}
	unsigned numericView; //writing data
	byte* data = (byte*)Memory;
	cout << "Type " << desiredSize << " bytes (0 to 255), one by one: ";
	for (SIZE_T i = 0; i < desiredSize; ++i) {
		std::cin >> numericView;
		*(data++) = numericView;
	}
	cout << "\nYou entered "; //showing typed info
	for (SIZE_T i = 0; i < desiredSize; ++i) {
		numericView = *((byte*)Memory + i);
		cout << numericView << " ";
	}
}