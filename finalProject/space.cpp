/********************************************************************* 
** Program name: The Sphinxes and the Trifecta  
** Description: The definition of the Space class. Contains the base
**              for all the space class: health, boss, standard, and
**              riddle. 
*********************************************************************/
#include "space.hpp"
#include <iostream>

Space::Space()
{
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
    type = "";
    row = 0;
    column = 0;
}

Space* Space::getUp()
{
    return up;
}

Space* Space::getDown()
{
    return down;
}

Space* Space::getLeft()
{
    return left;
}

Space* Space::getRight()
{
    return right;
}

string Space::getType()
{
    return type;
}

int Space::getRow()
{
    return row;
}

int Space::getColumn()
{
    return column;
}

void Space::setType(string t)
{
    type = t;
}

void Space::setLinkedSpaces(Space* U, Space* D, Space* L, Space* R)
{
    up = U;
    down = D;
    left = L;
    right = R;
}

// virtual functions to be defined in child space classes
Space::~Space(){};

int Space::action()
{
    return 0;
}

int Space::getHealth()
{
    return 0;
}

void Space::setHealth(int h){}

void Space::updateHealth(int damage){}