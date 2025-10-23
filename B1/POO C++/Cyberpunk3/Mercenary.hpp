#include <iostream>
#pragma once
#include "Character.hpp"
using namespace std;

class Mercenary : public Character
{
protected:
    string mercenaryType;

public:
    Mercenary();
    Mercenary(string newFirstName, string newLastName, int newLifePoints, int newReputation, int newMoney, string newMercenaryType);
    Mercenary(vector <string> Savefile);
    string getStats();
    ~Mercenary();
    void bonus();
};