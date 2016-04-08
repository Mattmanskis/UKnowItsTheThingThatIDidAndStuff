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
int skillsArray[10]={0,0,0,0,0,0,0,0,0,0};
//{1 ,2 heal,3 bash,4 iron skin,5 rage,6 blinding light,7 great heal, 8 curse drain, 9 intimidate, 10 comforting light}
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






