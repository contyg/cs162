/********************************************************************* 
** Program: TODO: 
** Description: TODO:  
** Inputs: TODO: 
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