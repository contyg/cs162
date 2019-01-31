/********************************************************************* 
** Program: Dice War
** Description: Declaration file for game class. Keeps score for 
**              players, rolls dice, prints stats and includes menu 
*********************************************************************/

#ifndef GAME_H
#define GAME_H

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
        ~Game();
        void setPlayersAndRolls();
        void play();
        void menu();
};
#endif