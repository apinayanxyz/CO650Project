#pragma once
class Class
{
private:
	
public:
	int health;
	int level;
	int attack;
	int maxHealth;

	Class();
	int checkSuccessrate();
	void levelUp(int levels);
	void heal(int healpoints);
		
};

