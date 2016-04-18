#include "encounter.h"
#include <iostream>
#include "getvalues.h"
#include "battle.h"
using namespace std;
bool Encounter(int level, string zName )
{    
    int rand1=RandomNumber(1,4);
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
            return Battle(level,zName, 1);
        }
        else if (FiftyFifty()== true)
        {
            cout<<"Attempting sneak..."<<endl <<endl;
            cout << "Sneak succesful! You snuck past the " <<zName <<"!" <<endl <<endl;
            return true;
        }
        else
        {
            cout<<"Attempting sneak..."<<endl <<endl;
            cout << "Sneak failed! The " <<zName <<" attacked you!" <<endl;
            return Battle(level, zName, 2);
        }
    }
    else
    {
        cout<< "A " <<zName <<" attacks you before you can react!" <<endl;
       return Battle(level, zName, 2);
    }

}

