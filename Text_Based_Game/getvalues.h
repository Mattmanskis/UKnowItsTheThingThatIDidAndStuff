#ifndef GETVALUES_H
#define GETVALUES_H
#include <string>
using namespace std;
void InitalizeName();
void InitalizeHealth();
void InitalizeDamage();
void InitalizeEnergy();
void InitalizeDefense();
int GetHealth();
int GetBaseHealth();
int GetDamage();
int GetEnergy();
int GetLevel();
string GetName();
void GetStats ();
void SetHealth(int damage);
int GetNumber();
bool CheckOk(string text);
bool FiftyFifty();
#endif // GETVALUES_H
