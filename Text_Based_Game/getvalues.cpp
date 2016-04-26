#include "getvalues.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <tgmath.h>
using namespace std;

int health;
int baseHealth;
int baseDamage;
int baseEnergy;
int baseDefense;
string pName;
double experiance = 0;
double experianceRequired = 10;
int skillsArray[9]={0,0,0,0,0,0,0,0,0};
int energyReq[11]={2,1,3,4,4,2,5,2,9,0,0};
    int GetNumber()
    {
        int x;
        cout <<"Enter a number ";
        cin >>x;
        return x;
    }

    int RandomNumber(int x, int y)
    {
        srand (time(NULL));
        return rand() % y + x;
    }

    void InitalizeName ()
    {
        cout << "First please enter your name: ";
        cin >>pName;
        cout << "Ok, thanks " << pName <<endl <<endl;
    }

    void InitalizeHealth ()
    {
        int x;
        do
        {
        cout <<"Enter your health, must be between 3-11" <<endl;
        x= GetNumber();
        baseHealth=10*x;
        } while (x <3 || x >11);
        cout << "Ok, your health is " <<baseHealth <<endl <<endl;
        health=baseHealth;
    }

    void InitalizeDamage ()
    {
        do
        {
        cout << "Now enter your damage must be between 3 and " <<14-baseHealth/10 <<endl;
        baseDamage = GetNumber();
        } while (baseDamage <3 || baseDamage+baseHealth/10 >14);
        cout << "Ok, your damage is " <<baseDamage <<endl <<endl;
    }

    void InitalizeEnergy ()
    {
        do
        {
            cout << "Now enter your energy, must be between 3 and " <<17-baseHealth/10-baseDamage <<endl;
            baseEnergy = GetNumber();
        } while (baseEnergy <3 || baseDamage+baseHealth/10+baseEnergy >17);
        cout << "Ok, your energy is " <<baseEnergy <<endl <<endl;
    }
    void InitalizeDefense ()
    {
        do
        {
            cout << "Now enter your defense, must be " <<20-baseHealth/10-baseDamage-baseEnergy <<endl;
            baseDefense = GetNumber();
        } while (baseDamage+baseHealth/10+baseEnergy+baseDefense !=20);
        cout << "Ok, your defense is " <<baseDefense <<endl <<endl;
    }
    int GetHealth()
    {
        return health;
    }

    int GetBaseHealth()
    {
        return baseHealth;
    }

    int GetDamage()
    {
        return baseDamage;
    }

    int GetEnergy()
    {
        return baseEnergy;
    }
    int GetDefense()
    {
        int actualDefense = baseDefense/2;
        return actualDefense;
    }
    string GetName()
    {
        return pName;
    }
    int GetLevel()
    {
        return log10 (experianceRequired);
    }
    int GetSkillsArray(int x)
    {
        return skillsArray[x];
    }
    int GetEnergyReq(int x)
    {
        return energyReq[x];
    }

    void GetStats ()
    {
        cout<<"level " <<GetLevel() <<endl;
        cout<<health <<"/" <<baseHealth <<" health"<<endl;
        cout<<baseDamage <<" damage"<<endl;
        cout<<baseEnergy <<" starting energy"<<endl;
        cout<<baseDefense << " defense" <<endl <<endl;
    }

    void SetHealth(int damage)
    {
        health = health - damage;
        if(health<0)
            health=0;
    }
    int SpecialActions(int energy);
    int StandardActions(int energy)
    {
        cout<<"Ok, standard action" <<endl;
        int answer;
        cout << endl <<"1) Attack" <<endl;
        cout <<"2) Block" <<endl;
        cout <<"3) Run" <<endl;
        cout <<"4) Special Actions" <<endl;
        answer=GetNumber();
        cout <<endl;
        if (answer==1)
            return 0;
        else if (answer==2)
            return 1;
        else if (answer==3)
            return -1;
        else if (answer==4)
            return SpecialActions(energy);
    }

    int SpecialActions(int energy)
    {
        cout<<endl<<"Energy is " <<energy <<"/" <<GetEnergy();
        cout<<endl <<endl <<"Chose an action:" <<endl <<endl;
        for(int i=-1; i<10; i++)
        {
            int count=i;
            int x = GetSkillsArray(i);
            if (count==-1)
            {
                    cout<<"0) standard actions -0"<<endl;
            }
            else if (count==0)
            {
                if (x==1)
                    cout<<"1) Heal -2" <<endl;
            }
            else if (count==1)
            {
                if (x==1)
                {
                    cout<<"2) Gaurd Break -1"<<endl;
                }
            }
            else if (count==2)
            {
                if (x==1)
                {
                    cout<<"3) Iron skin -3"<<endl;
                }
            }
            else if (count==3)
            {
                if (x==1)
                {
                    cout<<"4) Prayer to the old gods -4"<<endl;
                }
            }
            else if (count==4)
            {
                if (x==1)
                {
                    cout<<"5) Ethral scream  -4"<<endl;
                }
            }
            else if (count==5)
            {
                if (x==1)
                {
                    cout<<"6) Blood curse -2"<<endl;
                }
            }
            else if (count==6)
            {
                if (x==1)
                {
                    cout<<"7) Darkness falls -5"<<endl;
                }
            }
            else if (count==7)
            {
                if (x==1)
                {
                    cout<<"8) Damage bank - 2"<<endl;
                }
            }
            else if (count==8)
            {
                if (x==1)
                {
                    cout<<"9) Great heal -9"<<endl;
                }
            }
        }
        int number = GetNumber();
        if (number==0)
            StandardActions(energy);
        else if (skillsArray[number-1]==1)
        {
            if (energyReq[number-1] > energy)
            {
                cout<<"Too little energy! Please enter a valid number ";
                SpecialActions(energy);
            }
            else
            return number + 1;
        }
        else
        {
            cout <<number <<" is not a valid number. Please enter a valid number";
            SpecialActions(energy);
        }

    }

    int GetPAttack(int energy)
    {
        return SpecialActions(energy);
    }



    bool CheckOk(string text)
    {
      string answer;
      cout <<endl <<text << endl <<"y/n?" <<endl;
      cin >> answer;
      cout <<endl;
      if (answer=="y")
          return true;
      else
          return false;
    }

    void LevelUp(int experianceGained)
    {
        experiance=experiance+experianceGained;
        if (experiance>=experianceRequired)
        {
            experianceRequired=experianceRequired*10;
            cout<<"You leveled up!"<<endl<<endl;
            cout<<"Your stats are:"<<endl<<endl;
            GetStats();
            cout<<"You have 4 points you can put into any stat"<<endl;
            int pointsLeft = 4;
            bool centinue = true;
            do
            {
            cout<<"How many points would you like to put into Health?"<<endl;
            do
            {
            int healthPlus=GetNumber();
            if(healthPlus>=0 && healthPlus<=pointsLeft)
            {
            pointsLeft=pointsLeft-healthPlus;
            baseHealth=baseHealth+healthPlus*10;
            health=health+healthPlus*10;
            centinue =true;
            }
            else
                centinue=false;
            }while (centinue==false);

            cout<<"How many points would you like to put into Damage?"<<endl;
            do
            {
            int damagePlus=GetNumber();
            if(damagePlus>=0 && damagePlus<=pointsLeft)
            {
            pointsLeft=pointsLeft-damagePlus;
            baseDamage=baseDamage+damagePlus;
            centinue=true;
            }
            else
                centinue=false;
            }while (centinue==false);

            cout<<"How many points would you like to put into Energy?"<<endl;
            do
            {
            int energyPlus=GetNumber();
            if(energyPlus>=0 && energyPlus<=pointsLeft)
            {
            pointsLeft=pointsLeft-energyPlus;
            baseEnergy=baseEnergy+energyPlus;
            centinue=true;
            }
            else
                centinue=false;
            }while (centinue==false);
            cout<<"How many points would you like to put into defense?"<<endl;
            do
            {
            int defensePlus=GetNumber();
            if(defensePlus>=0 && defensePlus<=pointsLeft)
            {
            pointsLeft=pointsLeft-defensePlus;
            baseDefense=baseDefense+defensePlus;
            centinue=true;
            }
            else
                centinue=false;
            if (pointsLeft != 0)
                cout<<"You didn't allocate enough skill points!"<<endl;
            }while (centinue==false);
            }while (pointsLeft != 0);
            int newMove = 0;
            bool allMovesGoten = true;
            do
            {
                cout<<"Chose a skill:";
                for(int i=0; i++; i<9)
                {
                    allMovesGoten=allMovesGoten*skillsArray[1];
                    if(i==0&&skillsArray[i]==0)
                        cout<<"1) Heal" <<endl <<"Uses 2 energy, heals 5 points of damage"<<endl <<endl;
                    if(i==1&&skillsArray[i]==0)
                        cout<<"2) Gaurd Break" <<endl <<"Uses 1 energy, does large amounts of damage if your enemy blocks"<<endl <<endl;
                    if(i==2&&skillsArray[i]==0)
                        cout<<"3) Iron Skin" <<endl <<"Uses 3 energy, increases player defense" <<endl <<endl;
                    if(i==3&&skillsArray[i]==0)
                        cout<<"4) Prayer To The Old Gods" <<endl <<"Uses 4 energy, increases player attack" <<endl <<endl;
                    if(i==4&&skillsArray[i]==0)
                        cout<<"5) Ethral Scream" <<endl <<"Uses 4 energy, lowers enemy defense and attack greatly for a short time" <<endl <<endl;
                    if(i==5&&skillsArray[i]==0)
                        cout<<"6) Blood Curse" <<endl <<"Uses 2 energy, player gives 20% of their curent health to do twice that damage to the enemy" <<endl <<endl;
                    if(i==6&&skillsArray[i]==0)
                        cout<<"7) Darkness Falls" <<endl <<"Uses 5 energy, both player and enemy damage is halved for a period of time" <<endl <<endl;
                    if(i==7&&skillsArray[i]==0)
                        cout<<"8) Damage Bank" <<endl <<"Uses 2 energy, player waits one trun then attacks doing double damage" <<endl <<endl;
                    if(i==8&&skillsArray[i]==0)
                        cout<<"9) Great Heal" <<endl <<"Uses 9 energy, heals lots of damage"<<endl <<endl;
                    if(i>=9)
                        cout<<"Too Far" <<endl;
                }
                    if (allMovesGoten==0)
                    {
                    int choice = GetNumber();
                    if (choice>=0&&choice<=9)
                    {
                    if (skillsArray[choice-1]==1)
                        cout<<"Please enter a valid number";
                    else
                    {
                        skillsArray[choice-1]=1;
                        cout<<"You learne a new skill";
                        newMove=1;
                    }
                    }
                    else
                        cout<<"Please enter a valid choice";
                    }
                    else
                        cout<<"You have all moves!";
            }while(newMove == 0);

    }
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






