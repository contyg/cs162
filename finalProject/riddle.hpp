//TODO: description
#ifndef RIDDLE_HPP
#define RIDDLE_HPP

#include "space.hpp"

class Riddle : public Space
{
public:
    //constructor
    Riddle();

    virtual int healthPenalty();
};

#endif