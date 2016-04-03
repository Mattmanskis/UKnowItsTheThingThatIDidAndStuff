#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
//getNumber is used when the player needs to imput a number
int GetNumber()
{
    int x;
    cout <<"Enter a number ";
    cin >>x;
    return x;
}
void StartText ()
{
    cout << "Hello Welcome to Zombie Simulator 2016, by !" << endl;
    cout << "This is the difinitave version of Z. Simulator," <<endl;
    cout << "Now with more zombies, health, and damage!" <<endl;
    cout << "Before you can kick zombie ass you need to"<<endl;
    cout << "Set the amount of health and damage you have" <<endl;
    cout << "You can only set 150 points total, and must have" <<endl;
    cout << "At least 25 points in each, so spend carfully!" <<endl;
}
string GetName ()
{
    cout << "First please enter your name: ";
    string pName;
    cin >>pName;
    cout << "Ok, thanks" << pName <<endl <<endl;
    return pName;
}
int GetHealth ()
{
    int health;
    do
    {
    cout <<"Now enter your health" <<endl;
    health = GetNumber();
    cout << "Ok, your health is " <<health <<endl <<endl;
    } while (health <25 || health >125);
    return health;
}
int GetDamage (int health)
{
    int damage;
    do
    {
    cout << "Now enter your damage" <<endl;
    damage = GetNumber();
    cout << "Ok, your damage is " <<damage <<endl <<endl;
    } while (damage <25 || damage+health >150);
    return damage;
}
bool CheckOk(string pName,int health,int damage)
{
  cout <<"Is this ok? y/n?" <<endl;
  cout <<"Name: " <<pName <<endl;
  cout <<"Health: " <<health <<endl;
  cout <<"Damage: " <<damage << endl;
  string answer;
  cin >> answer;
  if (answer=="y")
      return true;
  else
      return false;
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
int Encounter(int pHealth, int pDamage, string pName, string zName )
{
    srand (time(NULL));
    int rand1=rand() % 8 + 4;
    int rand2=rand() % 10 + 5;
    int zHealth = (120*rand1+rand2)/(1+(125/pDamage));
    int zDamage = ((25*(25/(150-pDamage)))/(rand2/2));
    int damageDone = 0;
    cout <<"Oh Jeez! a " <<zName <<" apeared, looks to me like it has " <<endl;
    cout <<zHealth <<" health and " <<zDamage <<" damage!" <<endl;
    cout <<"do you attack y/n?"<<endl;
    string answer;
    cin >> answer;
    if (answer == "y")
        damageDone = Battle(pDamage, pHealth, pName, zDamage, zHealth, zName, true);
    if (answer != "y")
    {
        cout<<"Attempting sneak..."<<endl;
        if (FiftyFifty()== true)
            cout << "Sneak succesful! You snuck past the " <<zName <<"!!!" <<endl <<endl;
        else
        {
            cout << "Sneak failed! The " <<zName <<" saw you!!!" <<endl;
            damageDone = Battle(pDamage, pHealth, pName, zDamage, zHealth, zName, false);
        }
    }

    return pHealth-damageDone;
}
float GetScore(int startHealth,int endHealth)
{
    float score = (endHealth*1000)/startHealth;
    cout <<"Your score was " <<score <<" out of 1000 possible points!" <<endl ;
    return score;
}

/*main includes most of the game text, health and damage veriables, as well as all
of the operations on them*/
int main()
{
    bool readyToPlay = false;
    StartText();
    string pName=GetName();
    int health=GetHealth();
    int startHealth=health;
    int damage=GetDamage(health);
    readyToPlay=CheckOk(pName,health,damage);
    if (readyToPlay==false)
        return 0;
    health = Encounter(health, damage, pName, "Agressive Zombie");
    cout <<endl <<endl <<"your health is now " <<health <<"..." <<endl;
    if (health <= 0)
    {
        cout<<"You are dead, RIP" <<endl;
        return GetScore(startHealth,health);
    }
    health = Encounter(health, damage, pName, "Mirror Zombie");
    cout <<endl <<endl <<"your health is now " <<health <<"..." <<endl;
    if (health <= 0)
    {
        cout<<"You are dead, RIP" <<endl;
        return GetScore(startHealth,health);
    }
    health = Encounter(health, damage, pName, "Defensive Zombie");
    cout <<endl <<endl <<"your health is now " <<health <<"..." <<endl;
    if (health <= 0)
    {
        cout<<"You are dead, RIP" <<endl;
        return GetScore(startHealth,health);
    }
    health = Encounter(health, damage, pName, "BOSS ZOMBIE");
    cout <<endl <<endl <<"your health is now " <<health <<"..." <<endl;
    if (health <= 0)
    {
        cout<<"You are dead, RIP" <<endl;
        return GetScore(startHealth,health);
    }


    return GetScore(startHealth,health);
}
