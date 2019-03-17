#ifndef MENU_H
#define MENU_H

#include "space.hpp"

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

public:
    Menu();
    ~Menu();

    // print maps
    void printMap(int userRow, int userColumn);
    void printMap();

    // menus
    void intro();
    void mainMenu();
};

#endif