/********************************************************************* 
** Program: TODO: 
** Description: TODO:  
** Inputs: TODO: 
*********************************************************************/

#ifndef DIE_H
#define DIE_H

class Die
{
    private:
        int sides;
        int score;

    public:
        Die();
        void roll();
        int getScore();
};

#endif