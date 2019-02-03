/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "person.hpp"

#include <string>
using std::string;

class Instructor: public Person {

    private:
        double rating;

    public:
        Instructor(double r, string n, int a);

        //getters
        string getName(); 
        int getAge();
        string getAverage();

        void do_work();
};

#endif