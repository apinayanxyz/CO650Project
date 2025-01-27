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
Class::Class(string name)
{
	this->name = name;
	level = baseLevel;
	attack = baseAttack;
	maxHealth = baseMaxHealth;
	health = baseHealth;
	return;
}

 void Class:: print()
{
	cout << classType << " " << name << "- level:" << level << "|| attack:" << attack << "|| health:" << health << " out of " << maxHealth << " left" << endl;
}
int Class::checkSuccessrate()
{
	cout << "Test2" << endl;
	int chance = 5 + (level / 10) + (2 * (attack / 3)) - (maxHealth - health);
	cout << chance << endl;
	return chance;
}

void Class::levelUp(int levels)
{
	level = levels + level;
	attack = attack + (1 * levels);
	maxHealth = maxHealth + (2 * levels);
	health = health + (2 * levels);
}
void Class::levelUp()
{
	level = 1 + level;
	attack = attack + 1;
	maxHealth = maxHealth + 2;
	health = health + 2;
}
void Class::damage()
{
	int damagepoints = 10;
	if (health > 0) {
		if (damagepoints <= (health)) {
			health = health - damagepoints;
			cout << name << " was damaged for " << damagepoints << endl;
		}
		else {
			cout << name << " was damaged for " << (health) << endl;
			health = 0;
		}
	}

	else {
		cout << name << " is at 0 health" << endl;
	}
}
void Class::heal(int healpoints)
{
	if (health < maxHealth) {
		if (healpoints <= (maxHealth - health)) {
			health = health + healpoints;
			cout << name << " healed for " << healpoints << endl;
		}
		else {
			cout << name << " healed for " << (maxHealth-health) << endl;
			health = maxHealth;
		}
	}

	else {
		cout << classType << " " << name << " didn't need to heal" << endl;
	}
	
}

void Class::damage(int damagepoints)
{
	if (health > 0) {
		if (damagepoints <= (health)) {
			health = health - damagepoints;
			cout << name << " was damaged for " << damagepoints << endl;
		}
		else {
			cout << name << " was damaged for " << (health) << endl;
			health = 0;
		}
	}

	else {
		cout << name << " is at 0 health" << endl;
	}
}


