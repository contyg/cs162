/********************************************************************* 
** Program: TODO: 
** Description: TODO:  
** Inputs: TODO: 
*********************************************************************/
#include <iostream> //REMOVE:
using std::cout;    //REMOVE:
using std::cin;     //REMOVE:
using std::endl;    //REMOVE:

#include <cmath> 
#include "die.hpp"

Die::Die(int n, int rounds)
{
    sides = n;
    currentRoll = 0;
}

int Die::roll()
{ 
    currentRoll = rand() % sides + 1;

    if (currentRoll > sides) {
        currentRoll = sides;
    }

    return currentRoll;
}

int Die::getCurrentRoll() 
{
    return currentRoll;
}

int Die::getSides()
{
    return sides;
}

void Die::setSides(int n) 
{  
    sides = n;
}
