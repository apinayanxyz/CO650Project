#pragma once
#include <iostream>
using namespace std;
class Class
{
private:
	
public:
	int health;
	string classType;
	string name;
	int level;
	int attack;
	int maxHealth;

	//Constructor
	Class();
	Class(string name);
	int checkSuccessrate();


	//Polymorphism
	//These functions have been made virtual to allow for child classes to have functions 
	//that have the same name (and may do the same thing) while being different and doing different/extra tasks
	virtual void print();
	virtual void levelUp(int levels);
	virtual void heal(int healpoints);

	void damage(int damagepoints);
		

	//Overloading
	//These functions are used incase no parameter is required or provided by the system
	void levelUp();
	void damage();
};

