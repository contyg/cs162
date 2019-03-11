/********************************************************************* 
** Program name: Fibonacci Lab
** Description: Definition of fibonacci functions 
*********************************************************************/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
int recursiveFib(int n)
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
int iterativeFib(int n)
{
    int first = 0;
    int second = 1;
    int counter = 2;
    
    if(n == 0)
    {
        return 0;
    }    
    else if (n == 1)
    {
        return first+second;
    } 

    while(counter < n)
    {
        int temp = second;
        second = first+second;
        first = temp;
        ++counter;
    }
    return second;
}