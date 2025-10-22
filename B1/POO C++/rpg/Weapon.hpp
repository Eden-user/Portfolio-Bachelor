#include <iostream>
using namespace std;
#pragma once

class Weapon
{
private:
    string name;
    int damages;

public:
    Weapon();
    Weapon(string newWeapon, int newDamages);
    void update(string newName, int newDamages);
    void weaponDisplay();
    int getDamages() const;
    ~Weapon();
};