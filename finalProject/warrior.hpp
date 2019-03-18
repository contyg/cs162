//TODO: description
#ifndef WARRIOR_hpp
#define WARRIOR_hpp

#include "space.hpp"
#include "backpack.hpp"

class Warrior
{
private:
    int strength;
    int optionCount;
    Space* location;
    Backpack* backpack;

public:
    Warrior();

    // getters
    int getOptionCount();
    int getStrength();
    Space* getLocation();
    Backpack* getBackpack();

    //setters
    void setLocation(Space* space);

    // other functions
    void updateStrength(int factor);
    int attack(int choice);
    int defense(int damage);
    void move(char choice);
};

#endif