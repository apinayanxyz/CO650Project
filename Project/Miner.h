#pragma once
#include "Class.h"
class Miner :
    public Class
{
private:
    int miningPower;
public:
    //Constructor
    //Overloading
    //Used to provide a defualt constructor for array use and a function that allows a name to be given to an object
    Miner();
    Miner(string name);

    int getMiningPower();

    //Polymorphism
    // Functions that has the same name as functions in the parent class while having different definitions
    //These functions do extra pieces while still calling the original base function
    void print();
    void levelUp(int levels);
    void levelUp();
};

