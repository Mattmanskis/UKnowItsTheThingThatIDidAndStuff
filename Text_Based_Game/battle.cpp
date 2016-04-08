#include "battle.h"
#include "encounter.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "getvalues.h"
using namespace std;

int zLevel;
string zName;
int zDamage;
int zHealth;
int zEnergy;

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
    if(zName=="Agressive Zombie")
    {
        zDamage=5*zLevel/2;
        zHealth=10*zLevel;
        zEnergy=4;
    }
}
void Battle(int level, string name, bool pStartAttack)
{
    bool zAlive=true;
    bool pAlive=true;
    bool pStun=false;
    bool zStun=false;
    int pStartHealth=GetHealth();;
    if (pStartAttack==true) {
        zHealth= zHealth-GetDamage()*2;
        cout <<GetName() <<" deals " <<GetDamage()*2 <<" Sneak damage!" <<endl <<endl;
    }
    else {
        SetHealth(zDamage*2);
        cout <<zName <<" deals " <<zDamage*2 <<" Sneak damage!" <<endl <<endl;
    }

    cout <<"Battle started!" <<endl;
        do
        {
            int zAttack;
            int pAttack;
            cout<<endl;
            if (zName == "Agressive Zombie")
            {
                if (zAttack==0){
                    if(FiftyFifty())
                        zAttack=1;
                    else
                        zAttack=2;
                }
                else
                zAttack = 1;
            }
            if (zName == "Mirror Zombie")
            {
                if (pAttack >= 1 || pAttack <= 3)
                    zAttack = pAttack;
                else
                    zAttack = 1;
            }
            if (zName == "Defensive Zombie")
            {
                if (pAttack==0)
                    zAttack=1;
                if (zAttack==0)
                {
                    if(FiftyFifty())
                        zAttack=1;
                    else
                        zAttack=3;
                }
                else
                    zAttack=2;
            }
            if (zName == "BOSS ZOMBIE")
            {
                int cycle;
                cycle = cycle + 1;
                if (cycle > 0 || cycle <=3)
                    cycle = 0;
                if (cycle == 0)
                {
                    if (zAttack==0){
                        if(FiftyFifty())
                            zAttack=1;
                        else
                            zAttack=2;
                    }
                    else
                    zAttack = 1;
                }
                if (cycle == 1)
                {
                    if (zAttack==0){
                        if(FiftyFifty())
                            zAttack=1;
                        else
                            zAttack=2;
                    }
                    else
                    zAttack = 1;
                }
                if (cycle == 2)
                {
                    if (pAttack==0)
                        zAttack=1;
                    if (zAttack==0)
                    {
                        if(FiftyFifty())
                            zAttack=1;
                        else
                            zAttack=3;
                    }
                    else
                        zAttack=2;
                }

            }
            int roundCount;
            if (roundCount>50 || roundCount<0)
                roundCount=0;
            roundCount=roundCount+1;
            cout <<"Round " <<roundCount <<endl;
            cout <<"which attack do you chose? (1=attack, 2=block, 3=gaurd-break)"<<endl;
            pAttack=GetNumber();
            cout<<endl;
            if (pStun==true)
            {
                pAttack=0;
            }
            if (zStun==true)
            {
                zAttack=0;
            }
            pStun=false;
            zStun=false;
}while (pAlive==zAlive);
    cout<<"Battle over!";
}
