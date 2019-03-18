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