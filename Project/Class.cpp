#include "Class.h"
#include <iostream>
using namespace std;
int baseLevel = 1;
int baseAttack = 5;
int baseMaxHealth = 20;
int baseHealth = 20;
Class::Class()
{
	level = baseLevel;
	attack = baseAttack;
	maxHealth = baseMaxHealth;
	health = baseHealth;
	return;
}
int Class::checkSuccessrate()
{
	int chance = 5 + (level / 10) + (2 * (attack / 3)) - (maxHealth - health);
	return chance;
}

void Class::levelUp(int levels)
{
	level = levels + level;
	attack = attack + (1 * levels);
	maxHealth = maxHealth + (2 * levels);
}

void Class::heal(int healpoints)
{
	if (health < maxHealth) {
		if (healpoints <= (maxHealth - health)) {
			health = health + healpoints;
			cout << "Healed for " << healpoints << endl;
		}
		else {
			cout << "Healed for " << (maxHealth-health) << endl;
			health = maxHealth;
		}
	}

	else {
		cout << "You don't need to heal" << endl;
	}
	
}
