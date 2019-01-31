//TODO: description 

#include "Animal.hpp"

// constructor
Animal::Animal(int c, int b, int bfc, int p)
{
    age = 1;
    cost = c;
    numberOfBabies = b;
    baseFoodCost = bfc;
    payoff = p;
}

// functions
void Animal::dayOlder()
{
    age++; 
} 

bool Animal::isAdult()
{
    if (age >= 3) {
        return true;
    }
    return false;
}

// getters
int Animal::getAge()
{
    return age;
}

int Animal::getCost()
{
    return cost;
}

int Animal::getBabies()
{
    return numberOfBabies;
}

int Animal::getBaseFoodCost()
{
    return baseFoodCost;
}

int Animal::getPayoff()
{
    return payoff;
}

// setters
void Animal::setAge(int a)
{ 
    age = a;
}