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
        int currentRoll;

    public:
        Die(int n, int rounds);
        int roll();
        int getSides();
        int getCurrentRoll();
        void setSides(int n);
};

#endif