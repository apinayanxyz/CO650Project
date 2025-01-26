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
};

