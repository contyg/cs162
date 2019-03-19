//TODO: description
#include "health.hpp"
#include <iostream>

using std::cout;
using std::endl;

Health::Health(int r, int c) : Space()
{
    type = "\033[0;35mHealth\033[0m";
    row = r;
    column = c;
    health = 0;
}

int Health::action()
{
    if (health == 0)
    {
        cout << "\033[0;35mYou get 2 strength points!\033[0m" << endl;
        health = 1;
        return 2;
    }
    cout << "\033[0;35mYou've already picked up health points from this square.\033[0m" << endl;
    return 0;
}

int Health::getHealth()
{
    return health;
}

void Health::setHealth(int h){}

void Health::updateHealth(int damage){}