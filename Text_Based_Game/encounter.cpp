#include "encounter.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "getvalues.h"

int Encounter(int pHealth, int pDamage, string pName, string zName )
{
    srand (time(NULL));
    int rand1=rand() % 3 + 1;
    int damageDone = 0;
    cout <<"Oh Jeez! a " <<zName <<" apeared!" <<endl;
    CheckOk()
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
