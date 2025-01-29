#pragma once
#include "Party.h";
class Dungeons
{
private:
	int dungeonDifficulty;
	int maxGoldReward;
	int chance;
	int number;
	int strength;
public:
	//Constructor
	Dungeons();

	//Functional pointers used
	bool dungeonClearChance(int chance);
	void dungeonAttempt(int(Party::*partyChance)(), int(Party::*partyNumber)(), int(Party::*partyStrength)(), int choice,Party *party);
	bool adventureAttempt(int partyChance, int mageStrength);
	bool miningAttempt(int partyChance,int miningStrength);
	bool dungeonCrawlingAttempt(int partyChance,int healingStrength);

	void levelUpDungeon();
	int reward(bool dungeonCleared,Party party);
};

