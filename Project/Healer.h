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
    void useMana(int mana);
    void restoreMana(int mana);

    //Polymorphism
    //These functions do extra pieces while still calling the original base function
    void print();
    void levelUp(int levels);
    void levelUp();
    //Getters
    int getHealingPower();
    int getManaAmount();
    int getMaxManaAmount();
};

