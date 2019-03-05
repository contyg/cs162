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

void arrayFromFile(string fileName, int array[], int size)
{
    ifstream inputFile;
    inputFile.open(fileName);

    int i = 0;
    // while values, populate array
    while (inputFile >> array[i]) 
    {
        i++;
    }

    inputFile.close();
}
void print(int array[], int size)
{
    // determine array size
    int i = 0;
    while (i < size)
    {
        cout << array[i];
        i++;
    }
    cout << endl;
}

void simpleSearch(int array[], int size)
{
    // ask for target value
    cout << "What value do you want to search for?" << endl;
    int target = getInteger();
    bool foundIt = false;

    // search for target in array
    int i = 0;
    
    while (i < size)
    {
        if(array[i] == target)
        {
            foundIt = true;
            i = size;
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
void bubbleSort(int array[], int size)
{
    //ask for user's output file
    string file;
    cout << "What file do you want to output too?" << endl;
    
    cin >> file;
    ofstream outputFile;
    outputFile.open(file);

    // sort
    int i = 0;
    while (i < size)
    {
        for(int j = 0; j < size-1; j++)
        {
            if (array[j] > array[j+1])
            {
                // swap
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
        i++;
    }

    //output sorted values into file
    int k = 0;
    while(k < size)
    {
        outputFile << array[k];
        k++;
    }

    outputFile.close();
    
    //print sorted values on the screen
    print(array, size);
}

void binaryMenu(int array[], int size)
{    
    // ask for target value
    cout << "What value do you want to search for?" << endl;
    int target = getInteger();

    bool foundIt = binarySearch(array, 0, size, target);

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

bool binarySearch(int array[], int left, int right, int target)
{
    if (right > left)
    {
        int middle = (right+left)/2;
        if (array[middle] == target)
        {
            return true;
        }
        else if (array[middle] > target)
        {
            return binarySearch(array, left, middle-1, target);
        }
        return binarySearch(array, left, middle+1, target);
    }

    return false;
}
