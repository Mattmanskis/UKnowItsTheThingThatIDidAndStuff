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
    int rand1=rand() % 3 + 1;
    int damageDone = 0;
    cout <<"Oh Jeez! a level " <<level <<" " <<zName <<" apeared!" <<endl;
    if (CheckOk("Do you attack?")==true)
    {
        Battle(level,zName, true);
        return damageDone;
    }
    else if (FiftyFifty()== true)
    {
        cout<<"Attempting sneak..."<<endl <<endl;
        cout << "Sneak succesful! You snuck past the " <<zName <<"!!!" <<endl <<endl;
    }
    else
    {
        cout<<"Attempting sneak..."<<endl <<endl;
        cout << "Sneak failed! The " <<zName <<" saw you!!!" <<endl;
        Battle(level, zName, false);
    }

    return damageDone;
}

