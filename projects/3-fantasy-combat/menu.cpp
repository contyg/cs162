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

// TODO: 
void Menu::choosePlayer()
{

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
        default:
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