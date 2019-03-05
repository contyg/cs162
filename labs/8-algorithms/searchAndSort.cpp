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

    file.close();
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

void simpleSearch(int array[])
{
    // ask for target value
    cout << "What value do you want to search for?" << endl;
    int target = getInteger();
    bool foundIt = false;

    // search for target in array
    int arraySize = *(&array + 1) - array;
    int i = 0;
    
    while (i < arraySize)
    {
        if(array[i] == target)
        {
            foundIt = true;
            i = arraySize;
        }

        i++;
    }

    // output whether value is found or not
    if (foundIt)
    {
        cout << "FOUND" << endl;
    }
    else
    {
        cout << "NOT found" << endl;
    }
    
}

// CITATION: https://www.geeksforgeeks.org/bubble-sort/
void bubbleSort(int array[])
{
    //ask for user's output file
    string file;
    cout << "What file do you want to output too?" << endl;
    
    cin >> file;
    ofstream outputFile(file);

    // sort
    int arraySize = *(&array + 1) - array;
    int i = 0;
    while (i < arraySize)
    {
        for(int j = 0; j < arraySize-i; j++)
        {
            if (array[j] > array[j+1])
            {
                // swap
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        i++;
    }

    //output sorted values into file
    int j = 0;
    while(j < arraySize)
    {
        outputFile << array[j];
    }
    
    //print sorted values on the screen
    print(array);
}

void binarySearch(int array[])
{
    //TODO: find algorithm and implement
    
    // ask for target value
    cout << "What value do you want to search for?" << endl;
    int target = getInteger();
    bool foundIt = false;
    //TODO: search for target

    // output whether value is found or not
    if (foundIt)
    {
        cout << "FOUND" << endl;
    }
    else
    {
        cout << "NOT found" << endl;
    }
}
