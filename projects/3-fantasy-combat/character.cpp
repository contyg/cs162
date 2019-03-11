/********************************************************************* 
** Program name: Fantasy Combat 
** Description: Definition of Character Class 
*********************************************************************/


#include "character.hpp"
#include <iostream>
using std::cout;
using std::endl;

// constructor
Character::Character(int attackDie, int attackSides, int defenseDie, int defenseSides, int armor, int strength, string type) 
{
    // set up all the dice
    this->attackDie = attackDie;
    this->attackSides = attackSides;
    this->defenseDie = defenseDie;
    this->defenseSides = defenseSides;

    // set up starting stats
    this->armor = armor;
    this->strength = strength;
	this->type = type;
    this->currentRoll = 0;
    this->currentDamage = 0;
}

// default attack
void Character::attack()
{
    currentRoll = 0;

    for (int i = 0; i < attackDie; i++)
    {
        currentRoll += rand()%attackSides+1;
    }
}

// default defense
void Character::defense(int attackRoll)
{
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