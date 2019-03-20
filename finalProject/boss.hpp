/********************************************************************* 
** Program name: The Sphinxes and the Trifecta  
** Description: The declaration of the Boss class. Represents the gargoyle
**              which will need to be defeated with the trifecta to win
**              the game
*********************************************************************/
#ifndef BOSS_HPP
#define BOSS_HPP

#include "space.hpp"

class Boss : public Space
{

public:
    //constructor
    Boss(int r, int c);

    virtual int action();
    virtual int getHealth();
    virtual void setHealth(int h);
    virtual void updateHealth(int damage);
};

#endif