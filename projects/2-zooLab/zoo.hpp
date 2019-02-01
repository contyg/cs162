/********************************************************************* 
** Program: Dice War 
** Description: Definition file Zoo class. Contains daily zoo game 
**              functions, including random events, profit calculations
**              and cost calculations.
*********************************************************************/

#ifndef ZOO_H
#define ZOO_H

#include "animal.hpp"
#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"

class Zoo {

    private:
        int dailyBonus;
        int bank;
        
        Animal *tigers;
        Animal *penguins;
        Animal *turtles;
        
        int tigerArraySize;
        int penguinArraySize;
        int turtleArraySize;

        int tigerAmount;
        int penguinAmount;
        int turtleAmount;

    public: 
        // constructor & destructor
        Zoo();
        ~Zoo();

        // buy and create new animals
        void makePenguins(int amount, int age, bool buy); 
        void makeTigers(int amount, int age, bool buy);
        void makeTurtles(int amount, int age, bool buy);

        // day actions
        void ageAll();
        void calcCosts(); 
        void calcProfits();
        void randomEvent(); 
        void newBaby(); 
        void animalDies(); 
        void day();
        void newAnimal();

        // menu functions
        void startMenu();
        void playAgain(); 
};

#endif