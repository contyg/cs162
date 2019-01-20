#include <iostream>
#include "ant.hpp"

using std::cout;
using std::cin;
using std::endl;

void menu()
{
    // TODO: random ant starting position  
    int row;
    int col;
    int antCol;
    int antRow;
    int steps;
    int replay;

    // TODO: rows
    // TODO: validate rows
    cout << "\033[1;36m How many rows do you want on your board? \033[0m\n";
    
    // TODO: columns
    // TODO: validate columns
    cout << "\033[1;36m How many columns do you want on your board? \033[0m\n";

    // TODO: ant starting position
    // TODO: validate starting position
    cout << "\033[1;36m What row would you like the ant to start in? \033[0m\n";

    cout << "\033[1;36m What column would you like the ant to start in? \033[0m\n";

    // TODO: steps
    // TODO: validate steps
    cout << "\033[1;36m How many steps do you want to take? \033[0m\n";
    
    Ant ant(5, 5);
    ant.play(2);
    
    // TODO: play again?
    // TODO: validate play again input
    cout << "\033[1;31m Do you want to play again?\033[0m\n";
    cin >> replay;
    
    if (replay) {
        menu();
    }

    return;
}