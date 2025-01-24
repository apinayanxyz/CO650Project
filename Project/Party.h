#pragma once
class Party
{
private:
	int partyMembers;
	int healers;
	int miners;
	int mages;
	int gold;
public:
	Party();
	int getHealerStrength();
	int getMinerStrength();
	int getMageStrength();
	int getTotalPartyChance();
	//Friendship
	//Will allow the dungeons class to see how much gold a party has
	friend class Dungeons;

	//Instances of overloading
	int giveGold();
	int giveGold(int amount);
	int recieveGold();
	int recieveGold(int amount);
};