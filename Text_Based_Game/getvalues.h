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
int GetDefense();
int GetDamage();
int GetEnergy();
int GetLevel();
int GetEnergyReq(int x);
string GetName();
void GetStats ();
void SetHealth(int damage);
int GetPAttack(int energy);
int GetNumber();
int RandomNumber(int x, int y);
bool CheckOk(string text);
bool FiftyFifty();
#endif // GETVALUES_H
