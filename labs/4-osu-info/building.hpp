/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/

#ifndef BUILDING_H
#define BUILDING_H

#include <string>
using std::string;

class Building 
{

private:
	string name;
	int size;
	string address;
	
public:
	Building(string name, int size, string address);

	// getters
	string getName();
	int getSize();
	string getAddress();
};


#endif
