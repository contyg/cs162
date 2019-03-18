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
    strength = 10;
    optionCount = 3;
    location = nullptr;
}

int Warrior::getOptionCount()
{
    return optionCount;
}

int Warrior::getStrength()
{
    return strength;
}

void Warrior::setLocation(Space* space)
{
    location = space;
}

void Warrior::updateStrength(int factor)
{
    strength += factor;

    if (strength < 4)
    {
        optionCount = 1;
    }
    else if (strength < 8)
    {
        optionCount = 2;
    }
}

int Warrior::attack(int choice)
{
    switch (choice)
    {
        case 3:
            cout << "THE TRIFECTA " << endl;
            return 6;
        case 2:
            cout << "Sword attack!" << endl;
            return 2; 
        default:
            cout << "RWAR the fists of furry!" << endl;
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

void move(int choice)
{

}