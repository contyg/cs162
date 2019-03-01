/********************************************************************* 
** Program name: Fantasy Combat 
** Author: Genevieve Conty
** Date: 02/17/2019
** Description: Fantasy combat game with multiple characters. Rounds 
**              consist of an attack and defense from each player. 
*********************************************************************/

#include <iostream>
#include <string>

#include "menu.hpp"
#include "validate.hpp"

#include "barbarian.hpp"
#include "blueMen.hpp"
#include "harryPotter.hpp"
#include "medusa.hpp"
#include "vampire.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

Menu::Menu()
{
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

void Menu::makePlayer(int type, int team, string name) 
{
    switch(type)
    {
        case 1: // barbarian
            if(team == 1)
            {
                p1 = new Barbarian;
                break;
            }
            
            p2 = new Barbarian;
            break;

        case 2: // blue men
            if(team == 1)
            {
                p1 = new BlueMen;
                break;
            }
            
            p2 = new BlueMen;
            break;

        case 3: // harry potter
            if(team == 1)
            {
                p1 = new HarryPotter;
                break;
            }
            p2 = new HarryPotter;
            break;

        case 4: // medusa
            if(team == 1)
            {
                p1 = new Medusa;
                break;
            }
            p2 = new Medusa;
            break;

        case 5: // vampire
            if(team == 1)
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
        cout << "\033[1;35m---------- ROUND: " << rounds << " ----------\033[0m\n" << endl;

        // Stats
        cout << "\033[1;33m----- STATS 1 -----\033[0m" << endl; 
        cout << "\033[1;32mAttacker:\033[0m Player 1\n"
        << "    Type: " << p1->getType() << "\n"
        << "\033[1;32mDefender: \033[0m Player 2\n"
        << "    Type: " << p2->getType() << "\n"
        << "    Armor: " << p2->getArmor() << "\n"
        << "    Strength: " << p2->getStrength() << endl;

        //Attack 1
        p1->attack();
        attackRoll = p1->getCurrentRoll();
        p2->defense(attackRoll);
        cout << "Attack Roll (Player 1): " << attackRoll << "\n"
        << "Defense Roll (Player 2): " << p2->getCurrentRoll() << "\n"
        << "Total Damage: " << p2->getCurrentDamage() << "\n"
        << "Player 2 Remaining Strength: " << p2->getStrength() << "\n" << endl;

        // Stats
        cout << "\033[1;33m----- STATS 2 -----\033[0m" << endl; 
        cout << "\033[1;32mAttacker:\033[0m Player 2\n"
        << "    Type: " << p2->getType() << "\n"
        << "\033[1;32mDefender:\033[0m Player 1\n"
        << "    Type: " << p1->getType() << "\n"
        << "    Armor: " << p1->getArmor() << "\n"
        << "    Strength: " << p1->getStrength() << endl;

        //Attack 2
        p2->attack();
        attackRoll = p2->getCurrentRoll();
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

    startMenu();
}

void Menu::choosePlayers(int teamSize, int team)
{
    cout << "\033[1;35m\nChoose your players for TEAM "<< team << "\033[0m" << endl; 
    int i = 0;
    while (i < teamSize)
    {    
        cout << "\033[1;36mPlayer "<< i <<":\033[0m \033[0;36m Choose character type \n" 
        << "    1: Barbarian \n"
        << "    2: BlueMen \n"
        << "    3: Harry Potter \n"
        << "    4: Medusa \n"
        << "    5: Vampire\033[0m" << endl;
        
        int input = getIntegerBetween(1, 5);

        cout << "\033[1;36mPlayer "<< i <<":\033[0m \033[0;36m Choose character name \033[0m" << endl;

        string name;
        cin >> name;

        cout << "NAME:" << name << endl;

        // TODO: set name
        //TODO: makePlayer(); 
        
        i++;
    } 
}

void Menu::makeTeams()
{    
    cout << "\033[0;36m How many players do you want on TEAM 1?\033[0m" << endl;
    int teamOne = getInteger();

    cout << "\033[0;36m How many players do you want on TEAM 2?\033[0m" << endl;
    int teamTwo = getInteger();
    
    // put in appropriate linked list
    choosePlayers(teamOne, 1);

    choosePlayers(teamTwo, 2);

    // play game
}

void Menu::startMenu()
{    
    cout << "\033[0;36m Play: 1 \n Exit: 0\033[0m" << endl;
    
    int input = getIntegerBetween(0, 1);

    if(input)
    {
        rounds = 0;
        
        delete p1;
        p1 = nullptr;

        delete p2;
        p2 = nullptr;
        
        makeTeams();
    }
}