// Aiden Tsang
// CS216 Lab 8 - definitions of the helper functions that belong to main()

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

#include "Utilities.h"

using namespace std;

void clearFailedCin(const string &errorMessage) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\n" << errorMessage << endl;
}

int readInt(const string &prompt, int minVal, int maxVal) {
    int inputVal = 0;
    bool isValid = false;

    while (!isValid) {
        cout << prompt;
        cin >> inputVal;

        if (cin.fail()) {
            clearFailedCin("Invalid entry; please enter a whole number");
        }
        else if (inputVal < minVal || inputVal > maxVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPlease enter a whole number from " << minVal
                 << " to " << maxVal << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            isValid = true;
        }
    }

    return inputVal;
}

string readArmyName(const string &prompt) {
    string inputName = DEFAULT_NAME;
    bool isValid = false;

    while (!isValid) {
        cout << prompt;
        getline(cin, inputName);

        int letterCount = countAlphabetic(inputName);

        if (letterCount < MIN_ARMY_NAME_LETTERS
            || letterCount > MAX_ARMY_NAME_LETTERS) {
            cout << "\nAn army name needs from " << MIN_ARMY_NAME_LETTERS
                 << " to " << MAX_ARMY_NAME_LETTERS << " letters" << endl;
        }
        else {
            isValid = true;
        }
    }

    return inputName;
}

int countAlphabetic(const string &text) {
    int count = 0;
    int length = static_cast<int>(text.length());

    for (int i = 0; i < length; ++i) {
        if (isalpha(static_cast<unsigned char>(text[i]))) {
            ++count;
        }
    }

    return count;
}

string capitalizeFirst(const string &text) {
    string capitalized = text;

    if (capitalized.length() > 0) {
        capitalized[0] = static_cast<char>(
            toupper(static_cast<unsigned char>(capitalized[0])));
    }

    return capitalized;
}

int randomInRange(int minVal, int maxVal) {
    return (rand() % (maxVal - minVal + 1)) + minVal;
}

bool isChanceHit(int chancePercent) {
    return randomInRange(MIN_PERCENT_ROLL, PERCENT_ROLL) <= chancePercent;
}

void printDivider(int width) {
    cout << setfill(DIVIDER_CHAR) << setw(width) << "" << setfill(' ')
         << endl;
}