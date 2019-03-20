/********************************************************************* 
** Program name: The Sphinxes and the Trifecta  
** Description: The declaration of the Standard class. Contains the
**              standard space which does -1 damage on warrior stength.
*********************************************************************/
#include "standard.hpp"
#include <iostream>

using std::cout;
using std::endl;

Standard::Standard(int r, int c) : Space()
{
    type = "\033[1;37mStandard\033[0m";
    row = r;
    column = c;
    health = 0;
}

int Standard::action()
{
    cout << "\n\033[0;37mKeep track of your feet, your strength depletes with each step\033[0m\n" << endl;

    return -1; 
}

int Standard::getHealth()
{
    return 0;
}

void Standard::setHealth(int h){}

void Standard::updateHealth(int damage){}