#include "Party.h"
#include "Class.h"
#include "Miner.h"
#include "Mage.h"
#include "Healer.h"
#include <iostream>
#include "stdafx.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include "iostream"

using namespace std;
Party::Party()
{
	party = new Class*[maxPartySize];
	minerList = new Miner[maxPartySize];
	healerList = new Healer[maxPartySize];
	mageList = new Mage[maxPartySize];
	partySize = 0;
	healers = 0;
	miners = 0;
	mages = 0;
	gold = 100;
}
void Party::printParty()
{
	cout << "---" << endl;
	printGold();
	for (size_t i = 0; i < partySize; i++)
	{	
		Class* p;
		p = (party[i]);
		p->print();
	}
}

void Party::setGold(int gold)
{
	this->gold = gold;
}

int Party::getGold()
{
	return gold;
}

void Party::printGold()
{
	cout << "Your party has " << gold << " gold" << endl;
}

void Party::addMiner(string name)
{
	if (partySize<maxPartySize)
	{
		//Memory management
		//Uses a pointer(which is stored on the stack) to point to the adress of a value that is stored on the heap(within the array)
		Miner* minerP = new Miner(name);
		minerList[miners] = *minerP;
		party[partySize] = &minerList[miners];
		miners++;
		partySize++;
	}
	else {
		cout << "Your party is full" << endl;
	}
}
int Party::getMinerNumber()
{
	return miners;
}
void Party::addMage(string name)
{
	if (partySize < maxPartySize)
	{
		//Memory management
		//Uses a pointer(which is stored on the stack) to point to the adress of a value that is stored on the heap(within the array)
		Mage* mageP = new Mage(name);
		mageList[mages] = *mageP;
		party[partySize] = &mageList[mages];
		mages++;
		partySize++;
	}
	else {
		cout << "Your party is full" << endl;
	}
}
int Party::getMageNumber()
{
	return mages;
}
void Party::addHealer(string name)
{
	if (partySize < maxPartySize)
	{
		//Memory management
		//Uses a pointer(which is stored on the stack) to point to the adress of a value that is stored on the heap(within the array)
		Healer* healerP = new Healer(name);
		healerList[healers] = *healerP;
		party[partySize] = &healerList[healers];
		healers++;
		partySize++;
	}
	else {
		cout << "Your party is full" << endl;
	}
}
int Party::getHealerNumber()
{
	return healers;
}
int Party::getHealerStrength()
{
	int strength = 0;
	for (size_t i = 0; i < healers; i++)
	{
		strength = strength + (healerList[i].getHealingPower() * (healerList[i].getManaAmount() / healerList[i].getMaxManaAmount()));
	}
	return strength;
}
int Party::getMinerStrength()
{
	int strength = 0;
	for (size_t i = 0; i < miners; i++)
	{
		strength = strength + (minerList[i].getMiningPower());
	}
	return strength;
}
int Party::getMageStrength()
{
	int strength = 0;
	for (size_t i = 0; i < healers; i++)
	{
		strength = strength + (healerList[i].getHealingPower() * (healerList[i].getManaAmount() / healerList[i].getMaxManaAmount()));
	}
	return strength;
}
int Party::getTotalPartyChance()
{
	int totalChance = 0;
	for (size_t i = 0; i < partySize; i++)
	{
		Class* p;
		p = (party[i]);
		totalChance = totalChance + p->checkSuccessrate();
	}
	return totalChance;
}

int Party::getMaxSize()
{
	return maxPartySize;
}

int Party::getPartySize()
{
	return partySize;
}

void Party::healParty(int healpoints)
{
	cout << "---" << endl;
	cout << "Healing party" << endl;
	int manaCost = healpoints / 2;
	int numberOfAvailableHeals = 0;
	int damageAmount = 0;
	for (size_t i = 0; i < partySize; i++)
	{
		damageAmount = damageAmount + (party[i]->maxHealth - party[i]->health);
	}
	if (damageAmount>0)
	{
		if (healpoints > getHealerStrength())
		{
			healpoints = getHealerStrength();
		}
		if (damageAmount < healpoints)
		{
			gold = gold - (damageAmount / 2);
		}
		else {

			gold = gold - (healpoints / 2);
		}

		if (healers > 0)
		{
			for (size_t i = 0; i < healers; i++)
			{
				if (healerList[i].getManaAmount() > 0)
				{
					numberOfAvailableHeals++;
					healerList[i].useMana(manaCost / healers);
				}
				else
				{
					cout << healerList[i].name << " doesn't have enough mana to heal" << endl;
				}
			}

			cout << "" << endl;
			for (size_t i = 0; i < partySize; i++)
			{
				party[i]->heal(healpoints * (numberOfAvailableHeals / healers));
			}
		}
		else
		{
			cout << "You have no healers" << endl;
		}
	}
	else {
		cout << "Your party did not need to heal" << endl;
	}
	
	
}

void Party::restoreMana(int mana)
{
	cout << "---" << endl;
	for (size_t i = 0; i < healers; i++)
	{
		healerList[i].restoreMana(mana);
	}
	for (size_t i = 0; i < mages; i++)
	{
		mageList[i].restoreMana(mana);
	}
}

void Party::levelParty(int levels)
{
	for (size_t i = 0; i < partySize; i++)
	{
		party[i]->levelUp(levels);
	}
}

void Party::damageParty(int damage)
{
	cout << "---" << endl;
	for (size_t i = 0; i < partySize; i++)
	{
		party[i]->damage(damage);
	}
}

int Party::giveGold()
{
	SOCKET clientSocket;
	int port = 55555;
	WSADATA wsaData;
	int wsaerr;
	WORD wVersionRequested = MAKEWORD(2, 2);
	wsaerr = WSAStartup(wVersionRequested, &wsaData);
	if (wsaerr != 0) {
		cout << "The Winsock dll not found!" << endl;
		return 0;
	}
	else {
		cout << "The Winsock dll found!" << endl;
		cout << "The status: " << wsaData.szSystemStatus << endl;
	}

	clientSocket = INVALID_SOCKET;
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		cout << "Error at socket(): " << WSAGetLastError() << endl;
		WSACleanup();
		return 0;
	}
	else {
		cout << "socket() is OK!" << endl;
	}

	sockaddr_in clientService;
	clientService.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);
	if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
		cout << "Client: connect() - Failed to connect." << endl;
		WSACleanup();
		return 0;
	}
	else {
		cout << "Client: connect() is OK." << endl;
		cout << "Client: Can start sending and receiving data..." << endl;
	}


	int globalGold;
	int byteCount = SOCKET_ERROR;
	byteCount = recv(clientSocket, (char*)&globalGold, sizeof(globalGold), 0);
	if (byteCount == 0 || byteCount == WSAECONNRESET) {
		cout << "Client: Connection Closed." << endl;
	}
	if (byteCount < 0) {
		cout << "Client: error " << WSAGetLastError() << endl;
	}
	else {
		cout << globalGold << endl;
		globalGold = globalGold +(gold/10);
		gold = gold - (gold / 10);
		send(clientSocket, (char*)&globalGold, sizeof(globalGold), 0);

	}
	WSACleanup();
	return 0;
}
int Party::giveGold(int amount)
{
	SOCKET clientSocket;
	int port = 55555;
	WSADATA wsaData;
	int wsaerr;
	WORD wVersionRequested = MAKEWORD(2, 2);
	wsaerr = WSAStartup(wVersionRequested, &wsaData);
	if (wsaerr != 0) {
		cout << "The Winsock dll not found!" << endl;
		return 0;
	}
	else {
		cout << "The Winsock dll found!" << endl;
		cout << "The status: " << wsaData.szSystemStatus << endl;
	}

	clientSocket = INVALID_SOCKET;
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		cout << "Error at socket(): " << WSAGetLastError() << endl;
		WSACleanup();
		return 0;
	}
	else {
		cout << "socket() is OK!" << endl;
	}

	sockaddr_in clientService;
	clientService.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);
	if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
		cout << "Client: connect() - Failed to connect." << endl;
		WSACleanup();
		return 0;
	}
	else {
		cout << "Client: connect() is OK." << endl;
		cout << "Client: Can start sending and receiving data..." << endl;
	}


	int globalGold;
	int byteCount = SOCKET_ERROR;
	byteCount = recv(clientSocket, (char*)&globalGold, sizeof(globalGold), 0);
	if (byteCount == 0 || byteCount == WSAECONNRESET) {
		cout << "Client: Connection Closed." << endl;
	}
	if (byteCount < 0) {
		cout << "Client: error " << WSAGetLastError() << endl;
	}
	else {
		cout << globalGold << endl;
		globalGold = globalGold + amount;
		gold = gold - amount;
		send(clientSocket, (char*)&globalGold, sizeof(globalGold), 0);

	}
	WSACleanup();
	return 0;
}

int Party::recieveGold()
{
	SOCKET clientSocket;
	int port = 55555;
	WSADATA wsaData;
	int wsaerr;
	WORD wVersionRequested = MAKEWORD(2, 2);
	wsaerr = WSAStartup(wVersionRequested, &wsaData);
	if (wsaerr != 0) {
		cout << "The Winsock dll not found!" << endl;
		return 0;
	}
	else {
		cout << "The Winsock dll found!" << endl;
		cout << "The status: " << wsaData.szSystemStatus << endl;
	}

	clientSocket = INVALID_SOCKET;
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		cout << "Error at socket(): " << WSAGetLastError() << endl;
		WSACleanup();
		return 0;
	}
	else {
		cout << "socket() is OK!" << endl;
	}

	sockaddr_in clientService;
	clientService.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);
	if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
		cout << "Client: connect() - Failed to connect." << endl;
		WSACleanup();
		return 0;
	}
	else {
		cout << "Client: connect() is OK." << endl;
		cout << "Client: Can start sending and receiving data..." << endl;
	}


	int globalGold;
	int byteCount = SOCKET_ERROR;
	byteCount = recv(clientSocket, (char*)&globalGold, sizeof(globalGold), 0);
	if (byteCount == 0 || byteCount == WSAECONNRESET) {
		cout << "Client: Connection Closed." << endl;
	}
	if (byteCount < 0) {
		cout << "Client: error " << WSAGetLastError() << endl;
	}
	else {
		cout << "You attempted to take "<<globalGold<< " gold"<< endl;
		gold = gold +globalGold;
		globalGold = 0;
		send(clientSocket, (char*)&globalGold, sizeof(globalGold), 0);

	}
	WSACleanup();
	return 0;
}
int Party::recieveGold(int amount)
{
	SOCKET clientSocket;
	int port = 55555;
	WSADATA wsaData;
	int wsaerr;
	WORD wVersionRequested = MAKEWORD(2, 2);
	wsaerr = WSAStartup(wVersionRequested, &wsaData);
	if (wsaerr != 0) {
		cout << "The Winsock dll not found!" << endl;
		return 0;
	}
	else {
		cout << "The Winsock dll found!" << endl;
		cout << "The status: " << wsaData.szSystemStatus << endl;
	}

	clientSocket = INVALID_SOCKET;
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		cout << "Error at socket(): " << WSAGetLastError() << endl;
		WSACleanup();
		return 0;
	}
	else {
		cout << "socket() is OK!" << endl;
	}

	sockaddr_in clientService;
	clientService.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);
	if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
		cout << "Client: connect() - Failed to connect." << endl;
		WSACleanup();
		return 0;
	}
	else {
		cout << "Client: connect() is OK." << endl;
		cout << "Client: Can start sending and receiving data..." << endl;
	}


	int globalGold;
	int byteCount = SOCKET_ERROR;
	byteCount = recv(clientSocket, (char*)&globalGold, sizeof(globalGold), 0);
	if (byteCount == 0 || byteCount == WSAECONNRESET) {
		cout << "Client: Connection Closed." << endl;
	}
	if (byteCount < 0) {
		cout << "Client: error " << WSAGetLastError() << endl;
	}
	else {
		cout << "You attempted to take " << amount << " gold"<<  endl;
		gold = gold + amount;
		globalGold = globalGold-amount;
		send(clientSocket, (char*)&globalGold, sizeof(globalGold), 0);

	}
	WSACleanup();
	return 0;
}