#pragma once
#include <iostream>
using namespace std;
class Class
{
private:
	
public:
	int health;
	string name;
	int level;
	int attack;
	int maxHealth;

	//Constructor
	Class();
	Class(string name);
	int checkSuccessrate();
	void levelUp(int levels);
	void heal(int healpoints);
	void damage(int damagepoints);
		
	void levelUp();
	void heal();
	void damage();
};

