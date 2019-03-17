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
    int tests[] = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60}; // 13
    // int tests[] = {40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54}; // 15
    int j = 0;
    while (j < 13)
    {
        cout << "\033[0;36mN = " << tests[j] << "\033[0m\n" <<endl;
        clock_t rTime;
        clock_t iTime;

        cout << "Calculating the \033[1;35miterative\033[0m fibannocci..." << endl;
        iTime = clock();
        unsigned long long int i = iterativeFib(tests[j]);
        iTime = clock() - iTime;
        cout << "Result: " << i << endl;
        long iSec = (float)iTime / CLOCKS_PER_SEC;
        cout << "The iterative option took \033[0;35m" << iSec << "\033[0m seconds.\n" << endl;

        cout << "Calculating the \033[1;35mrecursive\033[0m fibannocci..." << endl;
        rTime = clock();
        unsigned long long int r = recursiveFib(tests[j]);
        rTime = clock() - rTime;
        long rSec = (float)rTime / CLOCKS_PER_SEC;
        cout << "Result: " << r << endl;
        cout << "The recursive option took \033[0;35m" << rSec << "\033[0m seconds.\n" << endl;
        cout << "\033[1;37m======================================\033[0m" << endl;
        j++;
    }
    
    return 0;
}