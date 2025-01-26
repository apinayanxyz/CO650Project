#include "Party.h"
#include "Class.h"
#include "Miner.h"
#include "Mage.h"
#include "Healer.h"
#include <iostream>
using namespace std;
Party::Party()
{
	party = new Class[maxPartySize];
	minerList = new Miner[maxPartySize];
	healerList = new Healer[maxPartySize];
	mageList = new Mage[maxPartySize];
	partySize = 0;
	healers = 0;
	miners = 0;
	mages = 0;
}
void Party::addMiner(string name)
{
	if (partySize<maxPartySize)
	{
		Miner tester = Miner(name);

		Miner* i ;

		i = &tester;
		party[partySize] = *i;
		minerList[miners] = *i;
		partySize++;
		miners++;
	}
}
void Party::addMage(string name)
{
	if (partySize < maxPartySize)
	{
		Mage mage = Mage(name);

		Mage* mageP;

		mageP = &mage;
		party[partySize] = *mageP;
		mageList[mages] = *mageP;
		partySize++;
		mages++;
	}
}
void Party::addHealer(string name)
{
	if (partySize < maxPartySize)
	{
		Healer healer = Healer(name);

		Healer* healerP;

		healerP = &healer;
		party[partySize] = *healerP;
		healerList[healers] = *healerP;
		partySize++;
		healers++;
	}
}
int Party::getTotalPartyChance()
{
	int totalChance = 0;
	for (size_t i = 0; i < maxPartySize; i++)
	{
		totalChance = totalChance + party[i].checkSuccessrate();
	}
	return totalChance;
}

int Party::getMaxSize()
{
	cout << maxPartySize << endl;
	return maxPartySize;
}
