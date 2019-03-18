//TODO: description
#ifndef RIDDLE_HPP
#define RIDDLE_HPP

#include "space.hpp"

class Riddle : public Space
{
public:
    //constructor
    Riddle(int r, int c);

    virtual int action();
    virtual int getHealth();
    virtual void setHealth(int damage);
};

#endif