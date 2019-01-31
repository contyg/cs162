/********************************************************************* 
** Program: Dice War
** Description: Declaration file for game class. Keeps score for 
**              players, rolls dice, prints stats and includes menu. 
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
    oneScore = 0;
    twoScore = 0;
    oneTurns = nullptr;
    twoTurns = nullptr;
}

void Game::setPlayersAndRolls()
{
    // prep results arrays
    oneTurns = new int[rounds];
    twoTurns = new int[rounds];

    // Player 1: sides - inputs[2], rounds - inputs[1] 
    if (inputs[4]) {
        LoadedDie one(inputs[2], inputs[1]);
        
        for (int n = 0; n < rounds; n++)
        {
            oneTurns[n] = one.roll();
        }
    } else {
        Die one(inputs[2], inputs[1]);

        for (int n = 0; n < rounds; n++)
        {
            oneTurns[n] = one.roll();
        }
    } 
    
    // Player 2: sides - inputs[3], rounds - inputs[1]
    if (inputs[5]) {
        LoadedDie two(inputs[3], inputs[1]);

        for (int n = 0; n < rounds; n++) {
            twoTurns[n] = two.roll();
        }
    } else {
        Die two(inputs[3], inputs[1]);

        for (int n = 0; n < rounds; n++) {
            twoTurns[n] = two.roll();
        }
    } 
}

void Game::play()
{
    setPlayersAndRolls();
    string p1Type; 
    string p2Type; 

    if (inputs[4]) {
        p1Type = "Loaded";
    } else {
        p1Type = "Regular";
    }

    if (inputs[5]) {
        p2Type = "Loaded";
    } else {
        p2Type = "Regular";
    }
    
    while (rounds > 0)
    {
        if (oneTurns[(rounds-1)] > twoTurns[(rounds-1)]) 
        {
            oneScore++;
        } 
        else if (twoTurns[(rounds-1)] > oneTurns[(rounds-1)])
        {
            twoScore++;
        }

        cout << "\033[32mPlayer 1\033[0m"
        << "\n  Score: " << oneScore
        << "\n  Die Type: " << p1Type
        << "\n  Die Sides: " << inputs[2]
        << "\n  Die Value: " << oneTurns[(rounds-1)]
        << "\n\033[32mPlayer 2\033[0m" 
        << "\n  Score: " << twoScore
        << "\n  Die Type: " << p2Type
        << "\n  Die Sides: " << inputs[3]
        << "\n  Die Value: " << twoTurns[(rounds-1)]
        << "\n-------------------" << endl;

        rounds--;
    }

    if (oneScore > twoScore) 
    {
        cout << "\033[31mPlayer 1 won the war!\033[0m" << endl;
    } 
    else 
    {
        cout << "\033[31mPlayer 2 won the war!\033[0m" << endl;
    }
}

void Game::menu()
{
    string prompts[7];
    prompts[0] = "Do you want to play or exit the game?\n   Please enter an integer to choose. Play: 1, Exit: 0";
    prompts[1] = "How many rounds do you want to play?"; 
    prompts[2] = "How many sides does Player 1 want for their die?";
    prompts[3] = "How many sides does Player 2 want for their die?";
    prompts[4] = "Would Player 1 like the loaded die or the regular die? \n   Please enter an integer to choose. Loaded: 1, Regular: 0";
    prompts[5] = "Would Player 2 like the loaded die or the regular die? \n   Please enter an integer to choose. Loaded: 1, Regular: 0";
    prompts[6] = "Good Game! Wanna play again? \n   Please enter an integer to choose. Play Again: 1, Exit: 0";

    int i = 0;
    while (i < 7)
    {
        bool valid = false;
        double testInput;

        // NOTE: 0 = false, 1 = true
       
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
                if (valid && isBetween(inputs[i], 0, 1) && inputs[i])
                {
                    i++;
                } else if (valid && isBetween(inputs[i], 0, 1) && !inputs[i]) {
                    exit(0);
                }   
                break;
            case 1: // rounds
                if (valid && isAbove(inputs[i], 0))
                {
                    rounds = inputs[i];
                    i++;
                } 
                break;
            case 2: // player 1 sides
            case 3: // player 2 sides
                if (valid && isAbove(inputs[i], 0))
                {
                    i++;
                } 
                break;
            case 4: // player 1 die choice
                if (valid && isBetween(inputs[i], 0, 1))
                {
                    i++;
                }
                break;
            case 5: // player 2 die choice
                if (valid && isBetween(inputs[i], 0, 1))
                {
                    i++;
                    play();
                }
                break;
            case 6: // play again
                if (valid && isBetween(inputs[i], 0, 1) && inputs[i])
                {
                    menu();
                    i++;
                } else if (valid && isBetween(inputs[i], 0, 1) && !inputs[i]) {
                    exit(0);
                }
                break;
            default:
                break;
        }
    }
    
    cout << "\033[1;36m Good game friends! \033[0m\n";
    return;
}

Game::~Game () {
    delete oneTurns; 
    oneTurns = nullptr;

    delete twoTurns;
    twoTurns = nullptr;
}