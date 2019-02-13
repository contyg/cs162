//TODO: description

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

public: 
    Character(int attackDie, int attackSides, int defenseDie, int defenseSides, int armor, int strength, string type);
    virtual void attack();
    virtual void defense(int attackRoll);

    int getArmor();
    int getStrength();
    int getCurrentRoll();
    int getCurrentDamage();
    string getType();

    void setStrength(int strength);
    void setCurrentRoll(int currentRoll);
    void setCurrentDamage(int currentDamage);
};

#endif
