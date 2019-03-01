/********************************************************************* 
** Program name: Fantasy Combat
** Description: Declaration of Menu Class   
*********************************************************************/

#ifndef MENU_H
#define MENU_H

#include "queue.hpp"
#include <string>

using std::string;

class Menu {

private:
    int rounds;
	Queue* team1;
	Queue* team2;
    Queue* losers;
	
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