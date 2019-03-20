//TODO: description
#include "boss.hpp"

Boss::Boss(int r, int c) : Space()
{
    type = "\033[1;32mBoss\033[0m";
    row = r;
    column = c;
    health = 15;
}

int Boss::action()
{
    if (health > 9)
    {
        return -6;
    }
    else if (health > 4)
    {
        return -3;
    }
    return -1;
}

int Boss::getHealth()
{
    return health;
}

void Boss::setHealth(int h)
{
    health = h;
}

void Boss::updateHealth(int damage)
{
    health += damage;
}