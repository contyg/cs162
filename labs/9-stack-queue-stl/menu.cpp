/********************************************************************* 
** Program name: Stack and Queue STL Containers Lab  
** Description: Definition of menu functions. 
*********************************************************************/

#include "menu.hpp"
#include "validate.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <queue>

using std::string;
using std::stack;
using std::queue;
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

    // trigger action according to user's choice
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

void printBuffer(queue<int> buffer)
{
    // make copy of buffer
    queue<int> b = buffer;

    // print if not empty
    if(!b.empty())
    {
        while (!b.empty())
        {
            cout << b.front();
            b.pop();
        }
        cout << endl;
        return;
    }
    
    cout << "{empty buffer}" << endl;
}

void buffer()
{
    // menu section
    cout << "\n\033[1;36mFor the buffer simulation:\033[0m" << endl;
    cout << "\033[0;36mHow many rounds?\033[0m" << endl;
    int rounds = getInteger();

    cout << "\033[0;36mIn a percentage, what's the chance of removing random number from the front?\033[0m" << endl;
    int removeChance = getIntegerBetween(0, 100);

    cout << "\033[0;36mIn a percentage, what's the chance of adding random number the the end?\033[0m" << endl;
    int addChance = getIntegerBetween(0, 100);

    //REMOVE:
    cout << "rounds: " << rounds << " removeChance: " << removeChance << " addChance: " << addChance << endl;

    // run simulation 
    queue<int> buffer;
    double avgLength = 0;
    for(int i = 0; i < rounds; i++)
    {
        int N = 1 + rand()%1000; 
        int removeRandom = 1 + rand()%100;
        int addRandom = 1 + rand()%100;

        cout << "i: " << i << " N: " << N << " removeRandom: " << removeRandom << " addRandom: " << addRandom << endl;
        
        // add and remove
        if (removeRandom <= removeChance)
        {
            cout << "REMOVE" << endl;
            buffer.push(N);
        }


        if (addRandom <= addChance && !buffer.empty())
        {
            cout << "ADD" << endl;
            buffer.pop();
        }

        // calculate avg length
        int length = buffer.size();
        avgLength = (avgLength * (rounds - 1)+length) / rounds;

        // output
        cout << "\n\033[1;32m ROUND " << i << "\033[0m" << endl;
        cout << "   buffer length: " << length
        << "\n   buffer avg length: " << avgLength
        << "\n   buffer values: ";
        printBuffer(buffer);
    }

    cout << "4_YO" << endl;
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






