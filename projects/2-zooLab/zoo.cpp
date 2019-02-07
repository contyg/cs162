/********************************************************************* 
** Program: Dice War 
** Description: Declaration file Zoo class. Contains daily zoo game 
**              functions, including random events, profit calculations
**              and cost calculations.
*********************************************************************/

#include "zoo.hpp"
#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"
#include "validation.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
using std::string;
using std::cout;
using std::cin;
using std::endl;

// ----- START constructor & destructor -------------------
Zoo::Zoo() 
{
    // start with no daily bonus and $25k in the bank
	bank = 25000; 
    dailyBonus = 0;

    // start with no animals
    tigerAmount = 0;
    penguinAmount = 0;
    turtleAmount = 0;

    // start with 10 for each animal
    tigerArraySize = 10;
    penguinArraySize = 10;
	turtleArraySize = 10;

    // dynamically create arrays for each animal
    tigers = new Tiger[tigerArraySize];
    penguins = new Penguin[penguinArraySize];
	turtles = new Turtle[turtleArraySize];
}

Zoo::~Zoo() 
{
    // delete dynamic arrays
    delete tigers;

    delete penguins;

	delete turtles;
}

// ----- START buy and create new animals ----------------
void Zoo::makePenguins(int amount, int age, bool buy)
{  
    for (int i = 0; i < amount; i++)
    {
        penguinAmount++;
    
        // resize array if needed
        if (penguinAmount > penguinArraySize) 
        {
            penguinArraySize*=2;
            penguins = new Penguin[penguinArraySize];
        }

        penguins[penguinAmount-1].setAge(age);

        if (buy)
        {
            bank -= 1000;
        }
    }

    if (buy)
    {
        cout << "\033[32mAfter buying, "<< amount <<" penguin(s) you have $"<< bank << " in the bank.\033[0m"<< endl;
    }
}

void Zoo::makeTigers(int amount, int age, bool buy)
{  
    for (int i = 0; i < amount; i++)
    {
        tigerAmount++;
        
        // resize array if needed
        if (tigerAmount > tigerArraySize) 
        {
            tigerArraySize*=2;
            tigers = new Tiger[tigerArraySize];
        }

        tigers[tigerAmount-1].setAge(age);

        if (buy)
        {
            bank -= 10000;
        }   
    }

    if (buy)
    {
        cout << "\033[32mAfter buying, "<< amount <<" tiger(s) you have $"<< bank << " in the bank.\033[0m"<< endl;
    }
}

void Zoo::makeTurtles(int amount, int age, bool buy)
{  
    for (int i = 0; i < amount; i++)
    {
        turtleAmount++;
        
        // resize array if needed
        if (turtleAmount > turtleArraySize) 
        {
            turtleArraySize*=2;
            turtles = new Turtle[turtleArraySize];
        }

        turtles[turtleAmount-1].setAge(age);

        if (buy)
        {
            bank -= 100;
        }
    }

    if (buy)
    {
        cout << "\033[32mAfter buying, "<< amount <<" turtle(s) you have $"<< bank << " in the bank.\033[0m"<< endl;
    }
}

// ----- START day actions --------------------
void Zoo::ageAll()
{
    int i = 0;
    while (i < penguinAmount) 
    {
        penguins[i].dayOlder();
        cout << "\033[34mPenguin #" << i << " is " << penguins[i].getAge() << " day(s) old.\033[0m"<< endl;
        i++;
    }
    
    int j = 0;
    while (j < tigerAmount) 
    {
        tigers[j].dayOlder();
        cout << "\033[34mTiger #" << j << " is " << tigers[j].getAge() << " day(s) old.\033[0m"<< endl;
        j++;
    }
    
    int n = 0;
    while (n < turtleAmount) 
    {
        turtles[n].dayOlder();
        cout << "\033[34mTurtle #" << n << " is " << turtles[n].getAge() << " day(s) old.\033[0m"<< endl;
        n++;
	}
}

void Zoo::calcCosts()
{
    int feedCosts = penguinAmount * penguins[0].getBaseFoodCost()
        + tigerAmount * tigers[0].getBaseFoodCost()
        + turtleAmount * turtles[0].getBaseFoodCost();

    bank -= feedCosts;

    cout << "\033[32mAfter feeding costs, you have $"<< bank << " in the bank.\033[0m"<< endl;
}

void Zoo::calcProfits()
{
    int payoffs = penguinAmount * penguins[0].getPayoff()
        + tigerAmount * tigers[0].getPayoff()
        + turtleAmount * turtles[0].getPayoff()
        + dailyBonus;
    
    bank += payoffs;

    cout << "\033[32mAfter profits, you have $"<< bank << " in the bank.\033[0m"<< endl;
}

 void Zoo::newBaby()
 {
    int whichAnimal = rand()%3;
    int numAnimalsChecked = 0;
    bool noNewBaby = true;

    while (noNewBaby && numAnimalsChecked < 3)
    {
        // penguin
        if (whichAnimal == 0)
        {
            for (int i = 0; i < penguinAmount; i++)
            {
                if (penguins[i].isAdult())
                {
                    noNewBaby = false;
                    
                    int penguinLitter = penguins[i].getBabies();
                    makePenguins(penguinLitter, 0, false);
                    cout << "\033[35mYou have a new raft of baby penguins!\033[0m" << endl;
                    break;
                }
            }
            numAnimalsChecked++;
            whichAnimal++;
        }
        // tiger
        else if (whichAnimal == 1)
        {
            for (int i = 0; i < tigerAmount; i++)
            {
                if (tigers[i].isAdult())
                {
                    noNewBaby = false;
                    makeTigers(1, 0, false);
                    cout << "\033[35mYou have a new baby tiger!\033[0m" << endl;
                    break;
                }
            }
            numAnimalsChecked++;
            whichAnimal++;
        }
        // turtle
        else if (whichAnimal == 2)
        {
            for (int i = 0; i < turtleAmount; i++)
            {
                if (turtles[i].isAdult())
                {
                    noNewBaby = false;
                    
                    int turtleLitter = turtles[i].getBabies();
                    makeTurtles(turtleLitter, 0, false);
                    cout << "\033[35mYou have a new bale of baby turtle!\033[0m" << endl;

                    break;
                }
            }
            numAnimalsChecked++;
            whichAnimal++;
        } 
        else if (whichAnimal > 2)
        {
            whichAnimal = 0;
        }
    }

    if(noNewBaby && numAnimalsChecked > 3)
    {
        cout << "\033[35mAll of your animals are too young to have a kid. Maybe next time.\033[0m" << endl;
    }
 }

void Zoo::animalDies()
 {
    int numAnimalsChecked = 0;
    bool animalNotDead = true;
    int whichAnimal = rand()%3;
    string deadAnimalType = "";

    while (animalNotDead && numAnimalsChecked < 3)
    {
        // penguin
        if (whichAnimal == 0 && penguinAmount > 0)
        {
            penguinAmount--;
            deadAnimalType = "penguin";
            animalNotDead = false;  
        }
        // tiger
        else if (whichAnimal == 1 && tigerAmount > 0)
        {
            tigerAmount--;
            deadAnimalType = "tiger";
            animalNotDead = false;
        }
        // turtle
        else if (whichAnimal == 2 && turtleAmount > 0)
        {
            turtleAmount--;
            deadAnimalType = "turtle";
            animalNotDead = false;  
        }
        else if (whichAnimal > 2)
        {
            whichAnimal = 0;
        }
        numAnimalsChecked++;
        whichAnimal++;
    }

    cout << "\033[35mSorry to break it to you but...your "  
    << deadAnimalType << " died.\033[0m" << endl;
 }

void Zoo::randomEvent()
{
    int event = rand()%4;

    switch(event)
    {
        case 0: // animal dies
            animalDies();
            break;
        case 1: // attendance boom
            dailyBonus = tigerAmount*(rand()%(250 + 1) + 250);
            cout << "\033[35mYou've had an attendance boom! You get an extra $" << dailyBonus << "\033[0m" << endl;
            break;
        case 2: // new baby
            newBaby();
            break;
        default:
            cout << "\033[35mNothing random today.\033[0m" << endl;
            break;
    }

    return;
}

void Zoo::newAnimal()
{
    string prompts[2];
    prompts[0] = "Do you want to buy a new animal? \n    1:Yes, 0: No";
    prompts[1] = "Which animal would you like to buy? \n    2: Tiger, 1: Penguin, 0: Turtles";

    int i = 0;
    while (i < 2)
    {
        double testInput;
        int validInput;
        bool valid = false;

        bool is_between = false;

        cout << "\033[31m" << prompts[i] << "\033[0m\n";
        cin >> testInput;

        if (isInteger(testInput))
        {        
            valid = true;
            validInput = (int)testInput;
        }

        switch (i)
        {
            case 0:
                is_between = isBetween(validInput, 0, 1);
                if (valid && validInput)
                {
                    i++;
                } 
                else if (valid && !validInput)
                {
                    i += 2;
                }
                break;
            case 1:
                is_between = isBetween(validInput, 0, 2);
                if (valid)
                {
                    if (validInput == 0) 
                    {
                        makeTurtles(1, 1, true);
                    } 
                    else if (validInput == 1) 
                    {
                        makePenguins(1, 1, true);
                    } 
                    else
                    {
                        makeTigers(1, 1, true);
                    }
                    i++;
                }
                break;
            default:
                break;
        }        
    }
}

void Zoo::day()
{
    if (bank < 1)
    {
        cout << "\033[1;36mLooks like you are out of money. GG friend!\033[0m\n";
        exit(0);
    }

    ageAll();
    calcCosts(); 
    randomEvent();
    calcProfits();
    newAnimal();
    playAgain();
}

// ----- START menu functions --------------------

void Zoo::startMenu()
{
    int input;
    string prompts[4];
    prompts[0] = "Hi friend! Welcome to Zoo Tycoon. Are you ready to build a zoo? \n    1:Yes, 0: No";
    prompts[1] = "Do you want to buy 1 or 2 tigers?\n    Please enter 1 or 2."; 
    prompts[2] = "Do you want to buy 1 or 2 penguins?\n    Please enter 1 or 2.";
    prompts[3] = "Do you want to buy 1 or 2 turtles?\n    Please enter 1 or 2.";
    
    int i = 0;
    while (i < 4)
    {
        bool valid = false;
        double testInput;
        int validInput;
        bool is_between = false;
       
        cout << "\033[31m" << prompts[i] << "\033[0m\n";
        cin >> testInput;

        if (isInteger(testInput))
        {
            valid = true;
            validInput = (int)testInput;
        }

        switch (i)
        {
            case 0: // play or exit
                is_between = isBetween(validInput, 0, 1);
                if (valid && is_between && validInput)
                {
                    cout << "Your starting budget is: "<< bank << endl;
                    cout << "With this budget, you'll need to buy a few animals. \nYou can choose between tigers, penguins and turtles." << endl; 
                    i++;
                } else if (valid && is_between && !validInput) {
                    cout << "Have a good day!" << endl;
		            return exit(0);
                }   
                break;
            case 1: // tigers
                is_between = isBetween(validInput, 1, 2);
                if (valid && is_between)
                {
                    makeTigers(validInput, 1, true);
                    i++;
                } 
                break;
            case 2: // penguins
                is_between = isBetween(validInput, 1, 2);
                if (valid && is_between)
                {
                    makePenguins(validInput, 1, true);
                    i++;
                } 
                break;
            case 3: // turtles
                is_between = isBetween(validInput, 1, 2);
                if (valid && is_between)
                {
                    makeTurtles(validInput, 1, true);
                    i++;
                } 
                break;
            default:
                break;
        }
    }

    day();
}

void Zoo::playAgain()
{
    double testInput;
    int validInput;
    bool valid = false;
    
    cout << "Do you want to keep playing? \n    1:Yes, 0: No" << endl;
    cin >> testInput;

    if (isInteger(testInput))
    {
        valid = true;
        validInput = (int)testInput;
    }

    bool is_between = isBetween(validInput, 0, 1);
    
    if (valid && validInput && is_between) 
    {
        day();
    } 
    else if (valid && !validInput && is_between)
    {
        return exit(0);
    }

    playAgain();
}
