//TODO: description
#include "menu.hpp"
#include "validate.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printMap(int userRow, int userColumn)
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

void printMap()
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

void intro()
{
    cout << "INTRODUCTION AND GOALS AND STUFF" << endl;
}

void mainMenu()
{
    // colorful menu with prompts for function choice
    cout << "\n\033[1;35mWhich function would you like to use?\033[0m"
    << "\n   \033[0;35m1\033[0m: Print the board"
    << "\n   \033[0;35m2\033[0m: Print with user at B2"
    << "\n   0: Exit the program" << endl;

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