//TODO: description
#ifndef WARRIOR_hpp
#define WARRIOR_hpp

#include "space.hpp"

class Warrior
{
private:
    int strength;
    int optionCount;
    Space* location;

public:
    Warrior();

    // getters
    int getOptionCount();
    int getStrength();
    Space* getLocation();

    //setters
    void setLocation(Space* space);

    // other functions
    void updateStrength(int factor);
    int attack(int choice);
    int defense(int damage);
    void move(int choice);
};

#endif