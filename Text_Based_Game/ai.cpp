#include "ai.h"

if (zName == "Agressive Zombie")
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

}
