//TODO: description
#include "riddle.hpp"

Riddle::Riddle(int r, int c) : Space()
{
    type = "\033[0;34Riddle\033[0m";
    row = r;
    column = c;
}

int Riddle::healthPenalty()
{
    return -2;
}