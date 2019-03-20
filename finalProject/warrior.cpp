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

int Warrior::attack(int choice)
{
    switch (choice)
    {
        case 0:
            cout << "\nENGAGE THE TRIFECTA " << endl;
            backpack->setTrifectaUsed(false);
            return 6;
        case 2:
            cout << "Sword attack!" << endl;
            return 3; 
        default:
            cout << "Fists of Furry!" << endl;
            return 1;
    }
}

int Warrior::defense(int damage)
{
    int shieldUp = rand()%2;
    if (shieldUp)
    {
        cout << "Shield up!" << endl;
        return 0;
    }

    return damage;
}

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
    if (location->getType() != "\033[0;32Boss\033[0m")
    {
        int damageTaken = location->action();
        if (damageTaken == 0)
        {
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
            updateStrength(damageTaken);
        }
    }
}