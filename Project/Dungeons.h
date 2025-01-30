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

	bool dungeonClearChance(int chance);
	//Functional pointers used
	//Allows for the class to only store the functions its going to use while also having access to any other functions as the pointer to the party is used
	void dungeonAttempt(int(Party::*partyChance)(), int(Party::*partyNumber)(), int(Party::*partyStrength)(), int choice,Party *party);
	bool adventureAttempt(int partyChance, int mageStrength);
	bool miningAttempt(int partyChance,int miningStrength);
	bool dungeonCrawlingAttempt(int partyChance,int healingStrength);

	void levelUpDungeon();
	int reward(bool dungeonCleared,Party party);
};

