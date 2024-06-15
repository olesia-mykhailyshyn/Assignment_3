#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    HINSTANCE handle = LoadLibrary(TEXT("C:\KSE\Programming_paradigms\Assignment_3\caesaer.dll"));

    if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
    {
        cout << "Lib not found" << endl;
        return -1;
    }

    typedef void(*function_ptr)(string, string, int);
    function_ptr encrypt = (function_ptr)GetProcAddress(handle, "encrypt");
    if (encrypt == nullptr)
    {
        cout << "Proc not found" << endl;
        return -1;
    }

    typedef void(*function_ptr)(string, string, int);
    function_ptr decrypt = (function_ptr)GetProcAddress(handle, "encrypt");
    if (decrypt == nullptr)
    {
        cout << "Proc not found" << endl;
        return -1;
    }

    FreeLibrary(handle);

    return 0;
}