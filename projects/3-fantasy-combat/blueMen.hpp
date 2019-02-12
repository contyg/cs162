//TODO: description
#ifndef BLUE_MEN_H
#define BLUE_MEN_H
#include "character.hpp"

class BlueMen: public Character 
{

public: 
	BlueMen();

    int defense(int attackRoll);
};

#endif