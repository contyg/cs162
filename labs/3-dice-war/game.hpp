/********************************************************************* 
** Program: TODO: 
** Description: TODO:  
** Inputs: TODO: 
*********************************************************************/

#ifndef GAME_H
#define GAME_H

// #include "validate.hpp"
#include "die.hpp"
#include "loadedDie.hpp"

class Game
{
    private:
        Die player1;
        LoadedDie cheater;
        int rounds;

    public:
        Game();
        void play();
        void menu();
};
#endif