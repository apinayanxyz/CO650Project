#include "Healer.h"

Healer::Healer():Class()
{
}

Healer::Healer(string name):Class(name)
{
	classType = "Healer";
	healingPower = 5;
	maxManaAmount = 100;
	manaAmount = maxManaAmount;
}

void Healer::print() 
{
	cout << name << "'s healing power is " << healingPower << " ,with " << manaAmount << " mana out of " << maxManaAmount << " left" << endl;
	//Class::print();
	
}

void Healer::useMana(int mana)
{
	if (manaAmount>0)
	{
		if (mana > maxManaAmount - manaAmount)
		{
			cout << name << " used " << maxManaAmount - manaAmount << " mana" << endl;
			manaAmount = 0;
		}
		else
		{
			cout << name << " used " << mana << " mana" << endl;
			manaAmount = manaAmount - mana;
		}
	}
}

int Healer::getHealingPower()
{
	return healingPower;
}

int Healer::getManaAmount()
{
	return manaAmount;
}

int Healer::getMaxManaAmount()
{
	return maxManaAmount;
}
