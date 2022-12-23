#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::cin;

void MS()
{
	MEMORYSTATUSEX MemStatus;
	MemStatus.dwLength = sizeof(MemStatus);
	GlobalMemoryStatusEx(&MemStatus);
	cout << ("\n Memory status: \n \n");
	cout << "  Size of data structure in bytes: " << MemStatus.dwLength << "\n";
	cout << "  Loading Physical Memory: " << MemStatus.dwMemoryLoad << "\n";
	cout << "  Amount of actual physical memory in bytes: " << MemStatus.ullTotalPhys << "\n";
	cout << "  The amount of physical memory currently available in bytes: " << MemStatus.ullAvailPhys << "\n";
	cout << "  The current size of the allocated memory limit in bytes: " << MemStatus.ullTotalPageFile << "\n";
	cout << "  The maximum amount of memory that the current process can allocate, in bytes: " << MemStatus.ullAvailPageFile << "\n";
	cout << "  Size of the user mode portion of the virtual address space of the calling process in bytes: " << MemStatus.ullTotalVirtual << "\n";
}