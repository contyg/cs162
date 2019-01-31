/********************************************************************* 
** Program: Dice War 
** Description: Definition file for LoadedDie class. Inherits most
**              behavior from die class. Has roll that is rigged 75%
**              of the time. 
*********************************************************************/

#include <iostream>
#include "loadedDie.hpp"

LoadedDie::LoadedDie(int n, int rounds) : Die(n, rounds){}

int LoadedDie::roll()
{
    int rigFactor = rand()%4;
    currentRoll = rand() % sides + 1; 

    // 75% chance of applying rigFactor
    if (rigFactor > 0) {
        currentRoll += 1;
    }

    if (currentRoll > sides) {
        currentRoll = sides;
    }

    return currentRoll;
}
