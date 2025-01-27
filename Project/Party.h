#pragma once
#include <iostream>
#include "Class.h"
#include "Miner.h"
#include "Healer.h"
#include "Mage.h"
using namespace std;
class Party
{
private:
	Class** party;
	Miner* minerList;
	Healer* healerList;
	Mage* mageList;

	int partySize;
	int healers;
	int miners;
	int mages;

	int gold;
public:
	//static variable
	static int maxPartySize;

	//Constructor
	Party();

	void printParty();
	void addMiner(string name);
	int getMinerNumber();
	void addMage(string name);
	int getMageNumber();
	void addHealer(string name);
	int getHealerNumber();

	//"Getters"
	int getHealerStrength();
	int getMinerStrength();
	int getMageStrength();
	int getTotalPartyChance();
	int getMaxSize();


	void healParty(int healpoints);
	void restoreMana(int mana);
	void levelParty(int levels);
	void damageParty(int damage);


	//Friendship
	//Will allow the dungeons class to see how much gold a party has
	friend class Dungeons;

	//Instances of overloading
	int giveGold();
	int giveGold(int amount);
	int recieveGold();
	int recieveGold(int amount);

};