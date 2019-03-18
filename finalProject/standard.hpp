//TODO: description
#ifndef STANDARD_HPP
#define STANDARD_HPP

#include "space.hpp"

class Standard : public Space
{
public:
    //constructor
    Standard(int r, int c);

    virtual int action();
    virtual int getHealth();
    virtual void setHealth(int damage);
};

#endif