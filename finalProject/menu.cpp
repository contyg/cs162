//TODO: description
#include "menu.hpp"
#include "boss.hpp"
#include "health.hpp"
#include "riddle.hpp"
#include "standard.hpp"
#include "warrior.hpp"
#include "validate.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// ------ MAP ------------
// [ std1 ][ std2 ][ rid1 ]
// [ rid2 ][health][ std3 ]
// [ std4 ][ rid3 ][ boss ]

Menu::Menu()
{
    // make various spaces
    std1 = new Standard(0, 0); 
    std2 = new Standard(0, 1); 
    rid1 = new Riddle(0, 2); 
    
    rid2 = new Riddle(1, 0); 
    health = new Health(1, 1);
    std3 = new Standard(1, 2);
    
    std4 = new Standard(2, 0);
    rid3 = new Riddle(2, 1); 
    boss = new Boss(2, 2); 

    // link the map spaces
    std1->setLinkedSpaces(nullptr, rid2, nullptr, std2);
    std2->setLinkedSpaces(nullptr, health, std1, rid1);
    rid1->setLinkedSpaces(nullptr, std3, std2, nullptr);


    rid2->setLinkedSpaces(std1, std4, nullptr, health);
    health->setLinkedSpaces(std2, rid3, rid2, std3);
    std3->setLinkedSpaces(rid1, boss, health, nullptr);

    std4->setLinkedSpaces(rid2, nullptr, nullptr, rid3);
    rid3->setLinkedSpaces(health, nullptr, std4, boss);
    boss->setLinkedSpaces(std3, nullptr, rid3, nullptr);

    // fill attack options
    attackOptions[0] = "Choose your attack: ";
    attackOptions[1] = "\n    1: Fight with your fists (1pt)";
    attackOptions[2] = "\n    2: Fight with your sword (3pt)";
    attackOptions[3] = "\n    0: Use the Trifecta (6pt)";

    // establish warrior
    braveWarrior = new Warrior();
    braveWarrior->setLocation(std1);

    keepPlaying = true;
}

Menu::~Menu()
{
    delete std1;
    delete std2;
    delete std3;
    delete std4;

    delete rid1;
    delete rid2;
    delete rid3;

    delete health;
    delete boss;
}

// print map with user position 
void Menu::printMap(int userRow, int userColumn)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // riddle, purple
            if ((i == 1 && j == 0) || (i == 2 && j == 1) || (i == 0 && j == 2))
            {
                if (i == userColumn && j == userRow)
                {
                    cout << "\033[1;34m[\033[0m" << "X" << "\033[1;34m]\033[0m";
                }
                else
                {
                    cout << "\033[1;34m[ ]\033[0m";
                }
            }
            // health, pink
            else if (i == 1 && j == 1)
            {
                if (i == userColumn && j == userRow)
                {
                    cout << "\033[1;35m[\033[0m" << "X" << "\033[1;35m]\033[0m";
                }
                else
                {
                    cout << "\033[1;35m[ ]\033[0m";
                }
            }
            // boss, green
            else if (i == 2 && j == 2)
            {
                if (i == userColumn && j == userRow)
                {
                    cout << "\033[1;32m[\033[0m" << "X" << "\033[1;32m]\033[0m";
                }
                else
                {
                    cout << "\033[1;32m[ ]\033[0m";
                }
            }
            // standard spaces, white
            else
            {
                if (i == userColumn && j == userRow)
                {
                    cout << "\033[1;37m[\033[0m" << "X" << "\033[1;37m]\033[0m";
                }
                else
                {
                    cout << "\033[1;37m[ ]\033[0m";
                }
            }
        }
        cout << endl;
    }

    cout << "\n" << endl;
}

// print map w/o user
void Menu::printMap()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // riddle, purple
            if ((i == 1 && j == 0) || (i == 2 && j == 1) || (i == 0 && j == 2))
            {
                cout << "\033[1;34m[ ]\033[0m";
            }
            // health, pink
            else if (i == 1 && j == 1)
            {
                cout << "\033[1;35m[ ]\033[0m";
            }
            // boss, green
            else if (i == 2 && j == 2)
            {
                cout << "\033[1;32m[ ]\033[0m";
            }
            // standard spaces, cyan
            else
            {
                cout << "\033[1;37m[ ]\033[0m";
            }
        }
        cout << endl;
    }
    cout << "\n" << endl;
}

void Menu::intro()
{
    cout << "\033[0;36mINTRODUCTION AND GOALS AND STUFF\033[0m" << endl;
}

int Menu::betweenMovesMenu()
{
    cout << "\033[0;36mWhat would you like to do next?\033[0m"
    << "\n    \033[0;36m1\033[0m: Print map (Costs 1 strenth point)"
    << "\n    \033[0;36m2\033[0m: Print map and show where you are (Costs 2 strenth points)"
    << "\n    \033[0;36m3\033[0m: Check contents of your backpack"
    << "\n    \033[0;36m4\033[0m: Check your health"
    << "\n    \033[0;36m5\033[0m: Move 1 space" 
    << "\n    \033[0;37m0\033[0m: Exit"<< endl;
    
    int choice = getIntegerBetween(0, 5);
    return choice;
}

char Menu::moveWarriorMenu()
{
    Space* location = braveWarrior->getLocation();
    char up = '-';
    char down = '-';
    char left = '-';
    char right = '-';

    cout << "\033[0;36mWhich direction would you like to move?\033[0m" << endl;
    
    if (location->getUp() != nullptr)
    {
        cout << "   \033[0;36mU\033[0m: Up to a " << location->getUp()->getType() << endl;
        up = 'U';
    }

    if (location->getDown() != nullptr)
    {
        cout << "   \033[0;36mD\033[0m: Down to a " << location->getDown()->getType() << endl;
        down = 'D';
    }

    if (location->getLeft() != nullptr)
    {
        cout << "   \033[0;36mL\033[0m: Left to a " << location->getLeft()->getType() << endl;
        left = 'L';
    }

    if (location->getRight() != nullptr)
    {
        cout << "   \033[0;36mR\033[0m: Right to a " << location->getRight()->getType() << endl;
        right = 'R';
    }

    char choice = getCharMatch(up, down, right, left);
    return choice; 
}

int Menu::attackMenu()
{
    int optionCount = braveWarrior->getOptionCount();
    int choice;

    for (int i = 0; i < (optionCount+1); i++)
    {
        cout << attackOptions[i] << endl; 
    }
    
    //print trifecta as choice if available and not used
    if(braveWarrior->getBackpack()->getFull() && braveWarrior->getBackpack()->getTrifectaNotUsed())
    {
        cout << attackOptions[3] << endl;
        choice = getIntegerBetween(0, optionCount);
    } 
    else // print other options
    {
        choice = getIntegerBetween(1, optionCount);
    }

    return choice;
}

void Menu::battleMenu()
{
    cout << "\033[0;36mIt is time to engage the boss. Have your Trifecta ready!\033[0m" << endl;
    
    // reset boss health
    boss->setHealth(15);
    
    // attack loops
    do
    {
        // attack boss
        int attackChoice = attackMenu();
        int attackDamage = braveWarrior->attack(attackChoice);
        boss->updateHealth(attackDamage);

        // boss attack and warrior defense
        int bossAttackDamage = boss->action();
        int damageTaken = braveWarrior->defense(bossAttackDamage);
        braveWarrior->updateStrength(damageTaken);

        cout << "Warrior Health: " << braveWarrior->getStrength()
        << "\n    Boss Health: " << boss->getHealth() << endl;
    } while (braveWarrior->getStrength() > 0 && boss->getHealth() > 0) ;
    
    if(braveWarrior->getStrength() > 0 && boss->getHealth() <= 0)
    {
        cout << "You've WON!" << endl;
    }
    else
    {
        cout << "Boss killed you" << endl;
    }
    keepPlaying = false;
}

void Menu::playGame()
{
    do
    {
        int choice = betweenMovesMenu();

        // route to appropriate action/menu
        switch (choice)
        {
            case 1: 
                braveWarrior->updateStrength(-1);
                printMap();
                break;
            case 2:
                //braveWarrior->updateStrength(-2);
                printMap(braveWarrior->getLocation()->getColumn(), braveWarrior->getLocation()->getRow());
                break;
            case 3: 
                braveWarrior->getBackpack()->printContents();
                break;
            case 4: 
                cout << "\033[0;35mYour current health is " << braveWarrior->getStrength() << "\033[0m \n" << endl;
                break;
            case 5:
            {
                char moveChoice = moveWarriorMenu();
                braveWarrior->move(moveChoice); 
                if (braveWarrior->getLocation()->getType() == "\033[0;32mBoss\033[0m")
                {
                    battleMenu();
                }
            }
                break;  
            default:
                keepPlaying = false;
                cout << "MK BYE THEN" << endl;
                break;
        }

        // check strength
        if (braveWarrior->getStrength() < 1)
        {
            cout << "U DEAD" << endl;
            keepPlaying = false;
        }
    } while (keepPlaying);

    cout << "U FINISHED BYE" << endl;
}