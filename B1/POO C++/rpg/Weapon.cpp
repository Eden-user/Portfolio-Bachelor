#include "Weapon.hpp"

Weapon::Weapon()
{
    name = "Epée en bois";
    damages = 10;
}

Weapon::Weapon(string newWeapon, int newDamages)
{
    name = newWeapon;
    damages = newDamages;
}

Weapon::~Weapon()
{
}
void Weapon::update(string newName, int newDamages)
{
    name = newName;
    damages = newDamages;
}

void Weapon::weaponDisplay()
{
    cout << "weapon info :" << endl;
    cout << "Name : " << name << endl;
    cout << "ATK : " << damages << endl;
}

int Weapon::getDamages() const
{
    return damages;
}