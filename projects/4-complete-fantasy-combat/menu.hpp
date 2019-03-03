/********************************************************************* 
** Program name: Fantasy Combat Part 2 
** Description: Declaration of Menu Class   
*********************************************************************/

#ifndef MENU_H
#define MENU_H

#include "queue.hpp"
#include "DoublyLinkedList.hpp"
#include <string>

using std::string;

class Menu {

private:
    int rounds;
	Queue* team1;
	Queue* team2;
    DoublyLinkedList* losers;
    int t1Score;
    int t2Score;
	
public:
    Menu();
    ~Menu();

    void choosePlayers(int teamSize, int team);
    void makePlayer(int type, int team);
	void playGame();
	void startMenu();
    void makeTeams();
}; 


#endif