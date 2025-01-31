#include <iostream>
#include "Class.h"
#include "Party.h"
#include "Dungeons.h"
using namespace std;

//Static member
//assigning a max party size using static members 
//is used to modify how a certain person may want others to play the game

int Party::maxPartySize = 10;
Party party;
Dungeons dungeon;
void startGame();
void openMenu();
void addPartyMemberMenu();
void chooseAdventure();
void healParty();
void recoverMana();
void giveGold();

//Exception Handling using Exception Classes (Inheriting from Exception) 
//This execption is thrown when the party size is attempting to suceed or has suceeded the max party size
class MemoryException : public exception {
public:
    MemoryException() { }
    virtual const char* what() const throw() {
        return "You're party is at max size";
    }
};


void startGame() {
    cout << "Welcome to the game" << endl;
    openMenu();
}

void openMenu() {
    cout << "Please choose an option" << endl;
    cout << "- - - - - - -" << endl;
    cout << "1. Print party" << endl;
    cout << "2. Add party member" << endl;
    cout << "3. Attempt an adventure" << endl;
    cout << "4. Heal Party(Costs Gold)" << endl;
    cout << "5. Recover Mana" << endl;
    cout << "6. Give gold" << endl;
    cout << "7. Get gold" << endl;
    cout << "8. Exit" << endl;
    cout << "- - - - - - -" << endl;
    int input;

    //Exception handling
    try {        
        cin >> input;
        if (!cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            switch (input)
            {
            case 1:
                party.printParty();
                openMenu();
                break;
            case 2:
                try
                {
                    if (party.getPartySize()>=10)
                    {
                        throw MemoryException();
                    }
                    else {
                        addPartyMemberMenu();
                    }
                }
                catch (MemoryException e) {
                    cout << "Exception : " << e.what() << endl;
                    openMenu();
                }
                break;
            case 3:
                chooseAdventure();
                break;
            case 4:
                healParty();
                break;
            case 5:
                recoverMana();
                break;
            case 6:
                giveGold();
            default:
                cout << "Exiting" << endl;
                exit(0);
                break;
            }
        }
        else {
            throw (input);
        }
    }
    catch (int myNum) {
        cout << "You have not entered a number" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        openMenu();
    }
        
}

void addPartyMemberMenu() {
    cout << "---" << endl;
    cout << "Which type of adveturer would you like in your party" << endl;
    cout << "- - - - - - -" << endl;
    cout << "1. Healer (Used for Dungeon Crawling)" << endl;
    cout << "2. Mage (Used for OverWorld Adventuring)" << endl;
    cout << "3. Miner (Used for Mining)" << endl;
    cout << "4. Exit" << endl;
    cout << "- - - - - - -" << endl;
    int input;
    try {
        cin >> input;
        if (!cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter a name" << endl;
            string name;
            cin >> name;
            cin.clear();
            cin.ignore(1000, '\n');
            switch (input)
            {
            case 1:
                party.addHealer(name);
                openMenu();
                break;
            case 2:
                party.addMage(name);
                openMenu();
                break;
            case 3:
                party.addMiner(name);
                openMenu();
                break;
            default:
                cout << "Exiting" << endl;
                openMenu();
                break;
            }
        }
        else {
            throw (input);
        }
    }
    catch (int myNum) {
        cout << "You have not entered a number" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        addPartyMemberMenu();
    }
}

void chooseAdventure() {
    cout << "---" << endl;
    cout << "Which adventure would you like to do" << endl;
    cout << "- - - - - - -" << endl;
    cout << "1. Dungeon Crawling (Healers needed)" << endl;
    cout << "2. OverWorld Adventuring (Mage needed)" << endl;
    cout << "3. Mining (Miner needed)" << endl;
    cout << "4. Exit" << endl;
    cout << "- - - - - - -" << endl;
    int (Party:: * chance)();
    int (Party:: * number)();
    int (Party:: * strength)();
    int(Dungeons:: * test)();
    int input;
    try {
        cin >> input;
        if (!cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            switch (input)
            {
            case 1:
                chance = &Party::getTotalPartyChance;
                number = &Party::getHealerNumber;
                strength = &Party::getHealerStrength;
                dungeon.dungeonAttempt(chance, number, strength, 1, &party);
                openMenu();
                break;
            case 2:
                chance = &Party::getTotalPartyChance;
                number = &Party::getMageNumber;
                strength = &Party::getMageStrength;
                dungeon.dungeonAttempt(chance, number, strength, 2, &party);
            case 3:
                chance = &Party::getTotalPartyChance;
                number = &Party::getMinerNumber;
                strength = &Party::getMinerStrength;
                dungeon.dungeonAttempt(chance, number, strength, 3, &party);
                break;
            default:
                cout << "Exiting" << endl;
                openMenu();
                break;
            }
        }
        else {
            throw (input);
        }
    }
    catch (int myNum) {
        cout << "You have not entered a number" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        chooseAdventure();
    }
}

void healParty(){
    cout << "---" << endl;
    cout << "How much do you want to heal by" << endl;
    cout << "(Healing costs gold)" << endl;
    int input;
    try
    {
        cin >> input; 
        if (!cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            party.healParty(input);
        }
        else {
            throw (input);
        }
    }
    catch (int myNum)
    {
        cout << "You have not entered a number" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        openMenu();
    }
}
void recoverMana() {
    cout << "---" << endl;
    cout << "How much mana do you want to recover" << endl;
    int input;
    try
    {
        cin >> input;
        if (!cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            party.restoreMana(input);
        }
        else {
            throw (input);
        }
    }
    catch (int myNum)
    {
        cout << "You have not entered a number" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        openMenu();
    }
}
void giveGold() {
    cout << "----" << endl;
    cout << "Do you wish to give a set amount of gold" << endl;
    string input;
    cin >> input;
    cin.clear();
    cin.ignore(1000, '\n');
    if (input=="yes"||input=="Yes"||input=="y"){}
    {
        int input2;
        try
        {
            cout << "Enter your amount" << endl;
            cin >> input2;
            if (!cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                party.giveGold(input2);
            }
            else {
                throw (input);
            }
        }
        catch (string myString)
        {
            cout << "You have not entered a number" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            giveGold();
        }
        openMenu();
    }
    if (input == "no" || input == "No" || input == "n")
    {
        openMenu();
    }
    else {
        openMenu();
    }
}
void getGold() {
    cout << "----" << endl;
    cout << "Do you wish to get a set amount of gold" << endl;
    string input;
    cin >> input;
    cin.clear();
    cin.ignore(1000, '\n');
    if (input == "yes" || input == "Yes" || input == "y") {}
    {
        cout << "Enter your amount" << endl;
        int input2;
        try
        {
            cin >> input2;
            if (!cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                party.recieveGold(input2);
            }
            else {
                throw (input);
            }
        }
        catch (int myNum)
        {
            cout << "You have not entered a number" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            getGold();
        }
        openMenu();
    }
    if (input == "no" || input == "No" || input == "n")
    {
        party.recieveGold();
        openMenu();
    }
    else {
        openMenu();
    }
}
int main()
{   
    startGame();

}

