/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/

#include "instructor.hpp"
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using::std::ostringstream;

Instructor::Instructor(double r, string n, int a): Person(n, a)
{
    rating = r;
} 

//getters
string Instructor::getName()
{
    return name;
}

int Instructor::getAge()
{
    return age; 
}

string Instructor::getAverage()
{
    ostringstream ratingStr; 
    ratingStr << "Rating: " << rating;

    return ratingStr.str();
}

void Instructor::do_work()
{
    int hours = rand()%41;

    ostringstream message;
    message << name << " graded papers for " << hours << " hours.";

    cout << "\n\033[33m" << message.str() <<  "\033[0m\n" << endl;
}