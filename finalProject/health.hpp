//TODO: description
#ifndef HEALTH_HPP
#define HEALTH_HPP

#include "space.hpp"

class Health : public Space
{
public:
    //constructor
    Health(int r, int c);

    virtual int healthPenalty();
};

#endif