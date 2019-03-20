/********************************************************************* 
** Program name: The Sphinxes and the Trifecta  
** Description: The definition of the Menu class. Contains all the
**              menus for all actions in the game. Contains main game
**              loop
*********************************************************************/
#ifndef MENU_H
#define MENU_H

#include "space.hpp"
#include "warrior.hpp"
#include <string>

using std::string;

// MAP
// [ std1 ][ std2 ][ rid1 ]
// [ rid2 ][health][ std3 ]
// [ std4 ][ rid3 ][ boss ]

class Menu 
{
private:
    Space *std1, *std2, *std3, *std4;
    Space *rid1, *rid2, *rid3;
    Space *health, *boss;
    string attackOptions[4];
    Warrior *braveWarrior;
    bool keepPlaying;

public:
    Menu();
    ~Menu();

    // print maps
    void printMap(int userRow, int userColumn);
    void printMap();

    // menus
    void intro();
    int betweenMovesMenu();
    char moveWarriorMenu();
    int attackMenu();
    void battleMenu();

    void playGame();
};

#endif