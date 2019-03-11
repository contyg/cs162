/********************************************************************* 
** Program name: Stack and Queue STL Containers Lab  
** Description: Definition of menu functions. 
*********************************************************************/

#include "menu.hpp"
#include "validate.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

void mainMenu()
{
    double testInput;
    // colorful menu with prompts for function choice
    cout << "\033[35mWhich function would you like to use?\033[0m"
    << "\n   \033[35m1\033[0m: Test the buffer"
    << "\n   \033[35m2\033[0m: Create a palindrome"
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
            cout << "Have a nice day!" << endl;
    }
}

void buffer()
{
    
    cout << "\n\033[36mWhat string would you like to reverse?\033[0m" << endl;
    int input; 

    mainMenu(); // loop back to main menu
}

void palindrome()
{
     
    mainMenu(); // loop back to main menu
}






