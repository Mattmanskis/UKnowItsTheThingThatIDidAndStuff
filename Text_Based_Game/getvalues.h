#ifndef GETVALUES_H
#define GETVALUES_H
#include <bits/stringfwd.h>
int GetNumber();
int GetHealth ();
int GetDamage (int health);
int GetEnergy (int health, int damage);
bool CheckOk(string text);
#endif // GETVALUES_H
