#include "ai.h"
#include <iostream>
#include "getvalues.h"
using namespace std;

int GetZAttack(string zName, int energy, double healthPercent, int coolDownArray[5])
{
    if (healthPercent<10)
    {
        if(energy>=9)
        {
            return 11;
        }
        else if(energy>=4)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
else if (zName == "Agressive Zombie")
{
    if (energy == 4)
        return  5;
    else
    {
    int rand=RandomNumber(1,10);
    if (rand < 4 && energy > 1)
        return 9;
    else
        return 0;
    }

}
else if (zName == "Boney Zombie")
{
    if(healthPercent > 80 && energy > 2)
        return 7;
    else if(healthPercent < 50)
    {
        if(energy>=9)
            return 10;
        else if (energy>=2 && healthPercent<=30)
            return 2;
        else
            return 1;
    }
    else
        return 0;

}
else if (zName == "Slime")
{
    if(coolDownArray[3]!=0)
    {
        if (energy>=3 && coolDownArray[0]==0)
            return 4;
        else
            return 0;
    }
    else if (energy >=3)
    {
        if (energy >=5)
            return 8;
        else if(coolDownArray[0] != 0)
            return 4;
        else
            return 0;
    }
    else
        return 1;
}
    return 0;
}
