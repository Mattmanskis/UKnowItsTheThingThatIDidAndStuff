#include <iostream>
#include <tgmath.h>
#include "getvalues.h"
using namespace std;

int baseHealth;
int baseDamage;
int baseEnergy;
string pName;
double experiance = 0;
double experianceRequired = 10;

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

string GetName ()
{
    cout << "First please enter your name: ";
    string pName;
    cin >>pName;
    cout << "Ok, thanks" << pName <<endl <<endl;
    return pName;
}

void GetStats (int health)
{
    cout<<"level " <<log10 (experianceRequired)<<endl;
    cout<<health <<"/" <<baseHealth <<" health"<<endl;
    cout<<baseDamage <<" damage"<<endl;
    cout<<baseEnergy <<" starting energy"<<endl <<endl;
}
bool FiftyFifty()
{
   srand (time(NULL));
   int x = rand() % 2 + 0;
   if (x==1)
       return true;
   else
       return false;
}

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
int Battle(int pDamage, int pHealth, string pName, int zDamage, int zHealth, string zName, bool pStartAttack)
{
    bool zAlive=true;
    bool pAlive=true;
    bool pStun=false;
    bool zStun=false;
    int pStartHealth=pHealth;
    if (pStartAttack==true) {
        zHealth= zHealth-pDamage*2;
        cout <<pName <<" deals " <<pDamage*2 <<" Sneak damage!" <<endl <<endl;
    }
    else {
        pHealth= pHealth-zDamage*2;
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
            int roundType = CompareAttacks(pAttack, zAttack);
            if (roundType==0)
            {
                pHealth=pHealth-zDamage;
            }
            if (roundType==1)
            {
                pHealth=pHealth-zDamage;
                zHealth=zHealth-pDamage;
            }
            if (roundType==3)
            {
                pHealth=pHealth-zDamage/10;
                zHealth=zHealth-pDamage/10;
            }
            if (roundType==4)
            {
                zHealth=zHealth-pDamage/10;
                pStun=true;
            }
            if (roundType==5)
            {
                pHealth=pHealth-zDamage/10;
                zHealth=zHealth-pDamage;
            }
            if (roundType==6)
            {
                pHealth=pHealth-zDamage/10;
                pStun=true;
            }
            if (roundType==7)
            {
                pHealth=pHealth-zDamage/10;
                zStun=true;
            }
            if (roundType==8)
            {
                pHealth=pHealth-zDamage;
                zHealth=zHealth-pDamage/10;
            }
            if (roundType==9)
            {
                zHealth=zHealth-pDamage/10;
                zStun=true;
            }
            if (roundType==10)
            {
                zHealth=zHealth-pDamage;
            }
            if (zAttack==0)
                cout <<zName <<" is stunned and does nothing..."<<endl;
            if (zAttack==1)
                cout <<zName <<" attacks!"<<endl;
            if (zAttack==2)
                cout <<zName <<" blocks!"<<endl;
            if (zAttack==3)
                cout <<zName <<" gaurd-breaks!"<<endl;
            if (pAttack==0)
                cout <<pName <<" is stunned and does nothing..."<<endl;
            if (pAttack==1)
                cout <<pName <<" attacks!"<<endl;
            if (pAttack==2)
                cout <<pName <<" blocks!"<<endl;
            if (pAttack==3)
                cout <<pName <<" gaurd-breaks!"<<endl;
            if (zStun==true)
                cout <<zName <<" is stuned!"<<endl;
            if (pStun==true)
                cout <<pName <<" is stuned!"<<endl;
            if (zHealth<=0)
            {
                zAlive=false;
                zHealth=0;
            }
            if (pHealth<=0)
            {
                pAlive=false;
                pHealth=0;
            }
            cout<<pName <<" has "<<pHealth <<" health" <<endl;
            cout<<zName <<" has " <<zHealth <<" health" <<endl;
            if (zHealth<=0)
                zAlive=false;
            if (pHealth<=0)
                pAlive=false;
            cout<<endl;

        }while(zAlive==pAlive);
    cout<<"Battle over!";
    return pStartHealth-pHealth;

}

/*Encounter spawns a zombie which the player can fight with until its dead,
 * once zhealth is 0 or less the function ends and returns the amound of
 * health the player had at the end of the fight.
 * health=player health
 * damage=player damage
*/


/*main includes most of the game text, health and damage veriables, as well as all
of the operations on them*/
int main()
{
    bool readyToPlay = false;
    StartText();
    do
    {
    pName=GetName();
    baseHealth=GetHealth();
    baseDamage=GetDamage(baseHealth);
    baseEnergy=GetEnergy(baseHealth,baseDamage);
    GetStats(baseHealth);
    readyToPlay=CheckOk("Is it ok to start with these stats?");
    }while (readyToPlay==false);
    int health = baseHealth;
    health = Encounter(health, baseDamage, pName, "Agressive Zombie");
    cout <<endl <<endl <<"your health is now " <<health <<"..." <<endl;
    if (health <= 0)
    {
        cout<<"You are dead, RIP" <<endl;
        return 0;
    }
    health = Encounter(health, baseDamage, pName, "Mirror Zombie");
    cout <<endl <<endl <<"your health is now " <<health <<"..." <<endl;
    if (health <= 0)
    {
        cout<<"You are dead, RIP" <<endl;
        return 0;
    }
    health = Encounter(health, baseDamage, pName, "Defensive Zombie");
    cout <<endl <<endl <<"your health is now " <<health <<"..." <<endl;
    if (health <= 0)
    {
        cout<<"You are dead, RIP" <<endl;
        return 0;
    }
    health = Encounter(health, baseDamage, pName, "BOSS ZOMBIE");
    cout <<endl <<endl <<"your health is now " <<health <<"..." <<endl;
    if (health <= 0)
    {
        cout<<"You are dead, RIP" <<endl;
        return 0;
    }


    return 0;
}
