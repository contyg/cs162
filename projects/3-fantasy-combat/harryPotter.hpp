//TODO: description
#ifndef HARRY_POTTER_H
#define HARRY_POTTER_H
#include "character.hpp"

class HarryPotter: public Character 
{

private: 
	int lives;

public: 
	HarryPotter();

    void defense(int attackRoll);
};

#endif