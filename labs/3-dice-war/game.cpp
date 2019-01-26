/********************************************************************* 
** Program: TODO: 
** Description: TODO:  
** Inputs: TODO: 
*********************************************************************/
#include "game.hpp"
#include "validate.hpp"
#include <iostream>
#include <string>

using std::string;
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
        << "\n  Die Type: Regular"
        << "\n  Die Sides: " << player.getSides()
        << "\n  Die Value: " << playerLastRoll
        << "\n\033[32mPlayer 2\033[0m" 
        << "\n  Score: " << cheater.getScore() 
        << "\n  Die Type: Loaded" 
        << "\n  Die Sides: " << cheater.getSides()
        << "\n  Die Value: " << cheaterLastRoll
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
    string prompts[6];
    prompts[0] = "Do you want to play or exit the game?\n   Please enter an integer to choose. Play: 1, Exit: 0";
    prompts[1] = "How many rounds do you want to play?"; 
    prompts[2] = "Would Player 1 like the loaded die or the regular die? \n   Please enter an integer to choose. Loaded: 0, Regular: 1";
    prompts[3] = "How many sides does Player 1 want for their die?";
    prompts[4] = "How many sides does Player 2 want for their die?";
    prompts[5] = "Good Game! Wanna play again? \nPlease enter an integer to choose. Play Again: 1, Exit: 0";

    int inputs[6] = {0};

    cout << "\033[31m MENU\033[0m\n"
    << "-------------------" << endl;

    int i = 0;
    while (i < 5)
    {
        bool valid = false;
        double testInput;
       
        cout << "\033[31m" << prompts[i] << "\033[0m\n";
        cin >> testInput;

        if (isInteger(testInput))
        {
            valid = true;
            inputs[i] = (int)testInput;
        }

        switch (i)
        {
            case 0: // play or exit
                if (valid)
                {
                    i++;
                }
                break;
            case 1: // rounds
                if (valid)
                {
                    rounds = inputs[i];
                    i++;
                } 
                break;
            case 2: // player 1 die choice
                if (valid)
                {
                    i++;
                } 
                break;
            case 3: // player 1 sides
                if (valid)
                {
                    i++;
                }
                break;
            case 4: // player 2 sides
                if (valid)
                {
                    i++;
                }
                break;
            case 5: // play agian
                if (valid)
                {
                    i++;
                }
                break;
            default:
                break;
        }
    }

    play();

    cout << "\033[32mSee you later!\033[0m" << endl;


}