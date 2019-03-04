/********************************************************************* 
** Program name: Fantasy Combat Part 2 
** Description: Definition of Menu Class   
*********************************************************************/

#include <iostream>
#include <string>

#include "menu.hpp"
#include "queue.hpp"
#include "DoublyLinkedList.hpp" 
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
    
    losers = new DoublyLinkedList;
    team1 = new Queue;
    team2 = new Queue;
    
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
    while(!team1->isEmpty() && !team2->isEmpty())
    {
        Character* teamOnePlayer = team1->getFront();
        Character* teamTwoPlayer = team2->getFront();
        
        rounds++;
        cout << "\033[1;35m---------- ROUND: " << rounds << " ----------\033[0m\n" << endl;
        
        cout << "TEAM 1: " 
        << "    " << teamOnePlayer->getType()<< ": " << teamOnePlayer->getName() 
        << "\nvs\n" 
        << "TEAM 2: " 
        << "    " << teamTwoPlayer->getType()<< ": " << teamTwoPlayer->getName() << endl;

        // round continues until 1 character dies
        while(teamOnePlayer->getStrength() > 0 && teamTwoPlayer->getStrength() > 0)
        {
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
            cout << "\033[1;33m" << teamOnePlayer->getName() << " won the battle for Team 1!\033[0m\n" << endl;
            t1Score++;

            // remove losing player from team and put in loser lineup
            losers->addHead(teamTwoPlayer);
            team2->removeFront();
            
            // restore strength, put winning player at back of team lineup
            teamOnePlayer->restoreStrength();
            team1->removeFront();
            team1->addBack(teamOnePlayer);

        }
        else if(teamTwoPlayer->getStrength() > teamOnePlayer->getStrength())
        {
            cout << "\033[1;33m" << teamTwoPlayer->getName() << " won the battle for Team 2!\033[0m\n" << endl;
            t2Score++;

            // remove losing player from team and put in loser lineup
            losers->addHead(teamOnePlayer);
            team1->removeFront();
            
            
            // restore strength, put winning player at back of team lineup
            teamTwoPlayer->restoreStrength();
            team2->removeFront();
            team2->addBack(teamTwoPlayer);
        }
        else
        {
            cout << "\033[1;33m" << "Looks like a draw of sorts. Both players lost.\033[0m\n" << endl;

            // remove players from teams
            team1->removeFront();
            team2->removeFront();

            // add players to loser pile
            losers->addHead(teamOnePlayer);
            losers->addHead(teamTwoPlayer);
        }
    }

    cout << "\033[1;36mRESULTS: \033[0m\n" << endl;

    if (t1Score > t2Score)
    {
        cout << "\033[1;32mTEAM 1 WINS\033[0m" << endl;
    }
    else if (t2Score > t1Score)
    {
        cout << "\033[1;32TEAM 2 WINS\033[0m" << endl;
    }
    else
    {
        cout << "\033[1;32DRAW\033[0m" << endl;
    }

    cout << "\nTeam 1 score: " << t1Score << "\nTeam 2 score: " << t2Score << endl;

    cout << "\033[0;36m\nWould you like to see the loser lineup?"
    << "\n   1: Yes"
    << "\n   0: No\033[0m\n" << endl;
    
    int input = getIntegerBetween(0, 1);
    if (input)
    {
        losers->printList();
    }

    playAgain();
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
            else 
            {
                team2->addBack(new Barbarian);
            }
            break;

        case 2: // blue men
            if(team == 1)
            {
                team1->addBack(new BlueMen);
                break;
            }
            else 
            {
                team2->addBack(new BlueMen);
            }
            break;

        case 3: // harry potter
            if(team == 1)
            {
                team1->addBack(new HarryPotter);
                break;
            }
            else
            {
                team2->addBack(new HarryPotter);
            }
            break;

        case 4: // medusa
            if(team == 1)
            {
                team1->addBack(new Medusa);
                break;
            }
            else
            {
                team2->addBack(new Medusa);
            }
            break;

        case 5: // vampire
            if(team == 1)
            {
                team1->addBack(new Vampire);
                break;
            }
            else
            {
                team2->addBack(new Vampire);
            }
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

    // initiate the game play
    playGame();
}

void Menu::startMenu()
{    
    cout << "\033[0;36m Play: 1 \n Exit: 0\033[0m" << endl;
    
    int input = getIntegerBetween(0, 1);

    if(input)
    {        
        makeTeams();
    }
}

void Menu::playAgain()
{    
    cout << "\033[0;36m Play: 1 \n Exit: 0\033[0m" << endl;
    
    int input = getIntegerBetween(0, 1);

    if(input)
    {
        rounds = 0;
        
        delete losers;
        losers = nullptr;
        losers = new DoublyLinkedList;

        delete team1;
        team1 = nullptr;
        team1 = new Queue;
        t1Score = 0;

        delete team2;
        team2 = nullptr;
        team2 = new Queue;
        t2Score = 0;

        makeTeams();
    }
}