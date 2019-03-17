//TODO: description
#include "menu.hpp"
#include "boss.hpp"
#include "health.hpp"
#include "riddle.hpp"
#include "standard.hpp"
#include "validate.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// ------ MAP ------------
// [ std1 ][ std2 ][ rid1 ]
// [ rid2 ][health][ std3 ]
// [ std4 ][ rid3 ][ boss ]

Menu::Menu()
{
    // make various spaces
    std1 = new Standard(); 
    std2 = new Standard(); 
    std3 = new Standard();
    std4 = new Standard();
    rid1 = new Riddle(); 
    rid2 = new Riddle(); 
    rid3 = new Riddle();
    health = new Health(); 
    boss = new Boss();

    // link the map spaces
    std1->setLinkedSpaces(nullptr, rid2, nullptr, std2);
    std2->setLinkedSpaces(nullptr, health, std1, rid1);
    std3->setLinkedSpaces(rid1, boss, health, nullptr);
    std4->setLinkedSpaces(rid2, nullptr, nullptr, rid3);

    rid1->setLinkedSpaces(nullptr, std3, std2, nullptr);
    rid2->setLinkedSpaces(std1, std4, nullptr, health);
    rid3->setLinkedSpaces(health, nullptr, std4, boss);

    health->setLinkedSpaces(std2, rid3, rid2, std3);
    boss->setLinkedSpaces(std3, nullptr, rid3, nullptr);
}

Menu::~Menu()
{
    delete std1;
    delete std2;
    delete std3;
    delete std4;

    delete rid1;
    delete rid2;
    delete rid3;

    delete health;
    delete boss;
}

void Menu::printMap(int userRow, int userColumn)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // riddle, purple
            if ((i == 1 && j == 0) || (i == 2 && j == 1) || (i == 0 && j == 2))
            {
                if (i == userRow && j == userColumn)
                {
                    cout << "\033[0;34m[\033[0m" << "X" << "\033[0;34m]\033[0m";
                }
                else
                {
                    cout << "\033[0;34m[ ]\033[0m";
                }
            }
            // health, pink
            else if (i == 1 && j == 1)
            {
                if (i == userRow && j == userColumn)
                {
                    cout << "\033[0;35m[\033[0m" << "X" << "\033[0;35m]\033[0m";
                }
                else
                {
                    cout << "\033[0;35m[ ]\033[0m";
                }
            }
            // boss, green
            else if (i == 2 && j == 2)
            {
                if (i == userRow && j == userColumn)
                {
                    cout << "\033[0;32m[\033[0m" << "X" << "\033[0;32m]\033[0m";
                }
                else
                {
                    cout << "\033[0;32m[ ]\033[0m";
                }
            }
            // standard spaces, white
            else
            {
                if (i == userRow && j == userColumn)
                {
                    cout << "\033[1;37m[\033[0m" << "X" << "\033[0;37m]\033[0m";
                }
                else
                {
                    cout << "\033[1;37m[ ]\033[0m";
                }
            }
        }
        cout << endl;
    }

    cout << "\n" << endl;
}

void Menu::printMap()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // riddle, purple
            if ((i == 1 && j == 0) || (i == 2 && j == 1) || (i == 0 && j == 2))
            {
                cout << "\033[1;34m[ ]\033[0m";
            }
            // health, pink
            else if (i == 1 && j == 1)
            {
                cout << "\033[1;35m[ ]\033[0m";
            }
            // boss, green
            else if (i == 2 && j == 2)
            {
                cout << "\033[1;32m[ ]\033[0m";
            }
            // standard spaces, cyan
            else
            {
                cout << "\033[1;37m[ ]\033[0m";
            }
        }
        cout << endl;
    }
    cout << "\n" << endl;
}

void Menu::intro()
{
    cout << "INTRODUCTION AND GOALS AND STUFF" << endl;
}

void Menu::mainMenu()
{
    // colorful menu with prompts for function choice
    cout << "\n\033[1;36mWhich function would you like to use?\033[0m"
    << "\n   \033[0;36m1\033[0m: Print the board"
    << "\n   \033[0;36m2\033[0m: Print with user at B2"
    << endl;

    int input = getIntegerBetween(0, 2);

    // trigger action according to user's choice
    switch (input)
    {
        case 1: 
            printMap();
            break;
        case 2:
            printMap(1, 1);
            break;
        default:
            cout << "\033[0;33mHave a nice day! :D\033[0m" << endl;
    }
}