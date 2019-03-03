/********************************************************************* 
** Program name: Fantasy Combat Part 2
** Description: Definition of Character Class 
*********************************************************************/

#include "character.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// constructor
Character::Character(int attackDie, int attackSides, int defenseDie, int defenseSides, int armor, int strength, string type) 
{
    this->attackDie = attackDie;
    this->attackSides = attackSides;
    this->defenseDie = defenseDie;
    this->defenseSides = defenseSides;

    this->armor = armor;
    this->startStrength = strength;
    this->strength = strength; 
	this->type = type;
    this->currentRoll = 0;
    this->currentDamage = 0;

    setName();
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

void Character::restoreStrength()
{
    // restore 80% of damage
    int restoreVal = currentDamage * .8;
    strength += restoreVal;

    // make sure strength doesn't exceed starting strength
    if (strength > startStrength)
    {
        strength = startStrength;
    }
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

void Character::setName()
{
    string name;
    cout << "\033[0;36m Choose character name: \033[0m" << endl;
    getline(cin, name);
    this->name = name;
}