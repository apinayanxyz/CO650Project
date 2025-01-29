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
    Mage();
    Mage(string name);
    void useMana(int mana);
    void restoreMana(int mana);

    //Polymorphism
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

