/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/

#include "building.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"

#include <string>
using std::string;

class University
{
    private:
        string name;
        Building *buildings;
        Person *people;
        
    public:
        University();
        void printBuildings();
        void printPeople();
};