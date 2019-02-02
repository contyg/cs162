/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/

#ifndef STUDENT_H
#define STUDENT_H

#include "person.hpp"

#include <string>
using std::string;

class Student: public Person {

    private:
        double gpa;


    public:
        Student(double gAvg, string n, int a);
        virtual ~Student(){};

        void do_work();
};

#endif