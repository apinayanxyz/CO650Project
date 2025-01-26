#include "Dungeons.h"
#include "Party.h"

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
