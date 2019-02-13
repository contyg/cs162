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
            makePlayer(input, 1);
        }
        else
        {
            makePlayer(input, 2);
        }

        i++;
    } 
    
    playGame();  
}

void Menu::makePlayer(int input, int playerNum)
{
    cout << "make player " << input << endl;
    switch(input)
    {
        case 1: // barbarian
            if(playerNum == 1)
            {
                p1 = new Barbarian;
                break;
            }
            
            p2 = new Barbarian;
            break;

        case 2: // blue men
            if(playerNum == 1)
            {
                p1 = new BlueMen;
                break;
            }
            
            p2 = new BlueMen;
            break;

        case 3: // harry potter
            if(playerNum == 1)
            {
                p1 = new HarryPotter;
                break;
            }
            p2 = new HarryPotter;
            break;

        case 4: // medusa
            if(playerNum == 1)
            {
                p1 = new Medusa;
                break;
            }
            p2 = new Medusa;
            break;

        case 5: // vampire
            if(playerNum == 1)
            {
                p1 = new Vampire;
                break;
            }
            p2 = new Vampire;
            break;

        default:
            break;
    }
}

void Menu::playGame()
{
    int attackRoll;
    while(p1->getStrength() > 0 && p2->getStrength() > 0)
    {
        rounds++;
        cout << "\033[0;32mRound: " << rounds << "\033[0m\n" << endl;

        // Stats
        cout << "\033[1;32mAttacker:\033[0m Player 1\n"
        << "    Type: " << p1->getType() << "\n"
        << "\033[1;32mDefender: \033[0m Player 2\n"
        << "    Type: " << p2->getType() << "\n"
        << "    Armor: " << p2->getArmor() << "\n"
        << "    Strength: " << p2->getStrength() << endl;

        //Attack 1
        attackRoll = p1->attack();
        p2->defense(attackRoll);
        cout << "Attack Roll (Player 1): " << attackRoll << "\n"
        << "Defense Roll (Player 2): " << p2->getCurrentRoll() << "\n"
        << "Total Damage: " << p2->getCurrentDamage() << "\n"
        << "Player 2 Remaining Strength: " << p2->getStrength() << "\n" << endl;

        // Stats
        cout << "\033[1;32mAttacker:\033[0m Player 2\n"
        << "    Type: " << p2->getType() << "\n"
        << "\033[1;32mDefender:\033[0m Player 1\n"
        << "    Type: " << p1->getType() << "\n"
        << "    Armor: " << p1->getArmor() << "\n"
        << "    Strength: " << p1->getStrength() << endl;

        //Attack 2
        attackRoll = p2->attack();
        p1->defense(attackRoll);
        cout << "Attack Roll (Player 2): " << attackRoll << "\n"
        << "Defense Roll (Player 1): " << p1->getCurrentRoll() << "\n"
        << "Total Damage: " << p1->getCurrentDamage() << "\n"
        << "Player 1 Remaining Strength: " << p1->getStrength() << "\n" << endl;
    }

    // see who won
    if(p1->getStrength() >  p2->getStrength())
    {
        cout << "Player 1 won the battle!" << endl;
    }
    else if(p2->getStrength() > p1->getStrength())
    {
        cout << "Player 2 won the battle!" << endl;
    }
    else
    {
        cout << "Looks like a draw friends" << endl;
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
        rounds = 0;
        
        delete p1;
        p1 = nullptr;

        delete p2;
        p2 = nullptr;
        
        choosePlayer();
    }
    
    exit(0);
}