#include <iostream>
#pragma once
using namespace std;
#include "Character.hpp"

class Increase
{
protected:
    string name;
    int bonusType;
    int bonusValue;
    int price;

public:
    Increase();
    Increase(string name, int bonusType, int bonusValue, int price);
    ~Increase();
    void generateIncrease();
    void applyEffect(Character &target);
    void displayInformations();
};