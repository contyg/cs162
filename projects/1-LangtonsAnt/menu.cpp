/********************************************************************* 
** Program: TODO: 
** Description: TODO: 
*********************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include "menu.hpp"
#include "ant.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

bool Menu::minCheck(int input, int min)
{
    if (input < min)
    {
        cout << "\033[1;31m ERROR: Please enter an integer that is above or equal to the minimum \033[0m\n";
        return false;
    }
    return true;
}

bool Menu::maxCheck(int input, int max)
{
    if (input > max)
    {
        cout << "\033[1;31m ERROR: Please enter an integer that is below or equal to the maximum \033[0m\n";
        return false;
    }

    return true;
}

// checks for chars and doubles
bool Menu::intCheck(double testInput)
{
    if (cin.fail() || testInput-floor(testInput)) 
    {
        cout << "\033[1;31m ERROR: Please enter an integer value \033[0m\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

// NOTE: 0-row, 1-col, 2-antRow, 3-antCol, 4-steps, 5-replay
bool Menu::prompt(int i)
{
    double testInput;
    
    cout << "\033[1;31m " << prompts[i] << "\033[0m\n";
    cin >> testInput;

    if (!intCheck(testInput))
    {
        return false;
    }

    inputs[i] = (int)testInput;
    
    switch (i)
    {
        case 0: // row
        case 1: // col
            if (!minCheck(inputs[i], 70) || !maxCheck(inputs[i], 100))
            {
                return false;
            }
            break;
        case 2:
            if (!minCheck(inputs[i], -1) || !maxCheck(inputs[i], 2))
            {
                prompt(2);
            }
            break;
        case 3: // antRow
            if (!minCheck(inputs[i], 0) || !maxCheck(inputs[i], inputs[0]-1))
            {
                return false;
            }
            break;
        case 4: // antCol
            if (!minCheck(inputs[i], 0) || !maxCheck(inputs[i], inputs[1]-1))
            {
                return false;
            }
            break;
        case 5: // steps
            if (!minCheck(inputs[i], 1) || !maxCheck(inputs[i], 33000))
            {
                return false;
            }
            break;
        case 6: // replay
            if (!minCheck(inputs[i], -1) || !maxCheck(inputs[i], 2))
            {
                prompt(5);
            }
            break;
        default:
            break;
    }
    return true;
}

void Menu::getInfo()
{
    prompts[0] = "How many rows do you want on your board? \n Min: 70, Max: 100";
    prompts[1] = "How many columns do you want on your board? \n Min: 70, Max: 100";
    prompts[2] = "Would you like to 0: Pick where your ant starts or 1: Get a random start point?";
    prompts[3] = "What row would you like the ant to start in? \n Remember, index starts at 0! So Min: 0, Max: 100 (total rows - 1)";
    prompts[4] = "What column would you like the ant to start in? \n Remember, index starts at 0! So Min: 0, Max: 100 (total columns - 1)";
    prompts[5] = "How many steps do you want to take? \n Min: 1, Max: 33000";
    prompts[6] = "Do you want to play again? \n No: 0, Yes: 1";

    int i = 0;
    while (i < 6)
    {
        if(prompt(i))
        {
            i++; 
        }
        // if (inputs[2])
        // {
        //     inputs[3] = (rand()%inputs[0]);
        //     inputs[4] = (rand()%inputs[1]);
        //     i += 2;
        // }
    }

    Ant ant(inputs);
    ant.play(inputs[4]);

    prompt(5);

    if(inputs[5])
    {
        getInfo();
    } else {
        cout << "\033[1;36m Good game friend! \033[0m\n";
    }

    return;
}