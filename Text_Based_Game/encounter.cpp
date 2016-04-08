#include "encounter.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "getvalues.h"
#include "battle.h"
using namespace std;
int Encounter(int level, string zName )
{    
    srand (time(NULL));
    int rand1=rand() % 4 + 1;
    int damageDone = 0;
    if (rand1 < 3)
    {
        cout<< "You see an agressive " <<zName <<", coming at you, you must battle!" <<endl;
        Battle(level, zName, 0);
    }
    else if (rand1 == 1)
    {
        cout<< "You spot a " <<zName <<", it hasn't seen you yet" <<endl;
        if (CheckOk("Do you attack?")==true)
        {
            Battle(level,zName, 1);
            return damageDone;
        }
        else if (FiftyFifty()== true)
        {
            cout<<"Attempting sneak..."<<endl <<endl;
            cout << "Sneak succesful! You snuck past the " <<zName <<"!" <<endl <<endl;
        }
        else
        {
            cout<<"Attempting sneak..."<<endl <<endl;
            cout << "Sneak failed! The " <<zName <<" attacked you!" <<endl;
            Battle(level, zName, 2);
        }
    }
    else
    {
        cout<< "A " <<zName <<" attacks you before you can react!" <<endl;
        Battle(level, zName, 2);
    }


    return damageDone;
}

