/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/
#include "student.hpp"
#include <sstream>
using::std::ostringstream;

Student::Student(double gradeAvg, string n, int a): Person(n, a)
{
    gpa = gradeAvg;
} 

//getters
string Student::getName()
{
    return name;
}

int Student::getAge()
{
    return age;
}

string Student::getAverage()
{
    ostringstream GPA; 
    GPA << "GPA: " << gpa;

    return GPA.str();
}

void Student::do_work()
{
    
}