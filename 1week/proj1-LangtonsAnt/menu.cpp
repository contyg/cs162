#include <iostream>
#include <string>
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

// TODO: is below X
bool Menu::maxCheck(int input, int max)
{
    if (input > max)
    {
        cout << "\033[1;31m ERROR: Please enter an integer that is below or equal to the maximum \033[0m\n";
        return false;
    }

    return true;
}

bool Menu::intCheck()
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

// 0-row, 1-col, 2-antRow, 3-antCol, 4-steps, 5-replay
bool Menu::prompt(int i)
{
    cout << "\033[1;31m " << prompts[i] << "\033[0m\n";
    cin >> inputs[i];
    if (!intCheck())
    {
        return false;
    } 
    
    cout << inputs[i];

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
            if (!minCheck(inputs[i], 0) || !maxCheck(inputs[i], inputs[0]))
            {
                return false;
            }
            break;
        case 3: // antCol
            if (!minCheck(inputs[i], 0) || !maxCheck(inputs[i], inputs[1]))
            {
                return false;
            }
            break;
        case 4: // steps
            if (!minCheck(inputs[i], 0) || !maxCheck(inputs[i], 20000))
            {
                return false;
            }
            break;
        case 5: // replay
            // TODO: fix this -1/2 shit
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
    prompts[0] = "How many rows do you want on your board? Min: 70, Max: 100";
    prompts[1] = "How many columns do you want on your board? Min: 70, Max: 100";
    prompts[2] = "What row would you like the ant to start in?";
    prompts[3] = "What column would you like the ant to start in?";
    prompts[4] = "How many steps do you want to take?";
    prompts[5] = "Do you want to play again?";

    // TODO: steps
    // TODO: play again
    // TODO: validate play again input
    // TODO: random ant starting position  

    int i = 0;
    while (i < 5)
    {
        cout << "i: " << i;
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
    }

    return;
}