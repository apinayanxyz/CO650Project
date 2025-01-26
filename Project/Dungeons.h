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

	int dungeonClearChance(int (*partyChance));
	bool adventureAttempt(int (*partyChance));
	bool miningAttempt(int (*partyChance));
	bool dungeonCrawlingAttempt(int (*partyChance));

	void levelUpDungeon();
	int reward(bool dungeonCleared,Party party);
};

