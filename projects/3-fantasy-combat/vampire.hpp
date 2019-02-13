//TODO: description

#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "character.hpp"

class Vampire: public Character 
{

public: 
	Vampire();

    void defense(int attackRoll);
};

#endif