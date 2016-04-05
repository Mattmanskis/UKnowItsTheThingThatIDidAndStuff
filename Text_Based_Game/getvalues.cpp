#include "getvalues.h"
#include <iostream>
#include <time.h>
#include <tgmath.h>
using namespace std;

int health;
int baseHealth;
int baseDamage;
int baseEnergy;
string pName;
double experiance = 0;
double experianceRequired = 10;

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
        cout <<"Enter your health, must be between 3-9" <<endl;
        baseHealth = GetNumber();
        } while (baseHealth <3 || baseHealth >9);
        cout << "Ok, your health is " <<baseHealth <<endl <<endl;
        health=baseHealth;
    }

    void InitalizeDamage ()
    {
        do
        {
        cout << "Now enter your damage must be between 3 and " <<12-baseHealth <<endl;
        baseDamage = GetNumber();
        } while (baseDamage <3 || baseDamage+baseHealth >12);
        cout << "Ok, your damage is " <<baseDamage <<endl <<endl;
    }

    void InitalizeEnergy ()
    {
        do
        {
            cout << "Now enter your energy, must be " <<15-baseHealth-baseDamage <<endl;
            baseEnergy = GetNumber();
        } while (baseDamage <3 || baseDamage+baseHealth >12);
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
        cout<<baseEnergy <<" starting energy"<<endl <<endl;
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






