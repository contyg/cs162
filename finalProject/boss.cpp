/********************************************************************* 
** Program name: The Sphinxes and the Trifecta  
** Description: The definition of the Boss class. Represents the gargoyle
**              which will need to be defeated with the trifecta to win
**              the game
*********************************************************************/
#include "boss.hpp"
#include <iostream>

using std::cout;
using std::endl;

Boss::Boss(int r, int c) : Space()
{
    type = "\033[1;32mBoss\033[0m";
    row = r;
    column = c;
    health = 15;
}

int Boss::action()
{
    if (health >= 10)
    {
        return -8;
    }
    else if (health >= 5)
    {
        return -3;
    }
    return -1;
}

int Boss::getHealth()
{
    return health;
}

void Boss::setHealth(int h)
{
    health = h;
}

void Boss::updateHealth(int damage)
{
    health += damage;
}