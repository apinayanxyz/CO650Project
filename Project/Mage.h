#pragma once
#include "Class.h"
class Mage :
    public Class
{
private:
    int manaLevel;
    int manaAmount;
    int maxManaAmount;
public:
    //Constructor
    //Overloading
    //Used to provide a defualt constructor for array use and a function that allows a name to be given to an object
    Mage();
    Mage(string name);

    void useMana(int mana);
    void restoreMana(int mana);

    //Polymorphism
    // Functions that has the same name as functions in the parent class while having different definitions
    //These functions do extra pieces while still calling the original base function
    void print();
    void heal(int healpoints);
    void levelUp(int levels);
    void levelUp();

    //Getters
    int getManaAmount();
    int getMaxManaAmount();
    int getManaLevel();


};

