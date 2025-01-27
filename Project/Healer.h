#pragma once
#include "Class.h"
class Healer :
    public Class
{
private:
    int maxManaAmount;
    int manaAmount;
    int healingPower;
public:
    Healer();
    Healer(string name);
    void print();
    void useMana(int mana);
    int getHealingPower();
    int getManaAmount();
    int getMaxManaAmount();
};

