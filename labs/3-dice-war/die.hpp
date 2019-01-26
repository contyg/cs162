/********************************************************************* 
** Program: TODO: 
** Description: TODO:  
** Inputs: TODO: 
*********************************************************************/

#ifndef DIE_H
#define DIE_H

class Die
{
    protected:
        int sides;
        int score;
        int currentRoll;

    public:
        Die();
        void roll();
        int getScore();
        void setSides(int n);
        int getSides();
        void addPoint();
        int getLastRoll();
};

#endif