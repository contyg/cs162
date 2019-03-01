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
#include "queue.hpp"
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
    team1 = nullptr;
    team2 = nullptr;
    losers = nullptr;
}

Menu::~Menu()
{
    delete team1;
    team1 = nullptr;

    delete team2;
    team2 = nullptr;
    
    delete losers;
    losers = nullptr;
}

void Menu::makePlayer(int type, int team, string name) 
{
    // TODO: set name

    switch(type)
    {
        case 1: // barbarian
            if(team == 1)
            {
                team1->addBack(new Barbarian); 
                break;
            }
            
            team2->addBack(new Barbarian);
            break;

        case 2: // blue men
            if(team == 1)
            {
                team1->addBack(new BlueMen);
                break;
            }
            
            team2->addBack(new BlueMen);
            break;

        case 3: // harry potter
            if(team == 1)
            {
                team1->addBack(new HarryPotter);
                break;
            }
            team2->addBack(new HarryPotter);
            break;

        case 4: // medusa
            if(team == 1)
            {
                team1->addBack(new Medusa);
                break;
            }
            team2->addBack(new Medusa);
            break;

        case 5: // vampire
            if(team == 1)
            {
                team1->addBack(new Vampire);
                break;
            }
            team2->addBack(new Vampire);
            break;

        default:
            break;
    }
}

void Menu::playGame()
{
    int attackRoll;
    while(team1->getStrength() > 0 && team2->getStrength() > 0)
    {
        rounds++;
        cout << "\033[1;35m---------- ROUND: " << rounds << " ----------\033[0m\n" << endl;

        // Stats
        cout << "\033[1;33m----- STATS 1 -----\033[0m" << endl; 
        cout << "\033[1;32mAttacker:\033[0m Player 1\n"
        << "    Type: " << team1->getType() << "\n"
        << "\033[1;32mDefender: \033[0m Player 2\n"
        << "    Type: " << team2->getType() << "\n"
        << "    Armor: " << team2->getArmor() << "\n"
        << "    Strength: " << team2->getStrength() << endl;

        //Attack 1
        team1->attack();
        attackRoll = team1->getCurrentRoll();
        team2->defense(attackRoll);
        cout << "Attack Roll (Player 1): " << attackRoll << "\n"
        << "Defense Roll (Player 2): " << team2->getCurrentRoll() << "\n"
        << "Total Damage: " << team2->getCurrentDamage() << "\n"
        << "Player 2 Remaining Strength: " << team2->getStrength() << "\n" << endl;

        // Stats
        cout << "\033[1;33m----- STATS 2 -----\033[0m" << endl; 
        cout << "\033[1;32mAttacker:\033[0m Player 2\n"
        << "    Type: " << team2->getType() << "\n"
        << "\033[1;32mDefender:\033[0m Player 1\n"
        << "    Type: " << team1->getType() << "\n"
        << "    Armor: " << team1->getArmor() << "\n"
        << "    Strength: " << team1->getStrength() << endl;

        //Attack 2
        team2->attack();
        attackRoll = team2->getCurrentRoll();
        team1->defense(attackRoll);
        cout << "Attack Roll (Player 2): " << attackRoll << "\n"
        << "Defense Roll (Player 1): " << team1->getCurrentRoll() << "\n"
        << "Total Damage: " << team1->getCurrentDamage() << "\n"
        << "Player 1 Remaining Strength: " << team1->getStrength() << "\n" << endl;
    }

    // see who won
    if(team1->getStrength() >  team2->getStrength())
    {
        cout << "Player 1 won the battle!" << endl;
    }
    else if(team2->getStrength() > team1->getStrength())
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
        
        delete team1;
        team1 = nullptr;

        delete team2;
        team2 = nullptr;
        
        makeTeams();
    }
}