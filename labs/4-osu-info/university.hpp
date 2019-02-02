/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/

#include "building.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"

#include <vector>
#include <string>
using std::vector;
using std::string;

class University
{
    private:
        string name;
        vector<Building*> buildings;
        vector<Person*> people;
        
    public:
        University();

        void startMenu();
        void workMenu();

        void printBuildings();
        void printPeople();
};