/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/
#include "student.hpp"
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
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
    int hours = rand()%41;

    ostringstream message;
    message << name << " did " << hours << " hours of homework." << endl;
    cout << "\n\033[33m" << message.str() <<  "\033[0m" << endl;
}