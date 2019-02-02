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

University::University() {
	name = "Oregon State University";

    // mqke buildings
    buildings.push_back(new Building("Kelley Engineering Center", 152166, "110 SW Park Terrace"));
    buildings.push_back(new Building("Aero Engineering Lab", 3637, "852 SW 30th Street"));

    // make a student & instructor
    people.push_back(new Student(4.0, "Hermione Granger", 21)); 
    people.push_back(new Instructor(2.0, "Serverus Snape", 55));
}

void University::startMenu()
{
    cout << "\033[35mWelcome to the OSU Information System.\033[0m" << endl;
    
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

        if (isInteger(testInput))
        {
            valid = true;
            validInput = (int)testInput;
        }

        if (isBetween(validInput, 0, 3))
        {
            switch(validInput)
            {
                case 0:
                    printBuildings();
                    break;
                case 1:
                    printPeople();
                    break;
                case 2:
                    workMenu();
                    break;
                default: 
                    cout << "\033[35mOk, byyyyee!\033[0m" << endl;
                    keepPlaying = false;
                    break;
            }
        }
    }
}

void University::printBuildings()
{
    //TODO: name, address, size
    cout << "\033[33m PRINT BUILDINGS \033[0m" << endl;
}

void University::printPeople()
{
    //TODO: name, age, GPA/Rating
    //TODO: diff message for prof/student
    cout << "\033[33m PRINT PPL \033[0m" << endl;
}

void University::workMenu()
{
    // TODO: choose who does work
    cout << "\033[33m WORK MENU\033[0m" << endl;
}