//TODO: description
#ifndef STANDARD_HPP
#define STANDARD_HPP

#include "space.hpp"

class Standard : public Space
{
public:
    //constructor
    Standard(int r, int c);

    virtual int healthPenalty();
};

#endif