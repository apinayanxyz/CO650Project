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
	Class::print();
	cout << "  " <<name << "'s healing power is " << healingPower << " ,with " << manaAmount << " mana out of " << maxManaAmount << " left" << endl;
}

void Healer::levelUp(int levels)
{
	Class::levelUp(levels);
	healingPower = healingPower + 2 * levels;
	maxManaAmount = maxManaAmount + (10*levels);
	manaAmount = manaAmount + (10 * levels);
}

void Healer::levelUp()
{
	Class::levelUp();
	healingPower = healingPower + 2;
	maxManaAmount = maxManaAmount + (10);
	manaAmount = manaAmount + (10);
}

void Healer::useMana(int mana)
{
	if (manaAmount>0)
	{
		if (mana > manaAmount)
		{
			cout << name << " used " << manaAmount << " mana" << endl;
			manaAmount = 0;
		}
		else
		{
			cout << name << " used " << mana << " mana" << endl;
			manaAmount = manaAmount - mana;
		}
	}
}

void Healer::restoreMana(int mana)
{
	if (manaAmount < maxManaAmount)
	{
		if (mana > maxManaAmount - manaAmount)
		{
			cout << name << " restored " << maxManaAmount-manaAmount << " mana" << endl;
			manaAmount = maxManaAmount;
		}
		else
		{
			cout << name << " restored " << mana << " mana" << endl;
			manaAmount = manaAmount + mana;
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
