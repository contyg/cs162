/********************************************************************* 
** Program name: Fibonacci Lab
** Description: Definition of fibonacci functions 
*********************************************************************/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
unsigned long long int recursiveFib(int n)
{
    if(n == 0)
    {
        return 0;
    }	
   	else if(n == 1)
   	{
        return 1;
    }
   	return recursiveFib(n-1) + recursiveFib(n-2);
}

// source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
unsigned long long int iterativeFib(int n)
{
    unsigned long long int first = 0;
    unsigned long long int second = 1;
    int counter = 2;

    while(counter < n)
    {
        unsigned long long int temp = second;
        second = first+second;
        first = temp;
        ++counter;
    }
    
    if(n == 0)
    {
        return 0;
    }    
    else
    {
        return first+second;
    } 
}