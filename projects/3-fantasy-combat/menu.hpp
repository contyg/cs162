//TODO: description

#ifndef MENU_H
#define MENU_H

#include "character.hpp"

class Menu {

private:
    bool exitGame;
    int rounds;
	Character* p1;
	Character* p2;
	
public:
    Menu();
    ~Menu();

    void choosePlayer();
    void makePlayer(int input, Character *player);
	void playGame();
	void playAgain();
}; 


#endif