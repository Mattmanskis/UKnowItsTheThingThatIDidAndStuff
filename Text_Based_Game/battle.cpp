#include "battle.h"
#include "encounter.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "getvalues.h"
using namespace std;

bool zAlive = true;
int zLevel;
string zName;
int zDamage;
int zHealth;
int zEnergy;
int zDefense;

int CompareAttacks(int pAttack, int zAttack)
{
    if (pAttack==0)
        return 0;
    if (zAttack==0)
        return 10;
    if (pAttack==zAttack)
        return pAttack;
    else
        if (zAttack>pAttack)
            return zAttack+pAttack+1;
        else
            return zAttack+pAttack+4;


}
void CreateZ(int level, string name)
{
    zLevel=level;
    zName=name;
    zAlive=true;
    if(zName=="Agressive Zombie")
    {
        zDamage=5*zLevel/2;
        zHealth=10*zLevel;
        zEnergy=4;
        zDefense=2;
    }
}
void Battle(int level, string name, int attacker)
{
    void CreateZ(int level, string name);
    bool pAlive=true;
    if (attacker < 0) {
        if (attacker == 1)
        {
        zHealth= zHealth-GetDamage()*2;
        cout <<GetName() <<" deals " <<GetDamage()*2 <<" Sneak damage!" <<endl <<endl;
        }
        else {
        SetHealth(zDamage*2);
        cout <<zName <<" deals " <<zDamage*2 <<" Sneak damage!" <<endl <<endl;
        }
    }

    cout <<"Battle started!" <<endl;
    do
    {
        cout<<endl;
        int zAttack;
        int pAttack;
        int roundCount;
        int energy;
        int pDamageDone;
        int zDamageDone;
        if (roundCount>50 || roundCount<0)
        {
            roundCount=0;
            energy=0;
        }
        if (energy==0)
            energy=1;
        else if (energy*2 >= GetEnergy())
            energy=GetEnergy();
        else
            energy=energy*2;
        roundCount=roundCount+1;
        cout <<"Round " <<roundCount <<endl <<endl;
        cout <<"Energy is "<<energy <<"/" <<GetEnergy();
        pAttack=GetPAttack(energy);
        cout<<pAttack;
        energy=energy-GetEnergyReq(pAttack-2);
        if (pAttack<7)
        {
            if (pAttack<4)
            {
                if (pAttack == 0)
                {
                    zHealth=zHealth-(pAttack-zDefense);
                    cout<<GetName() <<" uses standard attack!";
                    zDamageDone = (pAttack-zDefense);
                }
                if (pAttack == 2)
                {
                    if(GetHealth() + 5 > GetBaseHealth())
                        SetHealth(-(GetBaseHealth()-GetHealth()));
                    else
                        SetHealth(-5);
                }
            }
        }
        cout<<endl;
    }while (pAlive==zAlive);
    cout<<"Battle over!";
}
