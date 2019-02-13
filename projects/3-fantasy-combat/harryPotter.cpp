//TODO: description
#include "harryPotter.hpp"
#include <iostream>

using std::cout;
using std::endl;

// int attackDie, int attackSides, int defenseDie, int defenseSides, 
// int armor, int strength, string type
HarryPotter::HarryPotter() : Character(2, 6, 2, 6, 0, 10, "Harry Potter") 
{
	lives = 2;
}

//TODO: 
void HarryPotter::defense(int attackRoll) 
{
    cout << "\033[0;35mHP DEFENSE\033[0m" << endl;

    currentRoll = 0;
    for (int i = 0; i < defenseDie; i++)
    {
        int roll = rand()%defenseSides+1;
        cout << "\033[0;32mDEFAULT DEFENSE\033[0m: " << roll << endl;

        currentRoll += roll;
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
}