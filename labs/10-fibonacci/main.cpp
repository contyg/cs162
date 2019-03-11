/********************************************************************* 
** Program name: Fibonacci Lab  
** Author: Genevieve Conty
** Date: 03/17/2019
** Description: Compare recursion versus iteration algorithms 
                efficiency
*********************************************************************/

#include "fibonacci.hpp"
#include <time.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    clock_t rTime;
    clock_t iTime;

    cout << "Calculating the \033[1;35miterative\033[0m fibannocci..." << endl;
    iTime = clock();
    int i = iterativeFib(10);
    iTime = clock() - iTime;
    cout << "Result: " << i << endl;
    cout << "The iterative option took \033[0;35m" << iTime << "\033[0m seconds.\n" << endl;

    cout << "Calculating the \033[1;35mrecursive\033[0m fibannocci..." << endl;
    rTime = clock();
    int r = recursiveFib(10);
    rTime = clock() - rTime;
    cout << "Result: " << r << endl;
    cout << "The recursive option took \033[0;35m" << rTime << "\033[0m seconds.\n" << endl;

    

    return 0;
}