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

Die::Die()
{
    sides = 1;
    score = 0;
    currentRoll = 0;
}

void Die::roll()
{
    currentRoll = rand() % sides + 1;

    if (currentRoll > sides) {
        currentRoll = sides;
    }
}

int Die::getScore()
{
    return score;
}

int Die::getLastRoll() 
{
    return currentRoll;
}

void Die::addPoint()
{
    score++;
}

void Die::setSides(int n) 
{  
    sides = n;
}

int Die::getSides()
{
    return sides;
}