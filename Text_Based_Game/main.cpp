#include <iostream>
#include "getvalues.h"
#include "encounter.h"
using namespace std;
string zNames[5]{"Slime","Agressive Zombie","Boney Zombie","Giant Zombie","Sad Zombie"};
int zExperiance[5]{10,15,20,25,30};
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
    bool gameOver = false;
    do
    {
        int level= GetLevel();
        if (level > 9)
        {
            cout<<"Your stats are:"<<endl<<endl;
            GetStats();
            if (CheckOk("Are you ready to fight the boss?")==true)
            {
                pAlive=Encounter(level, "Boss Zombie");
                if (pAlive== true)
                    gameOver==true;
            }
        }
        int zNumber = RandomNumber(GetLevel()-1,GetLevel()+1);
        pAlive=Encounter(level, zNames[zNumber]);
        if (GetHealth()==0)
            pAlive=false;
        else
        LevelUp(zExperiance[zNumber]);
    }while (pAlive==true && gameOver==false);
    if (gameOver==true)
    {
        cout<<"Congradulations! You beat the game"<<endl<<endl;
    }
    else
    {
        cout<<"You died"<<endl<<endl;
    }
    cout<<"Your final score was: ";
    return 0;
}
