#ifndef MENU_H
#define MENU_H
#include <string>
using std::string;


void menu();
bool prompt(string str, int &input, int i, int optionalMax = 0);
void isAboveZero(int input, int min);
void isBelowMax(int input, int max);

#endif