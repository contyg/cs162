/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/
#include "student.hpp"

Student::Student(double gAvg, string n, int a): Person(n, a)
{
    gpa = gAvg;
} 