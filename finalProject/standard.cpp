//TODO: description
#include "standard.hpp"

Standard::Standard() : Space()
{
    type = "Standard";
}

int Standard::healthPenalty()
{
    return -1;
}