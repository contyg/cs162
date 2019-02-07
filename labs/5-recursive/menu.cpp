/********************************************************************* 
** Program name: Recursive Lab  
** Description: Definition of menu functions. 
*********************************************************************/

#include "menu.hpp"
#include "validate.hpp"
#include "recursive.hpp"

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
    << "\n   \033[35m1\033[0m: Reverse a string"
    << "\n   \033[35m2\033[0m: Sum an array of integers"
    << "\n   \033[35m3\033[0m: Find the triangular number"
    << "\n   0: Exit the program" << endl;

    cin >> testInput;

    bool valid = isInteger(testInput);
    int input;
    
    if (!valid)
    {
        mainMenu(); // re-trigger menu if input invalid
    } 

    input = (int)testInput;

    // trigger menu according to user's function choice
    switch (input)
    {
        case 1: 
            strReverseMenu();
            break;
        case 2:
            sumIntMenu();
            break;
        case 3: 
            triangularNumMenu();
            break;
        default:
            exit(0);
    }
}

void strReverseMenu()
{
    
    string input; 
    cout << "\n\033[36mWhat string would you like to reverse?\033[0m" << endl;

    cin.ignore(); // flush new line character
    getline(cin, input);

    stringReverse(input); // call desired function
    mainMenu(); // loop back to main menu
}

void sumIntMenu()
{
    double testInput;
    
    cout << "\033[32mHow many numbers are in your array?\033[0m" << endl;
    cin >> testInput;

    bool sizeValid = isInteger(testInput);
    int size;

    // re-trigger function menu if input is invalid
    if (!sizeValid)
    {
        sumIntMenu(); 
    }

    size = (int)testInput;
    int array[size];

    // collect all ints to be added
    int i = 0;
    while(i < testInput)
    {
        double testInt;
        
        cout << "\033[32mWhat number do you want at position "<< i <<" ?\033[0m" << endl;

        cin >> testInt;

        bool intValid = isInteger(testInt);

        if(intValid)
        {
            int input = (int)testInt;
            array[i] = input;
            i++;
        }
    }

    sumInt(size, array); // call desired function
    mainMenu(); // loop back to main menu
}

void triangularNumMenu()
{
    double testInput;

    cout << "\033[33mWhat integer would you like to find the triangular number of?\033[0m" << endl;
    cin >> testInput;
    
    bool valid = isInteger(testInput);
    int input;
    
    // re-trigger function menu if input is invalid
    if (!valid)
    {
        triangularNumMenu();
    } 

    input = (int)testInput;
    triangularNum(input); // call desired function
    mainMenu(); // loop back to main menu
}






