#include "Party.h"
#include "Class.h"
#include "Miner.h"
#include "Mage.h"
#include "Healer.h"
#include <iostream>
using namespace std;
Party::Party()
{
	//Pointers
	//party is an array of pointers
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
	cout << "---" << endl;
	printGold();
	for (size_t i = 0; i < partySize; i++)
	{	
		Class* p;
		p = (party[i]);
		p->print();
	}
}

void Party::setGold(int gold)
{
	this->gold = gold;
}

int Party::getGold()
{
	return gold;
}

void Party::printGold()
{
	cout << "Your party has " << gold << " gold" << endl;
}



void Party::addMiner(string name)
{
	if (partySize<maxPartySize)
	{
		//Memory management
		//Uses a pointer(which is stored on the stack) to point to the adress of a value that is stored on the heap(within the array)
		Miner* minerP = new Miner(name);
		minerList[miners] = *minerP;
		party[partySize] = &minerList[miners];
		miners++;
		partySize++;
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
		//Memory management
		//Uses a pointer(which is stored on the stack) to point to the adress of a value that is stored on the heap(within the array)
		Mage* mageP = new Mage(name);
		mageList[mages] = *mageP;
		party[partySize] = &mageList[mages];
		mages++;
		partySize++;
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
		//Memory management
		//Uses a pointer(which is stored on the stack) to point to the adress of a value that is stored on the heap(within the array)
		Healer* healerP = new Healer(name);
		healerList[healers] = *healerP;
		party[partySize] = &healerList[healers];
		healers++;
		partySize++;
		
		
	}
}
int Party::getHealerNumber()
{
	return healers;
}
int Party::getHealerStrength()
{
	int strength = 0;
	for (size_t i = 0; i < healers; i++)
	{
		strength = strength + (healerList[i].getHealingPower() * (healerList[i].getManaAmount() / healerList[i].getMaxManaAmount()));
	}
	return strength;
}
int Party::getMinerStrength()
{
	int strength = 0;
	for (size_t i = 0; i < miners; i++)
	{
		strength = strength + (minerList[i].getMiningPower());
	}
	return strength;
}
int Party::getMageStrength()
{
	int strength = 0;
	for (size_t i = 0; i < healers; i++)
	{
		strength = strength + (healerList[i].getHealingPower() * (healerList[i].getManaAmount() / healerList[i].getMaxManaAmount()));
	}
	return strength;
}
int Party::getTotalPartyChance()
{
	int totalChance = 0;
	for (size_t i = 0; i < partySize; i++)
	{
		Class* p;
		p = (party[i]);
		totalChance = totalChance + p->checkSuccessrate();
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
	cout << "---" << endl;
	int manaCost = healpoints / 2;
	int numberOfAvailableHeals = 0;
	int damageAmount = 0;
	for (size_t i = 0; i < partySize; i++)
	{
		damageAmount = damageAmount + (party[i]->maxHealth - party[i]->health);
	}
	if (damageAmount>0)
	{
		if (healpoints > getHealerStrength())
		{
			healpoints = getHealerStrength();
		}
		if (damageAmount < healpoints)
		{
			gold = gold - (damageAmount / 2);
		}
		else {

			gold = gold - (healpoints / 2);
		}

		if (healers > 0)
		{
			for (size_t i = 0; i < healers; i++)
			{
				if (healerList[i].getManaAmount() > 0)
				{
					numberOfAvailableHeals++;
					healerList[i].useMana(manaCost / healers);
				}
				else
				{
					cout << healerList[i].name << " doesn't have enough mana to heal" << endl;
				}
			}
			for (size_t i = 0; i < partySize; i++)
			{
				party[i]->heal(healpoints * (numberOfAvailableHeals / healers));
			}
			cout << "---" << endl;
			for (size_t i = 0; i < healers; i++)
			{
				cout << healerList[i].name << " has used " << healerList[i].getManaAmount() << " mana" << endl;
			}
		}
		else
		{
			cout << "You have no healers" << endl;
		}
	}
	else {
		cout << "Your party did not need to heal" << endl;
	}
	
	
}

void Party::restoreMana(int mana)
{
	cout << "---" << endl;
	for (size_t i = 0; i < healers; i++)
	{
		healerList[i].restoreMana(mana);
	}
	for (size_t i = 0; i < mages; i++)
	{
		mageList[i].restoreMana(mana);
	}
}

void Party::levelParty(int levels)
{
	for (size_t i = 0; i < partySize; i++)
	{
		party[i]->levelUp(levels);
	}
}

void Party::damageParty(int damage)
{
	cout << "---" << endl;
	for (size_t i = 0; i < partySize; i++)
	{
		party[i]->damage(damage);
	}
}
