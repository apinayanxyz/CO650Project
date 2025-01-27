#include "Miner.h"
#include <iostream>
using namespace std;
Miner::Miner()
{
}
Miner::Miner(string name) :Class(name)
{
    classType = "Miner";
    miningPower = 10;
}

int Miner::getMiningPower()
{
    return 0;
}

void Miner::print()
{
    Class::print();
    cout << "  " << name << "'s mining power is " << miningPower << endl;
}

void Miner::levelUp(int levels)
{
    Class::levelUp(levels);
    miningPower=miningPower + levels;
}
void Miner::levelUp()
{
    Class::levelUp();
    miningPower = miningPower + 1;
}