// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Class.h"
#include "Party.h"
using namespace std;

//assigning a max party size using static members 
//is used to modify how a certain person may want others to play the game
int Party::maxPartySize = 10;

int main()
{   
    /*Class test1;
    Class* test =&test1;
    *(test->attack) = *(test->attack) + 1;
    *(test->attack) = *(test->attack) + 1;
    cout << *(test->attack) << endl;
    cout << *(test->attack) << endl;
    test->levelUp(1, test);
    cout << *test->attack << endl;
    test->levelUp(1, test);
    cout << *test->attack << endl;*/

    Party party;
    party.getMaxSize();
    Class test1;
    Class* test = &test1;
    cout << test->attack << endl;
    test->levelUp(10);
    cout << test->attack << endl;
    cout << "Hello World!\n";


    //Class test2 = party.addMiner("test");
    /*Class* test3 = &(party.party[0]);
    cout << test3->attack << endl;
    test3->levelUp(10);
    cout << test3->attack << endl;
    test3->levelUp(10);
    cout << test3->attack << endl;
    test3->heal(100);
    test3->heal(100);
    test3->levelUp(10);
    cout << test3->attack << endl;
    test3->levelUp(10);
    cout << test3->attack << endl;
    cout << "Hello World!\n";*/

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
