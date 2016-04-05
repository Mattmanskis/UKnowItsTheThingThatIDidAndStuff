#include <iostream>
#include "getvalues.h"
#include "encounter.h"
using namespace std;

void StartText ()
{
    cout << "Hello Welcome to Zombie Simulator 2016, by !" << endl;
    cout << "This is the difinitave version of Z. Simulator," <<endl;
    cout << "Now with more zombies, health, and damage!" <<endl;
    cout << "Before you can kick zombie ass you need to"<<endl;
    cout << "Set the amount of health, damage, and energy you have" <<endl;
    cout << "You can only set 15 points total, and must have" <<endl;
    cout << "At least 3 points in each, so spend carfully!" <<endl;
}

int main()
{
    bool readyToPlay = false;
    StartText();
    do
    {
    InitalizeName();
    InitalizeHealth();
    InitalizeDamage();
    InitalizeEnergy();
    GetStats();
    readyToPlay=CheckOk("Is it ok to start with these stats?");
    }while (readyToPlay==false);
    Encounter(1, "Agressive Zombie");


    return 0;
}
