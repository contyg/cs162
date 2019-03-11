/********************************************************************* 
** Program name: Stack and Queue STL Containers Lab  
** Description: Definition of menu functions. 
*********************************************************************/

#include "menu.hpp"
#include "validate.hpp"
#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::stack;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

void mainMenu()
{
    double testInput;
    // colorful menu with prompts for function choice
    cout << "\n\033[1;35mWhich function would you like to use?\033[0m"
    << "\n   \033[0;35m1\033[0m: Test the buffer"
    << "\n   \033[0;35m2\033[0m: Create a palindrome"
    << "\n   0: Exit the program" << endl;

    int input = getInteger();

    // trigger menu according to user's function choice
    switch (input)
    {
        case 1: 
            buffer();
            break;
        case 2:
            palindrome();
            break;
        default:
            cout << "\033[0;33mHave a nice day! :D\033[0m" << endl;
    }
}

void buffer()
{
    // menu section
    cout << "\n\033[1;36mFor the simulation:\033[0m" << endl;
    cout << "\n\033[0;36m    How many rounds?\033[0m" << endl;
    int rounds = getInteger();

    cout << "\033[0;36m    In a percentage, what's the chance of adding random number at start?\033[0m" << endl;
    int headChance = getIntegerBetween(0, 100);

    cout << "\033[0;36m    In a percentage, what's the chance of adding random number at end?\033[0m" << endl;
    int tailChance = getIntegerBetween(0, 100);

    cout << "roundsp: " << rounds << " headChance: " << headChance << " tailChance: " << tailChance << endl;

    // loop back to main menu
    mainMenu(); 
}

void palindrome()
{
    // menu section
    string input; 
    cout << "\n\033[36mWhat string would you like to make a palindrome?\033[0m" << endl;

    cin.ignore(); // flush new line character
    getline(cin, input);

    // put input into stack
    stack<char> word;
    int i = 0;

    while(i < input.size())
    {
        word.push(input[i]);
        i++;
    }

    // print first half
    cout << input;

    // pop and print last half
    while(!word.empty())
    {
        // print char
        cout << word.top();
        // remove char
        word.pop();
    }

    // loop back to main menu
    mainMenu(); 
}






