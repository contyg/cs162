//TODO: description
#include "riddle.hpp"
#include "validate.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Riddle::Riddle(int r, int c) : Space()
{
    type = "\033[1;34mRiddle\033[0m";
    row = r;
    column = c;
    health = 0;
}

int Riddle::action()
{
    int damage = -2; 
    
    if (health == 1)
    {
        cout << "You've solved this riddle already!" << endl;
    }
    else if (row == 0)
    {
        cout << "RIDDLE 0: words" << endl;
        cout << "RIDDLE 0: 2" << endl;
        int input = getIntegerBetween(0, 4);
        
        if (input == 2)
        {
            health = 1;
            damage = 0;
        }
    }
    else if (row == 1)
    {
        cout << "RIDDLE 1: words" << endl;
        cout << "RIDDLE 1: 3" << endl;
        
        int input = getIntegerBetween(0, 4);

        if (input == 3)
        {
            health = 1;
            damage = 0;
        }
    }
    else if (row == 2)
    {
        health = 1;
        cout << "RIDDLE 2: words" << endl;
        cout << "RIDDLE 2: 2" << endl;

        int input = getIntegerBetween(0, 4);

        if (input == 2)
        {
            health = 1;
            damage = 0;
        }
    } 

    return damage;
}

int Riddle::getHealth()
{
    return health;
}

void Riddle::setHealth(int h){}

void Riddle::updateHealth(int damage){}