#include <iostream>
#include "getvalues.h"
#include "encounter.h"
using namespace std;
string zNames[5]{"Agressive Zombie","u","y","z","i"};
void StartText ()
{
    cout << "Hello Welcome to Zombie Simulator 2016, by !" << endl;
    cout << "This is the difinitave version of Z. Simulator," <<endl;
    cout << "Now with more zombies, health, and damage!" <<endl;
    cout << "Before you can kick zombie ass you need to"<<endl;
    cout << "Set the amount of health, damage, defence,and energy you have" <<endl;
    cout << "You can only set 20 points total, and must have" <<endl;
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
    InitalizeDefense();
    GetStats();
    readyToPlay=CheckOk("Is it ok to start with these stats?");
    }while (readyToPlay==false);
    bool pAlive = true;
    do
    {
        int level= GetLevel();
        pAlive=Encounter(level, "Agressive Zombie");
        if (GetHealth()==0)
            pAlive=false;
    }while (pAlive=true);
    return 0;
}
