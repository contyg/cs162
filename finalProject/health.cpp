//TODO: description
#include "health.hpp"
#include <iostream>

using std::cout;
using std::endl;

Health::Health(int r, int c) : Space()
{
    type = "\033[1;35mHealth\033[0m";
    row = r;
    column = c;
    health = 0;
}

int Health::action()
{
    if (health == 0)
    {
        cout << "\n\033[0;35mYou get 2 strength points!\033[0m\n" << endl;
        health = 1;
        return 2;
    }
    cout << "\n\033[0;35mYou've already picked up health points from this square.\033[0m\n" << endl;
    return -1;
}

int Health::getHealth()
{
    return health;
}

void Health::setHealth(int h){}

void Health::updateHealth(int damage){}