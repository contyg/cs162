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
    cout << "GAME Play" << endl;
    player.setSides(6);
    cheater.setSides(6);

    while (rounds > 0)
    {
        player.roll();
        cheater.roll();

        int playerLastRoll = player.getLastRoll();
        int cheaterLastRoll = cheater.getLastRoll();

        if (playerLastRoll > cheaterLastRoll) 
        {
            player.addPoint();
        } 
        else if (cheaterLastRoll > playerLastRoll)
        {
            cheater.addPoint();
        }

        cout << "\033[1;32mPlayer 1\033[0m"
        << "\n  Score: " << player.getScore()
        << "\n  Die Side: " << playerLastRoll
        << "\n\033[32mPlayer 2\033[0m" 
        << "\n  Score: " << cheater.getScore() 
        << "\n  Die Side: " << cheaterLastRoll
        << "\n-------------------" << endl;

        rounds--;
    }

    // TODO: pretty stuff
    if (player.getScore() > cheater.getScore()) 
    {
        cout << "Player # beat the odds and won the war!" << endl;
    } 
    else 
    {
        cout << "Predicatably...player # won the war." << endl;
    }

    // menu();
}

void Game::menu()
{
    cout << "\033[31m MENU\033[0m\n";

    rounds = 6;
    play();

    // TODO: set rounds
    // TODO: pretty stuff
    // TODO: bigger letters?
}