#include "constants.h"
#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

void clearBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool isValidName(const char* name) {
    const int NAME_LENGTH = strlen(name);

    for (int i = 0; name[i] != '\0'; i++) {
        char c = name[i];
        if (!isalpha(c) && !isspace(c))  {
            cout << "Names should contain only letters and spaces" << endl;
            return false;
        }
    }

    if (NAME_LENGTH < NAME_MIN) {
        cout << "Name is too short make it atleast 2 letters" << endl;
        return false;
    }

    if (NAME_LENGTH > NAME_MAX) {
        return false;
    }


    return true;
}

bool isValidInt(int &result, int min, int max) {
    cin >> result;

    if (!cin) {
        cin.clear();
        clearBuffer();
        cout << "Invalid input. Please enter a number" << endl;
        return false;
    }

    if (result < min || result > max) {
        clearBuffer();
        cout << "Invalid number. Your number should be between " << min << " to " << max << endl;
        return false;
    }

    clearBuffer();
    return true;
}

void checkForSimpleNumber(int &result, string message) {
    while (!cin) {
        cout << "Invalid Input please enter a number" << endl;
        cin.clear();
        clearBuffer();
        cout << message;
        cin >> result;
    }
}
