/********************************************************************* 
** Program: TODO: 
** Description: TODO:  
** Inputs: TODO: 
*********************************************************************/
#include "game.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Game::Game()
{
    rounds = 0;
    Die player;
    LoadedDie cheater;
}

void Game::play()
{
    cout << "YO" << endl;
    menu();
    while (rounds > 0)
    {
        player.roll();
        cheater.roll();

        if (player.getLastRoll() > cheater.getLastRoll()) 
        {
            player.addPoint();
        } 
        else 
        {
            cheater.addPoint();
        }

        rounds--;
    }
    
}

void Game::menu()
{
    cout << "MENU:" << endl;
    // TODO: set rounds
}