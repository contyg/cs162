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
    rounds = 0;
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
    
        cout << "\033[0;36mPlayer "<< 1 <<": Which character do you want to be? \n" 
        << "    1: Barbarian \n"
        << "    2: BlueMen \n"
        << "    3: Harry Potter \n"
        << "    4: Medusa \n"
        << "    5: Vampire\033[0m" << endl;
        
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
        default:
            break;
    }
}

// TODO: 
void Menu::playGame()
{

    while(/*both players strength > 0*/)
    {
        rounds++;
        cout << "\033[0;32mRound: " << rounds << "\033[0m\n" << endl;

        // Stats
        cout << "\033[1;32mAttacker:\033[0m Player 1\n"
        << "    Type:"
        << "\033[1;32mDefender:\033 Player 2\n"
        << "    Type:"
        << "    Armor:"
        << "    Strength:" << endl;

        //Attack 1
        cout << "Attack Roll (Player 1): \n"
        << "Defense Roll (Player 2): \n"
        << "Total Damage: \n"
        << "Player 2 Remaining Strength: \n" << endl;

        // Stats
        cout << "\033[1;32mAttacker:\033[0m Player 2\n"
        << "    Type:"
        << "\033[1;32mDefender:\033 Player 1\n"
        << "    Type:"
        << "    Armor:"
        << "    Strength:" << endl;

        //Attack 2
        cout << "Attack Roll (Player 2): \n"
        << "Defense Roll (Player 1): \n"
        << "Total Damage: \n"
        << "Player 1 Remaining Strength: \n" << endl;
    }

    playAgain();
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