/********************************************************************* 
** Program: TODO: 
** Description: TODO:  
** Inputs: TODO: 
*********************************************************************/

#ifndef LOADED_DIE_H
#define LOADED_DIE_H

class LoadedDie
{
    private:
        int sides;
        int score;
        int currentRoll;

    public:
        LoadedDie();
        void roll();
        int getScore();
        void setSides(int n);
        void addPoint();
        int getLastRoll();
};

#endif