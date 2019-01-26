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
        int rounds;
        int inputs[7];
        int oneScore;
        int *oneTurns;
        int twoScore;
        int *twoTurns;


    public:
        Game();
        void setPlayersAndRolls();
        void play();
        void menu();
};
#endif