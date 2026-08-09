// Aiden Tsang
// CS216 Lab 8 - declarations of the helper functions that belong to main()

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

using namespace std;

const string DEFAULT_NAME = "n/a";
const int MIN_PERCENT_ROLL = 1;
const int PERCENT_ROLL = 100;
const int MIN_ARMY_NAME_LETTERS = 3;
const int MAX_ARMY_NAME_LETTERS = 9;
const char DIVIDER_CHAR = '=';
const string NAME_RULE = " (" + to_string(MIN_ARMY_NAME_LETTERS) + " to "
                         + to_string(MAX_ARMY_NAME_LETTERS) + " letters): ";

void clearFailedCin(const string &errorMessage);
int readInt(const string &prompt, int minVal, int maxVal);
string readArmyName(const string &prompt);

int countAlphabetic(const string &text);
string capitalizeFirst(const string &text);
int randomInRange(int minVal, int maxVal);
bool isChanceHit(int chancePercent);
void printDivider(int width);

#endif
