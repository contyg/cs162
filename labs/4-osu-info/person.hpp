/********************************************************************* 
** Program: OSU Information System  
** Description: TODO: 
*********************************************************************/

#ifndef PERSON_H
#define PERSON_H

#include <string>
using std::string;

class Person
{
	protected: 
		string name;
		int age;

	public:
		Person(string name, int age);
		virtual ~Person(){};

		virtual void do_work() = 0;
};

#endif
