#pragma once
#include "Class.h"
class Miner :
    public Class
{
private:
    int miningPower;
public:
    Miner();
    Miner(string name);
    int getMiningPower();

    //Polymorphism
    //These functions do extra pieces while still calling the original base function
    void print();
    void levelUp(int levels);
    void levelUp();
};

