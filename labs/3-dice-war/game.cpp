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

        cout << "\033[32mPlayer 1\033[0m"
        << "\n  Score: " << player.getScore()
        << "\n  Regular Die Side & Value: " << playerLastRoll
        << "\n\033[32mPlayer 2\033[0m" 
        << "\n  Score: " << cheater.getScore() 
        << "\n  Loaded Die Side & Value: " << cheaterLastRoll
        << "\n-------------------" << endl;

        rounds--;
    }

    if (player.getScore() > cheater.getScore()) 
    {
        cout << "\033[31mPlayer 1 beat the odds and won the war!\033[0m" << endl;
    } 
    else 
    {
        cout << "\033[31mPredicatably...player 2 won the war.\033[0m" << endl;
    }

    // menu();
}

void Game::menu()
{
    cout << "\033[31m MENU\033[0m\n"
    << "-------------------" << endl;
    cout << "\033[31mDo you want to play or exit the game?\033[0m\n";
    cout << "\033[31m   Please enter an integer to choose. Play: 1, Exit: 0\033[0m\n";

    cout << "\033[31mHow many rounds do you want to play?\033[0m\n";
    cout << "\033[31mWould Player 1 like the loaded die or the regular die? Loaded: 0, Regular: 1\033[0m\n";
    cout << "\033[31m   Please enter an integer to choose. Loaded: 0, Regular: 1\033[0m\n";
    cout << "\033[31mHow many sides does Player 1 want for their die?\033[0m\n";
    cout << "\033[31mHow many sides does Player 2 want for their die?\033[0m\n";

    cout << "\033[31mGood Game! Wanna play again?\033[0m\n";
    cout << "\033[31m   Please enter an integer to choose. Play Again: 1, Exit: 0\033[0m\n";
    cout << "\033[32mSee you later!\033[0m" << endl;

    rounds = 6;
    play();

}