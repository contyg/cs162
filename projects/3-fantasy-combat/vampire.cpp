//TODO: description

#include "vampire.hpp"
#include <iostream>

using std::cout;
using std::endl;

// int attackDie, int attackSides, int defenseDie, int defenseSides, 
// int armor, int strength, string type
Vampire::Vampire() : Character(1, 12, 1, 6, 1, 18, "Vampire") {}

void Vampire::defense(int attackRoll)
{ 
    cout << "\033[0;35mVAMPIRE DEFENSE\033[0m" << endl;

    currentRoll = 0;
    for (int i = 0; i < defenseDie; i++)
    {
        currentRoll += rand()%defenseSides+1;
    }

    int damage = attackRoll - armor - currentRoll;
    
    // engage vampire charm
    int charmFactor = rand()%2;

    if (charmFactor)
    {
        cout << "\033[0;35mVampire charm defense!! Attack is void!!\033[0m" << endl;
    }

    // prevent negative damage points & implement charm defense
    if (damage < 0 || charmFactor)
    {
        currentDamage = 0;
    }
    else 
    {
        currentDamage = damage;
    }
    
    // adjust strength
    strength -= currentDamage;
}