//TODO: description
#ifndef BOSS_HPP
#define BOSS_HPP

#include "space.hpp"

class Boss : public Space
{
private:
    int health;

public:
    //constructor
    Boss(int r, int c);

    virtual int action();
    virtual int getHealth();
    virtual void setHealth(int damage);
};

#endif