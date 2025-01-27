#include "Dungeons.h"
#include "Party.h"

Dungeons::Dungeons()
{
	dungeonDifficulty = 1;
	maxGoldReward = 100;
}
void Dungeons::dungeonAttempt(int(*partyChance)(),int choice,Party party)
{
	bool succeed;
	chance = partyChance;
	if (choice == 1)
	{
		if (party.healers<=0)
		{
			cout << "You don't have enough healers" << endl;
		}
		else {

		}
	}
	else if(choice == 2) 
	{
		if (party.mages <= 0)
		{
			cout << "You don't have enough mages" << endl;
		}
		else {

		}
	}
	else {
		if (party.miners <= 0)
		{
			cout << "You don't have enough miners" << endl;
		}
		else {

		}
	}

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
