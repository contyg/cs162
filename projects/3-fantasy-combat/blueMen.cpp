//TODO: description
#include "blueMen.hpp"
#include <iostream>

using std::cout;
using std::endl;

// int attackDie, int attackSides, int defenseDie, int defenseSides, 
// int armor, int strength, string type
BlueMen::BlueMen(): Character(2, 10, 3, 6, 3, 12, "Blue Men") {}

//TODO:
int BlueMen::defense(int attackRoll)
{
    cout << "\033[0;36mHP DEFENSE\033[0m" << endl;

    int defense = armor;

    for (int i = 0; i < defenseDie; i++)
    {
        defense += rand()%defenseSides+1;
    }

    currentDamage = attackRoll - defense;
    strength -= currentDamage;

    return currentDamage;
}
