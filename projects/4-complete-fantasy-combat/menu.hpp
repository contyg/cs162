/********************************************************************* 
** Program name: Fantasy Combat
** Description: Declaration of Menu Class   
*********************************************************************/

#ifndef MENU_H
#define MENU_H

#include "character.hpp"

class Menu {

private:
    int rounds;
	Character* p1;
	Character* p2;
	
public:
    Menu();
    ~Menu();

    void choosePlayers(int teamSize, int team);
    void makePlayer(int type, int team, string name);
	void playGame();
	void startMenu();
    void makeTeams();
}; 


#endif