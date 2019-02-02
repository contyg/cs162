/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/

#include "instructor.hpp"
#include <sstream>
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
    
}