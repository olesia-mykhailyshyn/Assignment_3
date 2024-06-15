#include <iostream>
#include "caesaerStatic.h"

using namespace std;

int main() {
    while(true) {
        cout << "Choose command (cipher/exit):";
        string command;
        cin >> command;

        if (command == "exit") {
            cout << "Program was canselled" << endl;
            break;
        }
        else if (command == "cipher") {
            cout << "Please enter the key:";
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

    return 0;
}