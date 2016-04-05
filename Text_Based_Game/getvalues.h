#ifndef GETVALUES_H
#define GETVALUES_H
#include <string>
using namespace std;
string GetName ();
int GetNumber();
int GetHealth ();
int GetDamage (int health);
int GetEnergy (int health, int damage);
bool CheckOk(string text);
bool FiftyFifty();
#endif // GETVALUES_H
