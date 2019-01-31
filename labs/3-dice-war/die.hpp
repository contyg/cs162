/********************************************************************* 
** Program: Dice War
** Description: Declaration for die class. Keeps track of number of 
**              sides and current roll value. Roll function gives 
**              random value.  
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