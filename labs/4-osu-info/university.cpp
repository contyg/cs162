/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/
#include "university.hpp"
#include "student.hpp"
#include "instructor.hpp"

#include "validate.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

University::University() 
{
	name = "Oregon State University";

    // mqke buildings
    buildings.push_back(new Building("Kelley Engineering Center", 152166, "110 SW Park Terrace"));
    buildings.push_back(new Building("Aero Engineering Lab", 3637, "852 SW 30th Street"));

    // make a student & instructor
    people.push_back(new Student(3.9, "Hermione Granger", 21)); 
    people.push_back(new Instructor(2.1, "Serverus Snape", 55));
}

University::~University()
{
    for(int i = 0; i < buildings.size(); i++)
    {
        delete buildings[i];
		buildings[i] = nullptr;
    }

    for(int i = 0; i < people.size(); i++)
    {
        delete people[i];
		people[i] = nullptr;
    }
}

void University::startMenu()
{
    cout << "\033[35mWelcome to the OSU Information System.\033[0m\n" << endl;
    
    bool keepPlaying = true;

    // game play
    while (keepPlaying)
    {
        int validInput;
        bool valid = false;
        double testInput;
    
    
        cout << "\033[32mWhat would you like to do?\033[0m"
        << "\n  0: List all the buildings"
        << "\n  1: List all the people"
        << "\n  2: Assign work to someone"
        << "\n  3: Quit playing" << endl;

        cin >> testInput;

        // validation
        if (isInteger(testInput))
        {
            valid = true;
            validInput = (int)testInput;
        }

        // execute desired action
        if (isBetween(validInput, 0, 3))
        {
            switch(validInput)
            {
                case 0:
                    printBuildings();
                    break;
                case 1:
                    printPeople(false);
                    break;
                case 2:
                    workMenu();
                    break;
                default: 
                    cout << "\n\033[35mSee you later!\033[0m" << endl;
                    keepPlaying = false;
                    break;
            }
        }
    }
}

void University::printBuildings()
{
    cout << "\n\033[36mOSU buildings on the record: \033[0m\n" << endl;
    for(int i = 0; i < buildings.size(); i++)
    {
        cout << "\033[33mBuilding " << i << ":\033[0m"
        << "\n  Name: " << buildings[i]->getName()
        << "\n  Size: " << buildings[i]->getSize() << " sq ft"
        << "\n  Address: 1" << buildings[i]->getAddress() << "\n" << endl;
    }
}

void University::printPeople(bool onlyNames)
{
    if (onlyNames) // print only names
    {
        cout << "\n" << endl;
        for(int i = 0; i < people.size(); i++)
        {
            cout << "\033[33mPerson " << i << ": \033[0m"
            << people[i]->getName() << endl;
        }
    }
    else // print all info
    {
        cout << "\n\033[36mOSU instructors and students on the record: \033[0m\n" << endl;

        for(int i = 0; i < people.size(); i++)
        {
            cout << "\033[33mPerson " << i << ":\033[0m"
            << "\n  Name: " << people[i]->getName()
            << "\n  Age: " << people[i]->getAge()
            << "\n  " << people[i]->getAverage() << "\n" << endl;
        }
    }
     
}

void University::workMenu()
{
    // print just names
    printPeople(true);

    bool noWorkDone = true;

    // ask user who should do work
    while(noWorkDone)
    {
        int validInput;
        double testInput;

        cout << "\n\033[32mWho would you like to do work?\033[0m"
        << "\n    Please enter their number." << endl;

        cin >> testInput;

        if (isInteger(testInput))
        {
            validInput = (int)testInput;
        } 

        if (isBetween(validInput, 0, (people.size()-1)))
        {
            people[validInput]->do_work();
            noWorkDone = false;
        }
    }
    
}
