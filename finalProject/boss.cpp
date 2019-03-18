//TODO: description
#include "boss.hpp"

Boss::Boss(int r, int c) : Space()
{
    type = "\033[0;32Boss\033[0m";
    row = r;
    column = c;
}

int Boss::healthPenalty()
{
    return -3;
}