/********************************************************************* 
** Program name: Fantasy Combat Part 2 
** Description: Declaration of Vampire Class   
*********************************************************************/

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