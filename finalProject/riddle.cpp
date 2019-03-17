//TODO: description
#include "riddle.hpp"

Riddle::Riddle() : Space()
{
    type = "\033[0;34Riddle\033[0m";
}

int Riddle::healthPenalty()
{
    return -2;
}