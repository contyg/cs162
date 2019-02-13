//TODO: description

#include <iostream>
#include "menu.hpp"
#include "validate.hpp"

#include "barbarian.hpp"
#include "blueMen.hpp"
#include "harryPotter.hpp"
#include "medusa.hpp"
#include "vampire.hpp"

using std::cout;
using std::cin;
using std::endl;

Menu::Menu()
{
    exitGame = false;
    rounds = 1;
    p1 = nullptr;
    p2 = nullptr;
}

Menu::~Menu()
{
    delete p1;
    p1 = nullptr;

    delete p2;
    p2 = nullptr;
}

void Menu::choosePlayer()
{
    int i = 1;
    while (i < 3)
    {
        double testInput;
    
        cout << "Player "<< 1 <<": Which character do you want to be? \n" 
        << "    1: Barbarian \n"
        << "    2: BlueMen \n"
        << "    3: Harry Potter \n"
        << "    4: Medusa \n"
        << "    5: Vampire" << endl;
        
        cin >> testInput;

        if(!isInteger(testInput))
        {
            choosePlayer();
        }

        int input = (int)testInput;

        if (!isBetween(input, 1, 5)) 
        {
            choosePlayer();
        }
        
        if(i == 1)
        {
            makePlayer(i, p1);
        }
        else
        {
            makePlayer(i, p2);
        }

        i++;
    }   
}

void Menu::makePlayer(int input, Character *player)
{
    switch(input)
    {
        case 1: // barbarian
            player = new Barbarian;
            break;
        case 2: // blue men
            player = new BlueMen;
            break;
        case 3: // harry potter
            player = new HarryPotter;
            break;
        case 4: // medusa
            player = new Medusa;
            break;
        case 5: // vampire
            player = new Vampire;
            break;
        default: //TODO: move to choosePlayer, inBetween check
            cout << "\033[1;31mERROR: Please choose a valid player.\033[0m" << endl;
            choosePlayer();
            break;
    }
}

// TODO: 
void Menu::displayStats()
{

}
// TODO: 
void Menu::playGame()
{

    //playAgain();
}

void Menu::playAgain()
{
    double testInput;
    
    cout << "\033[0;36mDo you want to play again?\033[0m" 
    << "\n  1: Yes, 0: No" << endl;
    
    cin >> testInput;

    if(!isInteger(testInput))
    {
        playAgain();
    }

    int input = (int)testInput;

    if(input)
    {
        playGame();
    }
    
    exit(0);
}