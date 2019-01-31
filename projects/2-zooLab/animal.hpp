//TODO: description 

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {

    protected:
        int age;
        int cost;
        int numberOfBabies;
        int baseFoodCost;
        int payoff;    

    public: 
        // constructor
        Animal(int cost, int babies, int baseFoodCost, int payoff);
        // functions
        void dayOlder(); 
        bool isAdult(); 
        
        // getters
        int getAge();
        int getCost();
        int getBabies();
        int getBaseFoodCost();
        int getPayoff();

        // setters
        void setAge(int age);
};

#endif