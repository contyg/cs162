//TODO: description
#include "standard.hpp"

Standard::Standard(int r, int c) : Space()
{
    type = "\033[1;37mStandard\033[0m";
    row = r;
    column = c;
    health = 0;
}

int Standard::action()
{
    return -1; 
}

int Standard::getHealth()
{
    return 0;
}

void Standard::setHealth(int h){}

void Standard::updateHealth(int damage){}