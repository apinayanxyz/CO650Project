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
    void heal(int healpoints);
    void useMana(int mana);
    void levelUp(int levels);
    void levelUp();
};

