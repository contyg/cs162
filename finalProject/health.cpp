//TODO: description
#include "health.hpp"

Health::Health() : Space()
{
    type = "\033[0;35Health\033[0m";
}

int Health::healthPenalty()
{
    return 2;
}