/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/

#include "building.hpp"
#include <string>
using std::string;

Building::Building(string n, int s, string a)
{
    name = n;
    size = s;
    address = a; 
}

// getters
string Building::getName()
{
    return name;
}

int Building::getSize()
{
    return size;
}

string Building::getAddress()
{
    return address;
}

