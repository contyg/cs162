/********************************************************************* 
** Program: Dice War
** Description: Declaration for die class. Keeps track of number of 
**              sides and current roll value. Roll function gives 
**              random value. 
*********************************************************************/
#include <iostream>
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
