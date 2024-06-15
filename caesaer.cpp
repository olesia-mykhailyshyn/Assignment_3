#include <iostream>
#include <string>

using namespace std;

extern "C" {
__declspec(dllexport)
void encrypt (string text, int key) {

}

void decrypt (string text, int key) {
    
}
}