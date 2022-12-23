#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::cin;
using std::endl;
int Free();

void Return()
{
    SIZE_T Size;
    DWORD OldProtect = 0;
    DWORD NewProtect = 0;
    DWORD attribute = 0;
    int choise;
    bool flag;
    PVOID Memory;
    choise = Free();
    if (choise == 1)
    {
        cout << endl << "Enter address: ";
        cin >> Memory;
        flag = VirtualFree(Memory, 0, MEM_RELEASE);
    }
    else if (choise == 2)
    {
        cout << endl << "Enter the number of bytes to return:";
        cin >> Size;
        cout << endl << "Enter address: ";
        cin >> Memory;
        flag = VirtualFree(Memory, Size, MEM_DECOMMIT);
    }
    if (flag != 0) {
        cout << endl << "SUCCESS" << endl;
    }
    else {
        cout << endl << "ERROR" << endl;
    }
}

int Free() {
    int choise;
    cout << "1 - release a region of the address space" << endl;
    cout << "2 - returning physical memory" << endl;
    cout << endl << endl;
    cin >> choise;
    return choise;
}