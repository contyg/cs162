/********************************************************************* 
** Program Algorithms Lab 
** Description: Definition of search and sort functions
*********************************************************************/

#include "validate.hpp"
#include "searchAndSort.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void arrayFromFile(ifstream& file, int array[])
{
    int i = 0;
    // while values, populate array
    while (file >> array[0]) 
    {
        i++;
    }
}
void print(int array[])
{
    // determine array size
    int arraySize = *(&array + 1) - array;
    int i = 0;
    while (i < arraySize)
    {
        cout << array[i];
    }
    cout << endl;
}

void simpleSearch()
{
    // TODO: ask for target value
    // TODO: validate target

    // TODO: search for target in EACH file (4)
    // TODO: output whether value is found or not
}

void sort()
{
    //TODO: ask for user's output file
    //TODO: find and cite a sorting algorithm
    //TODO: output sorted values into file
    //TODO: print sorted values on the screen
}

void binarySearch()
{
    //TODO: find algorithm and implement
    //TODO: get and search for target
    // TODO: output whether value is found or not
}
