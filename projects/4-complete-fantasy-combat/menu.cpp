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
    
    losers = nullptr;
    team1 = nullptr;
    team2 = nullptr;
    
    t1Score = 0;
    t2Score = 0;
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

void Menu::playGame()
{   
    // continue unless either team's list is empty
    while(!team1->isEmpty() && !team1->isEmpty())
    {
        Character* teamOnePlayer = team1->getFront();
        Character* teamTwoPlayer = team2->getFront();

        // round continues until 1 character dies
        while(teamOnePlayer->getStrength() > 0 && teamTwoPlayer->getStrength() > 0)
        {
            rounds++;
            cout << "\033[1;35m---------- ROUND: " << rounds << " ----------\033[0m\n" << endl;

            cout << "TEAM 1: " 
            << "    " << teamOnePlayer->getType()<< ": " << teamOnePlayer->getName() 
            << "\nvs\n" 
            << "TEAM 2: " 
            << "    " << teamTwoPlayer->getType()<< ": " << teamTwoPlayer->getName() << endl;

            int attackRoll;

            //Player 1 attacks
            teamOnePlayer->attack();
            attackRoll = teamOnePlayer->getCurrentRoll();
            teamTwoPlayer->defense(attackRoll);

            //Player 2 attacks
            teamTwoPlayer->attack();
            attackRoll = teamTwoPlayer->getCurrentRoll();
            teamOnePlayer->defense(attackRoll);
        }

        // see who won and move players accordingly
        if(teamOnePlayer->getStrength() >  teamTwoPlayer->getStrength())
        {
            cout << teamOnePlayer->getName() << " won the battle for Team 1!" << endl;
            t1Score++;

            // remove losing player from team and put in loser lineup
            losers->addBack(teamTwoPlayer);
            team2->removeFront();
            
            // put winning player at back of team lineup
            team1->removeFront();
            team1->addBack(teamOnePlayer);

        }
        else if(teamTwoPlayer->getStrength() > teamOnePlayer->getStrength())
        {
            cout << teamTwoPlayer->getName() << " won the battle for Team 2!" << endl;
            t2Score++;

            // remove losing player from team and put in loser lineup
            losers->addBack(teamOnePlayer);
            team1->removeFront();
            
            // put winning player at back of team lineup
            team2->removeFront();
            team2->addBack(teamTwoPlayer);
        }
        else
        {
            cout << "Looks like a draw of sorts. Both players lost. " << endl;

            // remove players from teams
            team1->removeFront();
            team2->removeFront();

            // add players to loser pile
            losers->addBack(teamOnePlayer);
            losers->addBack(teamTwoPlayer);
        }
    }

    cout << "RESULTS: " 
    << "\n    Team 1: " << t1Score
    << "\n    Team 2: " << t2Score << endl;

    if (t1Score > t2Score)
    {
        cout << "TEAM 1 WINS" << endl;
    }
    else if (t2Score > t1Score)
    {
        cout << "TEAM 2 WINS" << endl;
    }
    else
    {
        cout << "DRAW" << endl;
    }

    cout << "Would you like to see the loser lineup?"
    << "\n   1: Yes"
    << "\n   o: No" << endl;
    

    startMenu();
}

void Menu::makePlayer(int type, int team)
{
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
        
        int type = getIntegerBetween(1, 5);

        cout << "\033[1;36mPlayer "<< i <<":\033[0m \033[0;36m Choose character name \033[0m" << endl;

        makePlayer(type, team); 
        
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

    // TODO: play game
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