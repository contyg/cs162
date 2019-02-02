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

		virtual string getName() = 0;
        virtual int getAge() = 0;
        virtual string getAverage() = 0;

		virtual void do_work() = 0;
};

#endif
