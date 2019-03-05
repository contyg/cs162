/********************************************************************* 
** Program Algorithms Lab 
** Author: Genevieve Conty
** Date: 03/04/2019
** Description: Search and sort lab 
*********************************************************************/

#include "validate.hpp"
#include "searchAndSort.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    //make empty arrays for each file
    int normalArr[9];
    int earlyArr[10];
    int midArr[10];
    int endArr[10];
    
    // put files into arrays
    arrayFromFile("original.txt", normalArr, 9);
    arrayFromFile("early.txt", earlyArr, 10);
    arrayFromFile("middle.txt", midArr, 10);
    arrayFromFile("end.txt", endArr, 10);

    // simple search
    // cout << "\033[1;35mSIMPLE SEARCH: \033[0m" << endl;
    // cout << "\n\033[0;32mnormal array: \033[0m";
    // simpleSearch(normalArr, 9);
    
    // cout << "\n\033[0;32mearly array: \033[0m";
    // simpleSearch(earlyArr, 10);

    // cout << "\n\033[0;32mmiddle array: \033[0m";
    // simpleSearch(midArr, 10);

    // cout << "\n\033[0;32mend array: \033[0m";
    // simpleSearch(endArr, 10);

    // bubble sort
    cout << "\n\033[1;35mBUBBLE SORT: \033[0m" << endl;
    cout << "\n\033[0;32mnormal array \033[0m";
    bubbleSort(normalArr, 9);
    
    cout << "\n\033[0;32mearly array \033[0m";
    bubbleSort(earlyArr, 10);

    cout << "\n\033[0;32mmiddle array \033[0m";
    bubbleSort(midArr, 10);

    cout << "\n\033[0;32mend array \033[0m";
    bubbleSort(endArr, 10);

    //binary sort
    // cout << "\n\033[1;35mBINARY SORT: \033[0m" << endl;
    // cout << "\n\033[0;32mnormal array: \033[0m";
    // binaryMenu(normalArr);
    
    // cout << "\n\033[0;32mearly array: \033[0m";
    // binaryMenu(earlyArr);

    // cout << "\n\033[0;32mmiddle array: \033[0m";
    // binaryMenu(midArr);

    // cout << "\n\033[0;32mend array: \033[0m";
    // binaryMenu(endArr);
    
    return 0;
}