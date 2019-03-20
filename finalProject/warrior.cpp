//TODO: description
#include "warrior.hpp"
#include "backpack.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

Warrior::Warrior()
{
    strength = 15;
    optionCount = 2;
    location = nullptr;
    backpack = new Backpack();
}

int Warrior::getOptionCount()
{
    return optionCount;
}

int Warrior::getStrength()
{
    return strength;
}

Space* Warrior::getLocation()
{
    return location;
}

Backpack* Warrior::getBackpack()
{
    return backpack;
}

void Warrior::setLocation(Space* space)
{
    location = space;
}

// update strength and weapon options based on strength
void Warrior::updateStrength(int factor)
{
    strength += factor;

    if (strength < 8)
    {
        optionCount = 1;
    }
    else
    {
        optionCount = 2;
    }
    
}

// execute attack actions w/ various damage
int Warrior::attack(int choice)
{
    int damage = 0;
    switch (choice)
    {
        case 0:
            cout << "\033[1;31mATTACK: \033[0m\033[0;31mENGAGE THE TRIFECTA \033[0m" << endl;
            backpack->setTrifectaUsed(false); // don't allow trifecta used more than once;
            damage = -6;
            break;
        case 2:
            cout << "\033[1;31mATTACK: \033[0m\033[0;31mSwift Sword of Swiftness!\033[0m" << endl;
            damage = -3; 
            break;
        default:
            cout << "\033[1;31mATTACK:\033[0m \033[0;31mFists of Furry!\033[0m" << endl;
            damage = -1;
            break;
    }
    return damage;
}

// apply shield 50% of the time
int Warrior::defense(int damage)
{
    int shieldUp = rand()%2;
    if (!shieldUp)
    {
        return damage;
    }

    cout << "\033[0;31mSHIELD UP!\033[0m" << endl;
    return 0;
}

// change warrior position
void Warrior::move(char choice)
{
    // move warrior
    switch(choice)
    {
        case 'U':
            setLocation(location->getUp());
            break;
        case 'D':
            setLocation(location->getDown());
            break;
        case 'L':
            setLocation(location->getLeft());
            break;
        case 'R':
            setLocation(location->getRight());
            break;

    }

    // playout any actions with new location
    if (location->getType() != "\033[1;32mBoss\033[0m")
    {
        int damageTaken = location->action();
        if (damageTaken == 0)
        {
            // add item to backpack when riddle solved
            int itemCount = backpack->getItemCount();
            switch (itemCount)
            {
                case 0:
                    backpack->addItem("TRI");
                    break;
                case 1:
                    backpack->addItem("FEC");
                    break;
                default:
                    backpack->addItem("TA!");
                    break;
            }
        }
        else 
        {
            // apply battle damage
            updateStrength(damageTaken);
        }
    }
}