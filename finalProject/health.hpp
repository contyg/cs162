/********************************************************************* 
** Program name: The Sphinxes and the Trifecta  
** Description: The declaration of the Health class. Gives the user 
**              extra health points the first time it is occupied.
*********************************************************************/
#ifndef HEALTH_HPP
#define HEALTH_HPP

#include "space.hpp"

class Health : public Space
{
public:
    //constructor
    Health(int r, int c);

    virtual int action();
    virtual int getHealth();
    virtual void setHealth(int h);
    virtual void updateHealth(int damage);
};

#endif