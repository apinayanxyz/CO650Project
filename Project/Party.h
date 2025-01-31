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
	//Pointers
	//party is an array of pointers
	//allows for these lists to point to the same object as they hold the same pointer value

	//Memory management within classes
	//These arrays store pointers, which are stored on the stack, to objects that are sotred on the heap
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
	//is used to set the maximum amount of party members a player is allowed to have
	static int maxPartySize;

	//Constructor
	Party();

	void printParty();
	void setGold(int gold);
	void printGold();
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
	int getPartySize();
	int getGold();


	void healParty(int healpoints);
	void restoreMana(int mana);
	void levelParty(int levels);
	void damageParty(int damage);


	//Friendship
	//Will allow the dungeons class to see how much gold a party has
	friend class Dungeons;

	//Instances of overloading
	//If a set amount isn't given, 10% of gold will be given and all gold will be gained
	int giveGold();
	int giveGold(int amount);
	int recieveGold();
	int recieveGold(int amount);

};