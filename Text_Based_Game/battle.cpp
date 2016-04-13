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
int zBaseDamage;
int zHealth;
int zBaseHealth;
int zEnergy;
int zBaseDefense;

void CreateZ(int level, string name)
{
    zLevel=level;
    zName=name;
    zAlive=true;
    if(zName=="Agressive Zombie")
    {
        zBaseDamage=5*zLevel/2;
        zBaseHealth=30*zLevel;
        zEnergy=4;
        zBaseDefense=2;
    }
    zHealth=zBaseHealth;
}
void Battle(int level, string name, int attacker)
{
    CreateZ(level,name);
    bool pAlive=true;
    if (attacker < 0) {
        if (attacker == 1)
        {
        zHealth= zHealth-GetDamage()*2;
        cout <<GetName() <<" deals " <<GetDamage()*2 <<" Sneak damage!" <<endl <<endl;
        }
        else {
        SetHealth(zBaseDamage*2);
        cout <<zName <<" deals " <<zBaseDamage*2 <<" Sneak damage!" <<endl <<endl;
        }
    }

    cout <<"Battle started!" <<endl;
    int cooldownArray[5]={0,0,0,0,0};
    do
    {
        cout<<endl;
        int zAttack = 0;
        int pAttack = 0;
        int pDamage = GetDamage();
        int zDamage = zBaseDamage;
        int zDefense = zBaseDefense;
        int pDefense = GetDefense();
        int roundCount;
        int energy;
        int pDamageDone = 0;
        int zDamageDone = 0;
        if (cooldownArray[0]>0)
        {
            pDefense=GetDefense()+2;
            cooldownArray[0]=cooldownArray[0]-1;
        }
        if (cooldownArray[3]>0)
        {
            pDamage=GetDamage()/2;
            zDamage=zBaseDamage/2;
            cooldownArray[3]=cooldownArray[3]-1;
        }

        if (cooldownArray[1]>0)
        {
            pDamage=pDamage+2;
            cooldownArray[1]=cooldownArray[1]-1;
        }
        if (cooldownArray[2]>0)
        {
            zDefense=zBaseDefense-3;
            zDamage=zDamage-2;
            cooldownArray[2]=cooldownArray[2]-1;
        }
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
        cout <<"Round " <<roundCount <<endl;
        if (cooldownArray[4]>0)
        {
         pAttack=11;
         cooldownArray[4]=0;
        }
        else
            pAttack=GetPAttack(energy);
        energy=energy-GetEnergyReq(pAttack-2);
        if (pAttack<7)
        {
            if (pAttack<4)
            {
                if (pAttack == 0)
                {
                    zDamageDone = (pDamage-zDefense);
                    cout<<GetName() <<" uses standard attack!"<<endl;
                }
                else if (pAttack == 2)
                {
                    cout<<GetName() <<" uses Heal, healing 5 points of damage!";
                    if(GetHealth() + 5 > GetBaseHealth())
                        SetHealth(-(GetBaseHealth()-GetHealth()));
                    else
                        SetHealth(-5);
                }
                else if (pAttack == -1)
                {
                    cout<<GetName() <<" tries to run!";
                    bool tf1 = FiftyFifty();
                    bool tf2 = FiftyFifty();
                    if (tf1==true && tf2==true)
                    {
                        cout<<"Run sucess!";
                    }
                    else
                        cout<<"Run failed!";
                }
            }
            else
            {
                if (pAttack==4)
                {
                    cout<<GetName()<<" used Iron Skin!" <<endl; "Player defense increased for 5 rounds!";
                    cooldownArray[0]=5;
                }
                else if (pAttack==5)
                {
                    cout<<GetName()<<" used Prayer to the old gods!" <<endl <<"Player damage increased for 3 rounds";
                    cooldownArray[1]=3;
                }
                else if (pAttack==6)
                {
                    cout<<GetName()<<" used Ethral scream!"<<endl<<"Enemy attack and defense significnatly decreased next 2 rounds";
                    cooldownArray[2]=2;
                }
            }
        }
        else
        {
                if(pAttack==7)
                {
                    cout<<GetName()<<" used Blood curse" <<endl<<"Trade 1/5 of your health to do double damage to your enemy";
                    SetHealth(GetHealth()/5);
                    zDamageDone=GetHealth()*2/5;
                }
                else if(pAttack==8)
                {
                    cout<<GetName()<<" used Darkness falls!" <<endl<<"All base damage is halved for 5 rounds!";
                    cooldownArray[3]=5;
                }
                else if(pAttack==9)
                {
                    cout<<GetName()<<" used Damage bank!" <<endl <<GetName() <<" stores energy...";
                    cooldownArray[4]=1;
                }
                else if(pAttack==10)
                {
                    cout<<GetName()<<" used Great heal" <<endl <<GetName() <<" healed 15 points of health ";
                    if(GetHealth() + 15 > GetBaseHealth())
                        SetHealth(-(GetBaseHealth()-GetHealth()));
                    else
                        SetHealth(-15);
                }
                else if(pAttack==11)
                {
                    cout<<GetName() <<" unleashes energy for masive damage!";
                    zDamageDone=(pDamage*2)-zDefense;
                }
        }
        if (pAttack==1)
        {
            pDamageDone=pDamageDone/5;
        }
        zHealth=zHealth-zDamageDone;
        cout <<GetName() <<"'s health is " <<GetHealth() <<"/" <<GetBaseHealth()<<endl;
        cout <<zName <<"'s health is " <<zHealth <<"/" <<zBaseHealth <<endl;
        cout<<endl;
    }while (pAlive==zAlive);
    cout<<"Battle over!";
}
