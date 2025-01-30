#pragma once
#include <iostream>
using namespace std;
class Class
{
private:
	
	int health;
	string classType;
	string name;
	int level;
	int attack;
	int maxHealth;
public:
    //Constructor
    //Overloading
    //Used to provide a defualt constructor for array use and a function that allows a name to be given to an object
	Class();
	Class(string name);
	virtual int checkSuccessrate();

	void damage(int damagepoints);

	//Polymorphism
	//These functions have been made virtual to allow for child classes to have functions 
	//that have the same name (and may do the same thing) while being different and doing different/extra tasks
	virtual void print();
	virtual void levelUp(int levels);
	virtual void heal(int healpoints);
	//Overloading
	//These functions are used incase no parameter is required or provided by the system
	virtual void levelUp();
	virtual void damage();

	//Friendship
	//Will allow theses classes to acces the private attributes of the "class2 class
	friend class Party;
	friend class Mage;
	friend class Miner;
	friend class Healer;
};

