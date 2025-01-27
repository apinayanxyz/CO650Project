#pragma once
#include "Party.h";
class Dungeons
{
private:
	int dungeonDifficulty;
	int maxGoldReward;
	int (*chance)();
public:
	//Constructor
	Dungeons();

	//Functional pointers used
	int dungeonClearChance(int (*partyChance)());
	void dungeonAttempt(int(*partyChance)(), int choice,Party party);
	void adventureAttempt(int(*partyChance)(), int MageStrength);
	bool miningAttempt(int (*partyChance)(),int miningStrength);
	bool dungeonCrawlingAttempt(int (*partyChance)(),int healingStrength);

	void levelUpDungeon();
	int reward(bool dungeonCleared,Party party);
};

