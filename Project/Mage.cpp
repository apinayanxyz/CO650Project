#include "Mage.h"

Mage::Mage()
{
}

Mage::Mage(string name):Class(name)
{
	classType = "Mage";
	manaLevel = 1;
	maxManaAmount = 100;
	manaAmount = maxManaAmount;
}

void Mage::print()
{
	Class::print();
	cout << "  " << name << "'s mana level is " << manaLevel << " ,with " << manaAmount << " mana out of " << maxManaAmount << " left" << endl;
}

void Mage::heal(int healpoints)
{
	if (maxManaAmount > manaAmount)
	{
		if ((maxManaAmount-manaAmount)>(2*healpoints))
		{
			manaAmount = manaAmount + 2 * healpoints;
			cout << name << " restored " << 2 * healpoints << " mana" << endl;
		}
		else {
			cout << name << " restored " << maxManaAmount - manaAmount << " mana" << endl;
			manaAmount = maxManaAmount;
		}
	}
	Class::heal(healpoints);
}

void Mage::useMana(int mana)
{
	if (manaAmount > 0)
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

void Mage::restoreMana(int mana)
{
	if (manaAmount < maxManaAmount)
	{
		if (mana > maxManaAmount - manaAmount)
		{
			cout << name << " restored " << maxManaAmount - manaAmount << " mana" << endl;
			manaAmount = maxManaAmount;
		}
		else
		{
			cout << name << " restored " << mana << " mana" << endl;
			manaAmount = manaAmount + mana;
		}
	}
}

void Mage::levelUp(int levels)
{
	Class::levelUp(levels);
	manaLevel=manaLevel+levels;
	maxManaAmount = maxManaAmount + (10 * levels);
	manaAmount = manaAmount + (10 * levels);
}
void Mage::levelUp()
{
	Class::levelUp(1);
	manaLevel = manaLevel + 1;
	maxManaAmount = maxManaAmount + (10);
	manaAmount = manaAmount + (10);
}

int Mage::getManaAmount()
{
	return manaAmount;
}

int Mage::getMaxManaAmount()
{
	return maxManaAmount;
}

int Mage::getManaLevel()
{
	return manaLevel;
}
