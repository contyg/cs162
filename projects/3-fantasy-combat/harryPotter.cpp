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
int HarryPotter::defense(int attackRoll)
{
    cout << "\033[0;35mHP DEFENSE\033[0m" << endl;

    int defense = armor;

    for (int i = 0; i < defenseDie; i++)
    {
        defense += rand()%defenseSides+1;
    }

    currentDamage = attackRoll - defense;
    strength -= currentDamage;

    return currentDamage;
}