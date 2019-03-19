//TODO: description
#include "boss.hpp"

Boss::Boss(int r, int c) : Space()
{
    type = "\033[0;32mBoss\033[0m";
    row = r;
    column = c;
    health = 15;
}

int Boss::action()
{
    if (health < 10)
    {
        return -3;
    }
    else if (health < 5)
    {
        return -1;
    }
    return -6;
}

int Boss::getHealth()
{
    return health;
}

void Boss::setHealth(int damage)
{
    health -= damage;
}