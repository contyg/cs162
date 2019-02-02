/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/

#include "validate.hpp"
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

// checks for chars and floats
bool isInteger(double testInput)
{
    if (cin.fail() || testInput-floor(testInput)) 
    {
        cout << "\033[1;31m ERROR: Please enter an integer value \033[0m\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

bool isBetween(int input, int min, int max)
{
    if (input > max)
    {
        cout << "\033[1;31m ERROR: Please enter an integer that is below or equal to "<< max <<" \033[0m\n";
        return false;
    }

    if (input < min)
    {
        cout << "\033[1;31m ERROR: Please enter an integer that is above or equal to "<< min <<" \033[0m\n";
        return false;
    }

    return true;
}