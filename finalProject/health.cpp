//TODO: description
#include "health.hpp"

Health::Health(int r, int c) : Space()
{
    type = "\033[0;35Health\033[0m";
    row = r;
    column = c;
}

int Health::healthPenalty()
{
    return 2;
}