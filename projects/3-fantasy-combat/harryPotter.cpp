/********************************************************************* 
** Program name: Fantasy Combat 
** Description: Definition of Harry Potter Class 
*********************************************************************/

#include "harryPotter.hpp"
#include <iostream>

using std::cout;
using std::endl;

// int attackDie, int attackSides, int defenseDie, int defenseSides, 
// int armor, int strength, string type
HarryPotter::HarryPotter() : Character(2, 6, 2, 6, 0, 10, "Harry Potter") 
{
	lives = 1;
}

void HarryPotter::defense(int attackRoll) 
{
    cout << "\033[0;35mHP DEFENSE\033[0m" << endl;

    currentRoll = 0;
    for (int i = 0; i < defenseDie; i++)
    {
        currentRoll += rand()%defenseSides+1;
    }

    int damage = attackRoll - armor - currentRoll;
    
    // prevent negative damage points
    if (damage < 0)
    {
        currentDamage = 0;
    }
    else 
    {
        currentDamage = damage;
    }
    
    // adjust strength
    strength -= currentDamage;

    // revive after 1st death
    if (strength < 1 && lives)
    {
        lives--;
        strength = 20;
        cout << "By the power of Hogwarts, Harry Potter lives again!" << endl;
    }
}