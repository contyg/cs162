#include <iostream>
#include <string>
#include "ant.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;



// TODO: is above 0
void isAboveMin(int input, int min)
{
    if (input < min)
    {
        cout << "\033[1;31m ERROR: Please enter an integer that is above or equal to the minimum \033[0m\n";
    }
}

// TODO: is below X
void isBelowMax(int input, int max)
{
    if (input > max)
    {
        cout << "\033[1;31m ERROR: Please enter an integer that is below or equal to the maximum \033[0m\n";
    }
}

bool prompt(string str, int &input, int i, int optionalMax = 0)
{
    cout << "\033[1;31m "<< str <<"\033[0m\n";
    if (cin.fail()) 
    {
        cout << "\033[1;31m ERROR: Please enter an integer value \033[0m\n";
        prompt(str, input, i);
    }

    cin >> input;

    switch (i)
    {
        case 0:
        case 1:
            isAboveMin(input, 70);
            break;
        case 2:
            isAboveMin(input, 0);
            isBelowMax(input, optionalMax);
        case 3:
            isAboveMin(input, 0);
            isBelowMax(input, optionalMax);
        case 4:
            isAboveMin(input, 0);
            isBelowMax(input, 20000);
        case 5:
            isAboveMin(input, -1);
            isBelowMax(input, 2);
        default:
            break;
    }

    return true;
}

void menu()
{
    // TODO: random ant starting position  
    int row = 0;
    int col = 0;
    int antCol = 0;
    int antRow = 0;
    int steps = 0;
    int replay = 2;
    
    int inputs[6] = {row, col, antCol, antRow, steps, replay};
    string prompts[6] = {
        "How many rows do you want on your board?", 
        "How many columns do you want on your board?", 
        "What row would you like the ant to start in?", 
        "What column would you like the ant to start in?", 
        "How many steps do you want to take?",
        "Do you want to play again?"};
    
    int i = 0;
    while (i < 6)
    {
        prompt(prompts[i], i);
    }

    // TODO: rows
    // TODO: validate rows
    if (prompt(""))
    {
        cin >> row;
        isAboveMin(row, 70);
    }
    
    // TODO: columns
    // TODO: validate columns

    // TODO: ant starting position
    // TODO: validate starting position


    // TODO: steps
    // TODO: validate steps
    
    Ant ant(5, 5);
    ant.play(2);
    
    // TODO: validate play again input
    cin >> replay;

    if (cin.fail()) 
    {
        cout << "\033[1;31m Do you want to play again?\033[0m\n";
    } 
    else if (replay) 
    {
        menu();
    }

    return;
}