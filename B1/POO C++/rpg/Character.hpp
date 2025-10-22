#include <iostream>
using namespace std;
#include "Weapon.hpp"
#pragma once


class Character
{
private:
    string name;
    int life;
    int mana;
    Weapon equippedWeapon;

public:
    Character();
    Character(string newName, int newLife, int newMana, string newWeapon, int newDamages/*,Weapon &newEquippedWeapon*/);
    void receiveDamages(int damages);
    void attack(Character &target);
    void takeLifePotion(int lifePoints);
    void switchWeapon(string weaponName, int weaponDamages);
    bool isAlive();
    void display();
    void gameOver();
    ~Character();
};