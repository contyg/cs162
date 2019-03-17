//TODO: description
#ifndef HEALTH_HPP
#define HEALTH_HPP

#include "space.hpp"

class Health : public Space
{
public:
    //constructor
    Health();

    virtual int healthPenalty();
};

#endif