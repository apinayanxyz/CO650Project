#pragma once
#include "Party.h";
class Dungeons
{
private:
	int dungeonDifficulty;
	int maxGoldReward;
public:
	//Constructor
	Dungeons();

	int dungeonClearChance(int partyChance);
	bool adventureCleared(int partyChance,int healerStrength);
	bool miningCleared(int partyChance, int minerStrength);
	bool dungeonCrawlingCleared(int partyChance, int mageStrength);
	int reward(bool dungeonCleared,Party party);
};

