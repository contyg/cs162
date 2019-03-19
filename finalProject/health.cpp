//TODO: description
#include "health.hpp"

Health::Health(int r, int c) : Space()
{
    type = "\033[0;35mHealth\033[0m";
    row = r;
    column = c;
}

int Health::action()
{
    return 2;
}

int Health::getHealth()
{
    return 0;
}

void Health::setHealth(int damage){}