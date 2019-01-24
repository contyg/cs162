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

    public:
        LoadedDie();
        void roll();
        int getScore();
};

#endif