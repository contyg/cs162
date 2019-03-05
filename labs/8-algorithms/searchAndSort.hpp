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

void arrayFromFile(ifstream& file, int array[]);
void print(int array[]);
void simpleSearch();
void sort();
void binarySearch();

#endif