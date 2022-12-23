#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::cin;
using std::endl;

void SM()
{
	void* Memory;
	cout << endl << "Enter address: ";
	cin >> Memory;
	MEMORYSTATUS MemStatus;
	MEMORY_BASIC_INFORMATION MemInfo;
	GlobalMemoryStatus(&MemStatus);
	VirtualQuery(Memory, &MemInfo, sizeof(MemStatus));
	cout << "  Information about pages in the virtual address space: " << "\n";
	cout << "  Pointer to the base address of the page region: " << MemInfo.BaseAddress << "\n";
	cout << "  Pointer to the base address of the range of pages allocated by the VirtualAlloc function: " << MemInfo.AllocationBase << "\n";
	cout << "  Memory protection option on initial region allocation: " << MemInfo.AllocationProtect << "\n";
	cout << "  Size of the area starting at the base address, in which all pages have the same attributes, in bytes: " << MemInfo.RegionSize << "\n";
	cout << "  Status of pages in the region. This element can be one of the following values: ";
	cout << endl << endl;
	switch (MemInfo.State) {
	case MEM_COMMIT:
		cout << "  Memory pages for which physical storage has been allocated" << endl;
		break;
	case MEM_FREE:
		cout << "  Pages of memory that are not available to the calling process and are available for allocation" << endl;
		break;
	case MEM_RESERVE:
		cout << "  Memory pages that reserve a range of the process's virtual address space without allocating physical memory" << endl;
		break;
	}
	cout << endl;
	cout << "  Protect access to pages in the region: " << MemInfo.Protect << endl;
	cout << "  The type of pages in the region. The following types are defined: ";
	switch (MemInfo.Type) {
	case MEM_IMAGE:
		cout << "    Memory pages in a region are displayed as a section of an image" << endl;
		break;
	case  MEM_MAPPED:
		cout << "    Memory pages within a region are shown in section view" << endl;
		break;
	case MEM_PRIVATE:
		cout << "   Memory pages within a region are private, i.e. not used by other processes" << endl;
		break;
	default:
		cout << MemInfo.Type << endl;
		break;
	}
}