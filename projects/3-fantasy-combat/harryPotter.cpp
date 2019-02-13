//TODO: description
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
    
    if (damage < 0)
    {
        currentDamage = 0;
    }
    else 
    {
        currentDamage = damage;
    }
    
    strength -= currentDamage;

    if (strength < 1 && lives)
    {
        lives--;
        cout << "By the power of Hogwarts, Harry Potter lives again!" << endl;
    }
}