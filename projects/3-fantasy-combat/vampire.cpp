//TODO: description

#include "vampire.hpp"
#include <iostream>

using std::cout;
using std::endl;

// int attackDie, int attackSides, int defenseDie, int defenseSides, 
// int armor, int strength, string type
Vampire::Vampire() : Character(1, 12, 1, 6, 1, 18, "Vampire") {}

//TODO: 
int Vampire::defense(int attackRoll)
{
    cout << "\033[0;32mVAMPIRE DEFENSE\033[0m" << endl; 
    int defense = armor;

    for (int i = 0; i < defenseDie; i++)
    {
        defense += rand()%defenseSides+1;
    }

    currentDamage = attackRoll - defense;
    strength -= currentDamage;

    return currentDamage;
}