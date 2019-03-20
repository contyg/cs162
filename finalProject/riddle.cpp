//TODO: description
#include "riddle.hpp"
#include "validate.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Riddle::Riddle(int r, int c) : Space()
{
    type = "\033[1;34mRiddle\033[0m";
    row = r;
    column = c;
    health = 0;
}

int Riddle::action()
{
    int damage = -2; 
    
    if (health == 1)
    {
        cout << "\n\033[0;34mYou've solved this riddle already!\033[0m\n" << endl;
    }
    // riddle source: https://puzzle.dse.nl/quiz1us/index.html
    else if (row == 0)
    {
        cout << "\n\033[0;34mA man is standing in front of a painting of a man, and he tells us the following: \n"
        << "\"Brothers and sisters have I none, but this man's father is my father's son\". Who is on the painting?" << endl;
        
        cout << "\nChoose your answer carefully: \033[0m\n" 
        << "\n    \033[1;34m1\033[0m: grandfather"
        << "\n    \033[1;34m2\033[0m: son"
        << "\n    \033[1;34m3\033[0m: himself"
        << "\n    \033[1;34m4\033[0m: father"
        << endl;
        
        int input = getIntegerBetween(1, 4);
        
        if (input == 2)
        {
            health = 1;
            damage = 0;
            cout << "\n\033[0;34mCorrect, Warrior\033[0m\n" << endl;
        }
        else
        {
            cout << "\n\033[0;34mWrong...walk away slowly\033[0m\n" << endl;
        }
        
    }
    // riddle source: https://www.gotoquiz.com/answers/can_you_guess_these_riddles?serans=0,0,3,4,1,1,1,4,3,1,3,3
    else if (row == 1)
    {
        cout << "\n\033[0;34mThe dead bodies of Bob and Ann are lying on the floor. They are naked and wet. \n"
        << "Their bodies have absolutely no cuts. The windows are open to the house they live in, and it is stormy. \n"
        << "How did they die?" << endl;
    
        cout << "\nChoose your answer carefully: \033[0m\n" 
        << "\n    \033[1;34m1\033[0m: Struck by lightning"
        << "\n    \033[1;34m2\033[0m: Poisoned"
        << "\n    \033[1;34m3\033[0m: They aren't human"
        << "\n    \033[1;34m4\033[0m: Drowned"
        << endl;
        
        int input = getIntegerBetween(1, 4);

        if (input == 3)
        {
            health = 1;
            damage = 0;
            cout << "\n\033[0;34mCorrect, Warrior\033[0m\n" << endl;
        }
        else
        {
            cout << "\n\033[0;34mWrong...walk away slowly\033[0m\n" << endl;
        }
    }
    // riddle source: https://puzzle.dse.nl/quiz1us/index.html
    else if (row == 2)
    {
        cout << "\n\033[0;34mA hunter leaves his cabin early in the morning and walks one mile due south. Here he sees a \n"
        << "bear and starts chasing it for one mile due east before he is able to shoot the bear. After shooting the bear,\n"
        << "he drags it one mile due north back to his cabin where he started that morning. What color is the bear?" << endl;
    
        cout << "\nChoose your answer carefully: \033[0m\n" 
        << "\n    \033[1;34m1\033[0m: black"
        << "\n    \033[1;34m2\033[0m: white"
        << "\n    \033[1;34m3\033[0m: brown"
        << "\n    \033[1;34m4\033[0m: grey"
        << endl;

        int input = getIntegerBetween(1, 4);

        if (input == 2)
        {
            health = 1;
            damage = 0;
            cout << "\n\033[0;34mExcellent choice, Warrior\033[0m\n" << endl;
        }
        else
        {
            cout << "\n\033[0;34mWrong...walk away slowly\033[0m\n" << endl;
        }
    } 

    return damage;
}

int Riddle::getHealth()
{
    return health;
}

void Riddle::setHealth(int h){}

void Riddle::updateHealth(int damage){}