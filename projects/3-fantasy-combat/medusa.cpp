/********************************************************************* 
** Program name: Fantasy Combat 
** Description: Definition of Medusa Class 
*********************************************************************/
#include "medusa.hpp"
#include <iostream>

using std::cout;
using std::endl;

// int attackDie, int attackSides, int defenseDie, int defenseSides, 
// int armor, int strength, string type
Medusa::Medusa() : Character(2, 6, 1, 6, 3, 8, "Medusa") {}

void Medusa::attack()
{
    cout << "\033[0;33mMEDUSA ATTACK\033[0m" << endl; 
    currentRoll = 0;

    for (int i = 0; i < attackDie; i++)
    {
        currentRoll += rand()%attackSides+1;
    }

    if(currentRoll == 12)
    {
        cout << "\033[0;33mBeware Medusa's glare.\033[0m" << endl; 
        currentRoll = 21;
    }
}
