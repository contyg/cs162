/********************************************************************* 
** Program name: Fantasy Combat
** Description: Declaration of Character Class   
*********************************************************************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
using std::string;

class Character
{
protected:
    int attackDie;
    int attackSides;
    int defenseDie;
    int defenseSides;
    int armor;
    int strength;
    int currentRoll;
    int currentDamage;
    string type;
    string name;

public: 
    Character(int attackDie, int attackSides, int defenseDie, int defenseSides, int armor, int strength, string type);
    virtual void attack();
    virtual void defense(int attackRoll);

    int getArmor();
    int getStrength();
    int getCurrentRoll();
    int getCurrentDamage();
    string getType();
    string getName();

    void setStrength(int strength);
    void setCurrentRoll(int currentRoll);
    void setCurrentDamage(int currentDamage);
    void setName(string name);
};

#endif
