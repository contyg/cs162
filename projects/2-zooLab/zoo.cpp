//TODO: description
#include "zoo.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// ----- START constructor & destructor -------------------
Zoo::Zoo() {
    // start with no daily bonus and $50k in the bank

	bank = 50000; 
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

Zoo::~Zoo() {
    // delete dynamic arrays and point to null
    delete tigers;
    tigers = nullptr;
    
    delete penguins;
	penguins = nullptr;

	delete turtles;
	turtles = nullptr;
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

    cout << "After buying,"<< amount <<" of penguin(s) you have "<< bank << "in the bank."<< endl;
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

    cout << "After buying,"<< amount <<" of tiger(s) you have "<< bank << "in the bank."<< endl;
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
            turtles = new Turtle[tigerArraySize];
        }

        turtles[turtleAmount-1].setAge(age);

        if (buy)
        {
            bank -= 100;
        }
    }

    cout << "After buying,"<< amount <<" of turtle(s) you have "<< bank << "in the bank."<< endl;
}

// ----- START day actions --------------------
void Zoo::ageAll()
{
    int i = 0;
    while (i < penguinAmount) 
    {
        penguins[i].dayOlder();
        i++;
    }
    
    int j = 0;
    while (j < tigerAmount ) 
    {
        tigers[j].dayOlder();
        j++;
    }
    
    int n = 0;
    while (n < turtleAmount) 
    {
        turtles[i].dayOlder();
        n++;
	}
}

void Zoo::calcCosts()
{
    int feedCosts = penguinAmount * penguins[0].getBaseFoodCost()
        + tigerAmount * tigers[0].getBaseFoodCost()
        + turtleAmount * turtles[0].getBaseFoodCost();

    bank -= feedCosts;

    // TODO: colors
    cout << "After feeding costs, you have "<< bank << "in the bank."<< endl;
}

void Zoo::calcProfits()
{
    int payoffs = penguinAmount * penguins[0].getPayoff()
        + tigerAmount * tigers[0].getPayoff()
        + turtleAmount * turtles[0].getPayoff()
        + dailyBonus;
    
    bank += payoffs;

    // TODO: colors
    cout << "After profits, you have "<< bank << "in the bank."<< endl;
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
                    cout << "You have a new raft of baby penguins!" << endl;
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
                    cout << "You have a new baby tiger!" << endl;
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
                    cout << "You have a new bale of baby turtle!" << endl;

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
        cout << "All of your animals are too young to have a kid. Maybe next time." << endl;
    }
 }

void Zoo::animalDies()
 {
    int numAnimalsChecked = 0;
    bool animalDied = false;
    int whichAnimal = rand()%3;

    while (animalDied && numAnimalsChecked < 3)
    {
        // penguin
        if (whichAnimal == 0)
        {
            penguinAmount--;
            numAnimalsChecked++;
            whichAnimal++;
        }
        // tiger
        else if (whichAnimal == 1)
        {
            tigerAmount--;
            numAnimalsChecked++;
            whichAnimal++;
        }
        // turtle
        else if (whichAnimal == 2)
        {
            turtleAmount--;
            numAnimalsChecked++;
            whichAnimal++;
        }
        else if (whichAnimal > 2)
        {
            whichAnimal = 0;
        }
    }

    cout << "Sorry to break it to you but...your " << 
    "animal"<< " died." << endl;
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
            cout << "You've had an attendance boom! You get an extra $" << dailyBonus << endl;
            break;
        case 2: // new baby
            newBaby();
            break;
        default:
            cout << "Nothing random today." << endl;
            break;
    }

    return;
}

void Zoo::day()
{
    int input;
    ageAll();
    calcCosts(); 
    randomEvent();
    calcProfits();
    // TODO: colors
    cout << "Do you want to buy a new animal? \n    1:Yes, 0: No" << endl;
    cin >> input;
    //TODO: validation
    if (input)
    {
        cout << "Which animal would you like to buy? \n    2: Penguin, 1: Tiger, 0: Turtles" << endl;
        cin >> input;
        if (input == 0) 
        {
            makeTurtles(1, 1, true);
        } 
        else if (input == 1) 
        {
            makePenguins(1, 1, true);
        } 
        else
        {
            makeTigers(1, 1, true);
        }
    }
    
    playAgain();

}

// ----- START menu functions --------------------

// TODO: colors
void Zoo::startMenu()
{
    int input;

    cout << "Hi friend! Welcome to Zoo Tycoon. Are you ready to build a zoo?" << endl;
    cout << "1:Yes, 0: No" << endl;

    // TODO: validation
    cin >> input;

    if (!input) 
    {
        cout << "Have a good day!" << endl;
		return exit(0);
	}

    cout << "Your starting budget is: "<< bank << endl;
    cout << "With this budget, you'll need to buy a few animals. \nYou can choose between tigers, penguins and turtles." << endl;
    
    cout << "Do you want to buy 1 or 2 tigers?\n    Please enter 1 or 2." << endl;
    //TODO: validate
    cin >> input;
    makeTigers(input, 1, true);

    cout << "Do you want to buy 1 or 2 penguins?\n    Please enter 1 or 2." << endl;
    //TODO: validate
    cin >> input;
    makePenguins(input, 1, true);

    cout << "Do you want to buy 1 or 2 turtles?\n    Please enter 1 or 2." << endl;
    //TODO: validate
    cin >> input;
    makeTurtles(input, 1, true);

    day();

}

// TODO: colors
void Zoo::playAgain()
{
    int input;
    cout << "Do you want to keep playing? \n    1:Yes, 0: No" << endl;
    cin >> input;
    //TODO: validation
    
    if (input) {
        day();
    }

    return exit(0);
}