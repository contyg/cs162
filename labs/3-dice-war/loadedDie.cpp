/********************************************************************* 
** Program: TODO: 
** Description: TODO:  
** Inputs: TODO: 
*********************************************************************/

#include <iostream> //REMOVE:
using std::cout;    //REMOVE:
using std::cin;     //REMOVE:
using std::endl;    //REMOVE:

#include "loadedDie.hpp"

LoadedDie::LoadedDie()
{
    sides = 1;
    score = 0;
    currentRoll = 0;
}

void LoadedDie::roll()
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
}

int LoadedDie::getScore()
{  
    return score;
}

int LoadedDie::getLastRoll()
{
    return currentRoll;
}

void LoadedDie::addPoint()
{
    score++;
}

void LoadedDie::setSides(int n) 
{  
    sides = n;
}