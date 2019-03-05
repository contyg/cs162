/********************************************************************* 
** Program Algorithms Lab 
** Description: Declaration of search and sort functions
*********************************************************************/
#ifndef MENU_H
#define MENU_H
#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;

void arrayFromFile(string fileName, int array[], int size);
void print(int array[], int size);
void simpleSearch(int array[], int size);
void bubbleSort(int array[], int size);
void binaryMenu(int array[], int size);
bool binarySearch(int array[], int left, int right, int target);

#endif