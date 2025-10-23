#include "Character.hpp"
#pragma once

Character::Character()
{
    firstName = "David";
    lastName = "Martinez";
    lifePoints = 100;
    reputation = 5;
    money = 25;
    attackPoints = 1;
}

Character::Character(string newFirstName, string newLastName, int newLifePoints, int newReputation, int newMoney)
{
    firstName = newFirstName;
    lastName = newLastName;
    lifePoints = newLifePoints;
    reputation = newReputation;
    money = newMoney;
    attackPoints = 1;
}

Character::~Character()
{
}

void Character::displayStats()
{
    cout << "First name : " << firstName << endl;
    cout << "Last name : " << lastName << endl;
    cout << "HP : " << lifePoints << endl;
    cout << "Reputation : " << reputation << endl;
    cout << "Money : " << money << endl;
}

void Character::receiveDamages(int damages)
{
    if (lifePoints >= 0)
    {
        lifePoints -= damages;
    }
    if (lifePoints <= 0)
    {
        cout << firstName << " " << lastName << " is dead. Game Over." << endl;
    }
}

void Character::getDefense(int defBonus)
{
    lifePoints += defBonus;
}

void Character::getAttack(int atkBonus)
{
    attackPoints += atkBonus;
}

void Character::getMoney(int sum)
{
    money += sum;
}

int Character::getReputation(int gain)
{
    reputation += gain;
    if (reputation > 100) {
        reputation = 100;
        cout << firstName << " " << lastName << " has " << reputation << " reputation." << endl;
    } 
    return reputation;
}
void Character::attack(Character &target)
{
    for (int i = 0; i < attackPoints ; i++)
    {
        target.receiveDamages(5);
    }
}
