//TODO: description

#include "character.hpp"
#include <iostream>
using std::cout;
using std::endl;

// constructor
Character::Character(int attackDie, int attackSides, int defenseDie, int defenseSides, int armor, int strength, string type) 
{
    this->attackDie = attackDie;
    this->attackSides = attackSides;
    this->defenseDie = defenseDie;
    this->defenseSides = defenseSides;

    this->armor = armor;
    this->strength = strength;
	this->type = type;
    this->currentRoll = 0;
    this->currentDamage = 0;
}

// default attack
int Character::attack()
{
    cout << "\033[0;31mDEFAULT ATTACK\033[0m" << endl;
    currentRoll = 0;

    for (int i = 0; i < attackDie; i++)
    {
        currentRoll += rand()%attackSides+1;
    }

    return currentRoll;
}

// default defense
int Character::defense(int attackRoll)
{
    cout << "\033[0;32mDEFAULT DEFENSE\033[0m" << endl;

    int defense = armor;

    for (int i = 0; i < defenseDie; i++)
    {
        defense += rand()%defenseSides+1;
    }

    currentDamage = attackRoll - defense;
    strength -= currentDamage;

    return currentDamage;
}

// getters
int Character::getArmor()
{
    return armor;
}

int Character::getStrength()
{
    return strength;
}

int Character::getCurrentRoll()
{
    return currentRoll;
}

int Character::getCurrentDamage()
{
    return currentDamage;
}

string Character::getType()
{
    return type;
}

// setters
void Character::setStrength(int strength)
{
    this->strength = strength;
}

void Character::setCurrentRoll(int currentRoll)
{
    this->currentRoll = currentRoll;
}

void Character::setCurrentDamage(int currentDamage)
{
    this->currentDamage = currentDamage;
}