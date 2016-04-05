#include "getvalues.h"
#include <iostream>
#include <time.h>
using namespace std;
    string GetName ()
    {
        cout << "First please enter your name: ";
        string pName;
        cin >>pName;
        cout << "Ok, thanks " << pName <<endl <<endl;
        return pName;
    }
    int GetNumber()
    {
        int x;
        cout <<"Enter a number ";
        cin >>x;
        return x;
    }

    int GetHealth ()
    {
        int health;
        do
        {
        cout <<"Now enter your health, must be between 3-9" <<endl;
        health = GetNumber();
        } while (health <3 || health >9);
        cout << "Ok, your health is " <<health <<endl <<endl;
        return health;
    }
    int GetDamage (int health)
    {
        int damage;
        do
        {
        cout << "Now enter your damage must be between 3 and " <<12-health <<endl;
        damage = GetNumber();
        } while (damage <3 || damage+health >12);
        cout << "Ok, your damage is " <<damage <<endl <<endl;
        return damage;
    }

    int GetEnergy (int health, int damage)
    {
        int energy;
        do
        {
            cout << "Now enter your energy, must be " <<15-health-damage <<endl;
            energy = GetNumber();
        } while (damage <3 || damage+health >12);
        cout << "Ok, your energy is " <<energy <<endl <<endl;
        return energy;
        }

    bool CheckOk(string text)
    {
      string answer;
      cout <<text << endl <<"y/n?" <<endl;
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






