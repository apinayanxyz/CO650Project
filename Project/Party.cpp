#include "Party.h"
#include "Class.h"
#include "Miner.h"
#include "Mage.h"
#include "Healer.h"
#include <iostream>
using namespace std;
Party::Party()
{
	party = new Class*[maxPartySize];
	minerList = new Miner[maxPartySize];
	healerList = new Healer[maxPartySize];
	mageList = new Mage[maxPartySize];
	partySize = 0;
	healers = 0;
	miners = 0;
	mages = 0;
	gold = 0;
}
void Party::printParty()
{
	for (size_t i = 0; i < partySize; i++)
	{	
		Class* p;
		p = (party[i]);
		p->print();
	}
}
void Party::addMiner(string name)
{
	if (partySize<maxPartySize)
	{
		Miner tester = Miner(name);

		Miner* i ;

		i = &tester;
		party[partySize] = new Miner(name);
		minerList[miners] = *i;
		partySize++;
		miners++;
	}
}
int Party::getMinerNumber()
{
	return miners;
}
void Party::addMage(string name)
{
	if (partySize < maxPartySize)
	{
		Mage mage = Mage(name);
		Mage* mageP;
		mageP = &mage;
		mageList[mages] = *mageP;

		party[partySize] = new Mage(name);
		partySize++;
		mages++;
	}
}
int Party::getMageNumber()
{
	return mages;
}
void Party::addHealer(string name)
{
	if (partySize < maxPartySize)
	{
		Healer healer = Healer(name);

		Healer* healerP;

		healerP = &healer;
		party[partySize] = new Healer(name);
		healerList[healers] = *healerP;
		partySize++;
		healers++;
	}
}
int Party::getHealerNumber()
{
	return healers;
}
int Party::getHealerStrength()
{
	int strength = 0;
	for (size_t i = 0; i < maxPartySize; i++)
	{
		strength = strength + (healerList[i].getHealingPower() * (healerList[i].getManaAmount() / healerList[i].getMaxManaAmount()));
	}
	return strength;
}
int Party::getTotalPartyChance()
{
	int totalChance = 0;
	for (size_t i = 0; i < maxPartySize; i++)
	{
		totalChance = totalChance + party[i]->checkSuccessrate();
	}
	return totalChance;
}

int Party::getMaxSize()
{
	cout << maxPartySize << endl;
	return maxPartySize;
}

void Party::healParty(int healpoints)
{
	int mana = healpoints / 2;
	int numberOfAvailableHeals = 0;
	int damageAmount = 0;
	cout << "test" << endl;
	for (size_t i = 0; i < partySize; i++)
	{
		damageAmount = damageAmount + (party[i]->maxHealth - party[i]->health);
	}
	if (damageAmount==0)
	{
		if (healers>0)
		{
			for (size_t i = 0; i < healers; i++)
			{
				if (healerList[i].getManaAmount() > 0)
				{
					numberOfAvailableHeals++;
					healerList[i].useMana(mana / healers);
				}
				else 
				{
					cout << healerList[i].name << " doesn't have enough mana to heal" << endl;
				}
			}
			for (size_t i = 0; i < partySize; i++)
			{
				party[partySize]->heal(healpoints * (numberOfAvailableHeals / healers));
			}
		}
		else 
		{
			cout << "You have no healers" << endl;
		}
	}
	
	
}
