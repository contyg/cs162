/********************************************************************* 
** Program: Dice War 
** Description: Declaration file for LoadedDie class. Inherits most
**              behavior from die class. Has roll that is rigged 75%
**              of the time. 
*********************************************************************/

#ifndef LOADED_DIE_H
#define LOADED_DIE_H
#include "die.hpp"

class LoadedDie: public Die
{
    public:
        LoadedDie(int n, int rounds);
        int roll();
};

#endif