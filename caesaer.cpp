#include <string>
#include <cctype> //for upper and lower case

using namespace std;

extern "C" {
__declspec(dllexport) string encrypt(string text, int key);
__declspec(dllexport) string decrypt(string text, int key);

    string encrypt (string text, int key) {
        string cipher = "";

        for (unsigned i=0; i < text.length(); i++ ) {
            char c = text[i];

            if (isupper(c)) {
                //apply Ceaser Cipher formula
                int x = c - 'A' + key;
                //handle boundary condition
                x = x % 26;
                //convert to char
                c = (char)(x + 'A');
            }
            else if (islower(c)) {
                int x = c - 'a' + key;
                x = x % 26;
                c = (char)(x + 'a');
            }
            cipher.insert(cipher.end(), 1, c); //insert in the end
        }

        return cipher;
    }

    string decrypt (string text, int key) {
        string plain = "";

        for (unsigned i=0; i < text.length(); i++ ) {
            char c = text[i];

            if (isupper(c)) {
                int x = c - 'A' - key;
                if (x < 0) {
                    x += 26;
                }
                c = (char)(x + 'A');
            }
            else if (islower(c)) {
                int x = c - 'a' - key;
                if (x < 0) {
                    x += 26;
                }
                c = (char)(x + 'a');
            }
            plain.insert(plain.end(), 1, c);
        }

        return plain;
    }
}