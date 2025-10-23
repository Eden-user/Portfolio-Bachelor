#include <iostream>
using namespace std;
#pragma once

class Character
{
protected:
    string firstName;
    string lastName;
    int lifePoints;
    int reputation;
    int money;
    int attackPoints;

public:
    Character();
    Character(string firstName, string lastName, int lifePoints, int reputation, int money);
    void displayStats();

    void receiveDamages(int damages);
    void getDefense(int defBonus);
    void getAttack(int atkBonus);
    void getMoney(int sum);
    int getReputation(int gain);
    void attack(Character &target);
    ~Character();
};