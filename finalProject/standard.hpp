/********************************************************************* 
** Program name: The Sphinxes and the Trifecta  
** Description: The definition of the Standard class. Contains the
**              standard space which does -1 damage on warrior stength.
*********************************************************************/
#ifndef STANDARD_HPP
#define STANDARD_HPP

#include "space.hpp"

class Standard : public Space
{
public:
    //constructor
    Standard(int r, int c);

    virtual int action();
    virtual int getHealth();
    virtual void setHealth(int h);
    virtual void updateHealth(int damage);
};

#endif