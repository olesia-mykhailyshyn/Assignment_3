#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    HINSTANCE handle = LoadLibrary(TEXT("C:\\KSE\\Programming_paradigms\\Assignment_3\\caesaer.dll"));

    if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
    {
        cout << "Lib not found" << endl;
        return -1;
    }

    typedef string(*encrypt_ptr)(string, int);
    auto encrypt = (encrypt_ptr)GetProcAddress(handle, "encrypt"); //encrypt_ptr -> auto = to avoid duplicating the type name
    if (encrypt == nullptr)
    {
        cout << "Proc not found" << endl;
        return -1;
    }

    typedef string(*decrypt_ptr)(string, int);
    auto decrypt = (decrypt_ptr)GetProcAddress(handle, "decrypt");
    if (decrypt == nullptr)
    {
        cout << "Proc not found" << endl;
        return -1;
    }

    while(true) {
        cout << "Choose command (cipher/exit):";
        string command;
        cin >> command;

        if (command == "exit") {
            cout << "Program was canselled" << endl;
            break;
        }
        else if (command == "cipher") {
            cout << "Please enter the integer key:";
            int key;
            cin >> key;

            string text = "";
            cout << "Please enter the text:" << endl;
            cin >> text;
            string cipher = "";

            cout << endl;

            cipher = encrypt(text, key);
            cout << "ENCRYPTING" << endl;
            cout << "Plain text:" << endl;
            cout << text << endl;
            cout << "Cipher text:" << endl;
            cout << cipher << endl << endl;

            text = decrypt(cipher, key);
            cout << "DECRYPTING" << endl;
            cout << "Cipher text:" << endl;
            cout << cipher << endl;
            cout << "Plain text:" << endl;
            cout << text << endl << endl;
        }
        else {
            cout << "Invalid command" << endl;
        }
    }

    FreeLibrary(handle);

    return 0;
}