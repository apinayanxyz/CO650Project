#include "Dungeons.h"
#include "Party.h"
#include "time.h"

Dungeons::Dungeons()
{
	dungeonDifficulty = 1;
	maxGoldReward = 100;
}
bool Dungeons::dungeonClearChance(int chance)
{
	srand(time(NULL));
	int success = rand() % 100;
	if (success<chance)
	{	cout << "You have cleared this dungeon" << endl;
		return true;
		
	}
	cout << "Your party has not cleared this dungeon" << endl;
	return false;
}

//Function pointers
//The following classes used funciton pointers to grab the function that is being called
//The value of the pointers change with the change in parameter values, meaning the funciton being used changes
void Dungeons::dungeonAttempt(int(Party::*partyChance)(), int(Party::*partyNumber)(), int(Party::*partyStrength)(),int choice,Party party)
{
	bool success;
	chance = (party.*partyChance)();
	number = (party.*partyNumber)();
	strength = (party.*partyStrength)();
	if (choice == 1)
	{
		if (chance<=0)
		{
			cout << "You don't have enough healers" << endl;
		}
		else {
			cout << "Attempting adventure" << endl;
			success = adventureAttempt(chance, strength);
		}
	}
	else if(choice == 2) 
	{
		if (number<= 0)
		{
			cout << "You don't have enough mages" << endl;
		}
		else {
			cout << "Attempting adventure" << endl;
			success = adventureAttempt(chance, strength);
		}
	}
	else {
		if (number<= 0)
		{
			cout << "You don't have enough miners" << endl;
		}
		else {
			cout << "Attempting adventure" << endl;
			success = adventureAttempt(chance, strength);
		}
	}
	cout << "Your party has recieved " << reward(success, party) << " gold" << endl;
	party.gold = party.gold + reward(success, party);
	if (success)
	{
		levelUpDungeon();
		
	}

}


bool Dungeons::adventureAttempt(int partyChance, int mageStrength)
{
	int chance = (partyChance / 4) + mageStrength;
	return dungeonClearChance(chance);
}

bool Dungeons::miningAttempt(int partyChance, int miningStrength)
{
	int chance = partyChance + (miningStrength * (3 / 4));
	return dungeonClearChance(chance);
}

bool Dungeons::dungeonCrawlingAttempt(int partyChance, int healingStrength)
{
	int chance = (partyChance / 2) + (healingStrength / 4);
	return dungeonClearChance(chance);
}


void Dungeons::levelUpDungeon()
{	
	
	dungeonDifficulty++;
	maxGoldReward = maxGoldReward + (maxGoldReward / 10);
}

//using friendship to gain the values and methods of party class
int Dungeons::reward(bool dungeonCleared,Party party)
{
	if (dungeonCleared)
	{
		return maxGoldReward;
	}

	else {
		return (maxGoldReward * (party.getTotalPartyChance() / 100) + (party.gold * party.getTotalPartyChance() / 100)) ;
	}
}
