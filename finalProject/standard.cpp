//TODO: description
#include "standard.hpp"

Standard::Standard(int r, int c) : Space()
{
    type = "Standard";
    row = r;
    column = c;
}

int Standard::action()
{
    return -1; 
}

int Standard::getHealth()
{
    return 0;
}

void Standard::setHealth(int damage){}