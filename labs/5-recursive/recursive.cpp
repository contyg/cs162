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
    cout << str[str.length()-1];
    str.pop_back();
    if (str.length() > 0)
    {
        stringReverse(str);
    }
    else 
    {
        cout << "\n" << endl;  
    }
}

int sumInt(int size, int* intArray)
{
    if (size > 0) 
    {
        size--;
        return intArray[size] + sumInt(size, intArray);
    }   
    
    int sum = intArray[size];
    cout << "\033[32mSum: \033[0m" << sum << endl;
    return sum;
}

int triangularNum(int num)
{
    if (num > 0) 
    {
		return num + triangularNum(num - 1);
    }
    cout << "\033[33mTriangular Number: \033[0m" << num << endl;
    return num;
}