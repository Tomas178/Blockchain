#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateRandomString(int length) {
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string randomString;
    for (int i = 0; i < length; ++i) {
        randomString += characters[rand() % characters.length()];
    }
    return randomString;
}

int main() {
    srand(time(nullptr));
    int lines = 100000;
    ofstream RF("6Uzduotis.txt");
    for (int i = 0; i < lines; i++) {
        int randomInt = rand() % 999 + 1;
        string tas_pats = generateRandomString(randomInt);
        RF << "a" + tas_pats << " " << "b" + tas_pats << "\n";
    }
}
