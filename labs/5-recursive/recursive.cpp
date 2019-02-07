/********************************************************************* 
** Program name: Recursive Lab  
** Description: Definition of recursive functions. 
*********************************************************************/
#include "recursive.hpp"
#include "menu.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void stringReverse(string str)
{
    cout << "\033[36mthe string: \033[0m" << str << endl;
}

void sumInt(int size, int* intArray)
{
    cout << "\033[32msum int size: \033[0m" << size << endl;
}

void triangularNum(int num)
{
     cout << "\033[33mtriangular Num: \033[0m" << num << endl;
}