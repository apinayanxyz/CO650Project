#include "Mage.h"

Mage::Mage()
{
}

Mage::Mage(string name):Class(name)
{
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
