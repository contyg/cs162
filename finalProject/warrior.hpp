/********************************************************************* 
** Program name: The Sphinxes and the Trifecta  
** Description: The declaration of the Warrior class. Contains the
**              attack, move and defense functions for the warrior
*********************************************************************/
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