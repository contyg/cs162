/********************************************************************* 
** Program name: The Sphinxes and the Trifecta  
** Description: The declaration of the riddle class. Contains all the
**              riddles and distributes trifecta pieces. 
*********************************************************************/
#ifndef RIDDLE_HPP
#define RIDDLE_HPP

#include "space.hpp"

class Riddle : public Space
{
public:
    //constructor
    Riddle(int r, int c);

    virtual int action();
    virtual int getHealth();
    virtual void setHealth(int h);
    virtual void updateHealth(int damage);
};

#endif