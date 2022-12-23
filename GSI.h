#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
void OEM(DWORD oem);

void GSI() {
	LPSYSTEM_INFO sysInfo;

	sysInfo = new SYSTEM_INFO();
	GetNativeSystemInfo(sysInfo);

	OEM(sysInfo->wProcessorArchitecture);
	cout << "Page Size: " << sysInfo->dwPageSize << ";\n";
	cout << "Minimum memory allocation address (hexadecimal): " << sysInfo->lpMinimumApplicationAddress << ";\n";
	cout << "Maximum memory allocation address (hexadecimal): " << sysInfo->lpMaximumApplicationAddress << ";\n";
	cout << "Processor revision: " << sysInfo->wProcessorRevision << ";\n";
	cout << "Active processor mask: " << sysInfo->dwActiveProcessorMask << ";\n";
	cout << "Distribution granularity: " << sysInfo->dwAllocationGranularity << ";\n";
	cout << "Processor level: " << sysInfo->wProcessorLevel << ";\n";

	delete sysInfo;
}

void OEM(DWORD oem) {
	switch (oem) {
	case PROCESSOR_ARCHITECTURE_AMD64:
		cout << "\nAMD64 processor architecture;\n";
		break;
	case PROCESSOR_ARCHITECTURE_ARM:
		cout << "\nARM processor architecture;\n";
		break;
	case PROCESSOR_ARCHITECTURE_ARM64:
		cout << "\nARM64 processor architecture;\n";
		break;
	case PROCESSOR_ARCHITECTURE_IA64:
		cout << "\nIntel Itanium processor architecture;\n";
		break;
	case PROCESSOR_ARCHITECTURE_INTEL:
		cout << "\nx86 processor architecture;\n";
		break;
	case PROCESSOR_ARCHITECTURE_UNKNOWN:
		cout << "\nProcessor architecture unknown;\n";
		break;
	default:
		cout << "\nProcessor architecture UNEXPECTED VALUE;\n";
	}
}
