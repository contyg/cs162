#include <iostream>
#include <string>
#include <cmath>
#include "menu.hpp"
#include "ant.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

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

bool Menu::intCheck(int i)
{
    if (cin.fail()) 
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
    cout << "\033[1;31m " << prompts[i] << "\033[0m\n";
    cin >> inputs[i];
    if (!intCheck(i))
    {
        return false;
    }
    
    switch (i)
    {
        case 0: // row
        case 1: // col
            if (!minCheck(inputs[i], 70) || !maxCheck(inputs[i], 100))
            {
                return false;
            }
            break;
        case 2: // antRow
            if (!minCheck(inputs[i], 0) || !maxCheck(inputs[i], inputs[0]-1))
            {
                return false;
            }
            break;
        case 3: // antCol
            if (!minCheck(inputs[i], 0) || !maxCheck(inputs[i], inputs[1]-1))
            {
                return false;
            }
            break;
        case 4: // steps
            if (!minCheck(inputs[i], 1) || !maxCheck(inputs[i], 33000))
            {
                return false;
            }
            break;
        case 5: // replay
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
    prompts[1] = "How many columns do you want on your board? \n Min: 70, Max: 100 (total rows - 1)";
    prompts[2] = "What row would you like the ant to start in? \n Remember, index starts at 0! So Min: 0, Max: 100 (total rows - 1)";
    prompts[3] = "What column would you like the ant to start in? \n Remember, index starts at 0! So Min: 0, Max: 100 (total columns - 1)";
    prompts[4] = "How many steps do you want to take? \n Min: 1, Max: 33000";
    prompts[5] = "Do you want to play again? \n No: 0, Yes: 1";

    int i = 0;
    while (i < 5)
    {
        if(prompt(i))
        {
            i++; 
        }
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