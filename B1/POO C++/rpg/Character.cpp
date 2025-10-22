#include "Character.hpp"

Character::Character()
{
    name = "blabla";
    life = 100;
    mana = 100;
    equippedWeapon = Weapon();
}

Character::Character(string newName, int newLife, int newMana, string newWeapon, int newDamages)
{
    name = newName;
    life = newLife;
    mana = newMana;
    equippedWeapon.update(newWeapon, newDamages);
}

Character::~Character()
{
}

void Character::receiveDamages(int damages)
{
    if (life >= 0)
    {
        life -= damages;
    }
    if (life <= 0)
    {
        cout << name << " is dead. Game Over." << endl;
    } 
}

void Character::attack(Character &target)
{
    target.receiveDamages(equippedWeapon.getDamages());
}

void Character::takeLifePotion(int lifePoints)
{
    if (life <= 100)
    {
        life += lifePoints;
    }
}

void Character::switchWeapon(string weaponName, int weaponDamages)
{
    equippedWeapon.update(weaponName, weaponDamages);
}

bool Character::isAlive()
{
    return life > 0;
}

void Character::display()
{
    cout << name << endl;
    cout << "HP : " << life << endl;
    cout << "Mana : " << mana << endl;
    equippedWeapon.weaponDisplay();
}
