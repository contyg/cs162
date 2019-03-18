//TODO: description
#ifndef BOSS_HPP
#define BOSS_HPP

#include "space.hpp"

class Boss : public Space
{
public:
    //constructor
    Boss(int r, int c);

    virtual int action();
};

#endif