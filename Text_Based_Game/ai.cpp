#include "ai.h"
#include <iostream>
#include "getvalues.h"
using namespace std;

int GetZAttack(string zName, int energy, double healthPercent)
{
    if (healthPercent<.1)
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
    else if (FiftyFifty() == true)
    {
        if (FiftyFifty() == true && energy >= 2)
            return 9;
        else
            return 0;
    }
    else
    {
        if (FiftyFifty() == true && energy >=2 )
            return 2;
        else
            return 0;
    }

}
/*
if (zName == "Mirror Zombie")
{
    if (pAttack >= 1 || pAttack <= 3)
        zAttack = pAttack;
    else
        zAttack = 1;
}
if (zName == "Defensive Zombie")
{
    if (pAttack==0)
        zAttack=1;
    if (zAttack==0)
    {
        if(FiftyFifty())
            zAttack=1;
        else
            zAttack=3;
    }
    else
        zAttack=2;
}
if (zName == "BOSS ZOMBIE")
{
    int cycle;
    cycle = cycle + 1;
    if (cycle > 0 || cycle <=3)
        cycle = 0;
    if (cycle == 0)
    {
        if (zAttack==0){
            if(FiftyFifty())
                zAttack=1;
            else
                zAttack=2;
        }
        else
        zAttack = 1;
    }
    if (cycle == 1)
    {
        if (zAttack==0){
            if(FiftyFifty())
                zAttack=1;
            else
                zAttack=2;
        }
        else
        zAttack = 1;
    }
    if (cycle == 2)
    {
        if (pAttack==0)
            zAttack=1;
        if (zAttack==0)
        {
            if(FiftyFifty())
                zAttack=1;
            else
                zAttack=3;
        }
        else
            zAttack=2;
    }

}*/
}
