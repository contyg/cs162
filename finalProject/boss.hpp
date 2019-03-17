//TODO: description
#ifndef BOSS_HPP
#define BOSS_HPP

#include "space.hpp"

class Boss : public Space
{
public:
    //constructor
    Boss();

    virtual int healthPenalty();
};

#endif