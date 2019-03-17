//TODO: description
#include "boss.hpp"

Boss::Boss() : Space()
{
    type = "\033[0;32Boss\033[0m";
}

int Boss::healthPenalty()
{
    return -3;
}