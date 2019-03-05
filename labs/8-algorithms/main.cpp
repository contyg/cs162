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
    // make files into ifstreams
    ifstream normal("normal.txt");
    ifstream early("normal.txt");
    ifstream mid("middle.txt");
    ifstream end("end.txt");

    //make empty arrays for each file
    int normalArr[9];
    int earlyArr[10];
    int midArr[10];
    int endArr[10];

    // simple search
    cout << "\033[1;35mSIMPLE SEARCH: \033[0m" << endl;
    cout << "\n\033[0;32mnormal array: \033[0m";
    simpleSearch(normalArr);
    
    cout << "\n\033[0;32mearly array: \033[0m";
    simpleSearch(earlyArr);

    cout << "\n\033[0;32mmiddle array: \033[0m";
    simpleSearch(midArr);

    cout << "\n\033[0;32mend array: \033[0m";
    simpleSearch(endArr);

    // bubble sort
    cout << "\n\033[1;35mBUBBLE SORT: \033[0m" << endl;
    cout << "\n\033[0;32mnormal array \033[0m";
    bubbleSort(normalArr);
    
    cout << "\n\033[0;32mearly array \033[0m";
    bubbleSort(earlyArr);

    cout << "\n\033[0;32mmiddle array \033[0m";
    bubbleSort(midArr);

    cout << "\n\033[0;32mend array \033[0m";
    bubbleSort(endArr);

    // binary sort
    cout << "\n\033[1;35mBINARY SORT: \033[0m" << endl;
    cout << "\n\033[0;32mnormal array: \033[0m";
    binarySearchMenu(normalArr);
    
    cout << "\n\033[0;32mearly array: \033[0m";
    binarySearchMenu(earlyArr);

    cout << "\n\033[0;32mmiddle array: \033[0m";
    binarySearchMenu(midArr);

    cout << "\n\033[0;32mend array: \033[0m";
    binarySearchMenu(endArr);
    
    return 0;
}