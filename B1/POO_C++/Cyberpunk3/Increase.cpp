#include "Increase.hpp"

Increase::Increase()
{
    name = "shoulder gun";
    bonusType = 2;
    bonusValue = 10;
    price = 50;
}
Increase::Increase(string newName, int newBonusType, int newBonusValue, int newPrice)
{
    name = newName;
    bonusType = newBonusType; // 1 = def, 2 = force, 3 = hacking
    bonusType = newBonusValue;
    price = newPrice;
}
Increase::~Increase()
{
}

void Increase::generateIncrease()
{
}
void Increase::displayInformations()
{
    cout << "Increase informations : " << endl;
    cout << "Name : " << name << endl;
    cout << "Bonus type : " << bonusType << endl;
    cout << "Bonus value : " << bonusValue << endl;
    cout << "Price : " << price << endl;
}

void Increase::applyEffect(Character &target)
{
    switch (bonusType)
    {
    case 1:
        target.getDefense(bonusValue);
        break;
    case 2:
        target.getAttack(bonusValue);
        break;
    case 3:
        target.getReputation(bonusValue);
        break;
    default:
        break;
    }
}