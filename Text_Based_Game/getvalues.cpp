#include "getvalues.h"
#include <iostream>
#include <time.h>
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
int skillsArray[9]={1,0,0,0,0,0,0,0,0};
    int GetNumber()
    {
        int x;
        cout <<"Enter a number ";
        cin >>x;
        return x;
    }

    void InitalizeName ()
    {
        cout << "First please enter your name: ";
        cin >>pName;
        cout << "Ok, thanks " << pName <<endl <<endl;
    }

    void InitalizeHealth ()
    {
        do
        {
        cout <<"Enter your health, must be between 3-11" <<endl;
        baseHealth = GetNumber();
        } while (baseHealth <3 || baseHealth >11);
        cout << "Ok, your health is " <<baseHealth <<endl <<endl;
        health=baseHealth;
    }

    void InitalizeDamage ()
    {
        do
        {
        cout << "Now enter your damage must be between 3 and " <<14-baseHealth <<endl;
        baseDamage = GetNumber();
        } while (baseDamage <3 || baseDamage+baseHealth >14);
        cout << "Ok, your damage is " <<baseDamage <<endl <<endl;
    }

    void InitalizeEnergy ()
    {
        do
        {
            cout << "Now enter your energy, must be between 3 and " <<17-baseHealth-baseDamage <<endl;
            baseEnergy = GetNumber();
        } while (baseDamage <3 || baseDamage+baseHealth+baseEnergy >17);
        cout << "Ok, your energy is " <<baseEnergy <<endl <<endl;
    }
    void InitalizeDefense ()
    {
        do
        {
            cout << "Now enter your defense, must be " <<20-baseHealth-baseDamage-baseEnergy <<endl;
            baseDefense = GetNumber();
        } while (baseDefense <3 || baseDamage+baseHealth+baseEnergy+baseDefense >20);
        cout << "Ok, your energy is " <<baseEnergy <<endl <<endl;
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
        return baseDefense;
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
    }

    int StandardActions()
    {
        cout<<"Ok, standard action" <<endl;
        string answer;
        cout << endl <<"Block or attack?" <<endl;
        cin >> answer;
        cout <<endl;
        if (answer=="attack")
            return 0;
        else
            return 1;
    }

    int SpecialActions(int energy)
    {
        int energyReq;
        cout<<"Ok, special action" <<endl <<endl <<"Chose an action:" <<endl <<endl;
        for(int i=0; i<10; i++)
        {
            int count=i;
            int x = GetSkillsArray(i);
            if (count==0)
            {
                if (x==1)
                    cout<<"1) Heal -2" <<endl;
                energyReq=2;
            }
            else if (count==1)
            {
                if (x==1)
                    cout<<"2) Gaurd Break -1"<<endl;
                energyReq=1;
            }
            else if (count==2)
            {
                if (x==1)
                    cout<<"3) Iron skin -3"<<endl;
                energyReq=3;
            }
            else if (count==3)
            {
                if (x==1)
                    cout<<"4) Prayer to the old gods -4"<<endl;
                energyReq=4;
            }
            else if (count==4)
            {
                if (x==1)
                    cout<<"5) Ethral scream  -4"<<endl;
                energyReq=4;
            }
            else if (count==5)
            {
                if (x==1)
                    cout<<"6) Blood curse -2"<<endl;
                energyReq=2;
            }
            else if (count==6)
            {
                if (x==1)
                    cout<<"7) Darkness falls -5"<<endl;
                energyReq=5;
            }
            else if (count==7)
            {
                if (x==1)
                    cout<<"8) Damage bank - 2"<<endl;
                energyReq=2;
            }
            else if (count==8)
            {
                if (x==1)
                    cout<<"9) Great heal -9"<<endl;
                energyReq=9;
            }
            else if (count==9)
            {
                    cout<<"10) standard actions -0"<<endl<<endl;
            }
        }
        int number = GetNumber();
        if (number==10)
            StandardActions();
        else if (skillsArray[number-1]==1)
        {
            if (energyReq > energy)
            {
                cout<<"Too little energy! Please enter a valid number" <<endl;
                SpecialActions(energy);
            }
            else
            return number + 2;
        }
        else
        {
            cout <<"Please enter a valid number" <<endl;
            SpecialActions(energy);
        }

    }

    int GetPAttack(int energy)
    {
        bool answer = CheckOk("Use a special action?");
        if (answer == false)
        {
            return StandardActions();
        }
        else
        {
            return SpecialActions(energy);
        }
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

    bool FiftyFifty()
    {
       srand (time(NULL));
       int x = rand() % 2 + 0;
       if (x==1)
           return true;
       else
           return false;
    }






