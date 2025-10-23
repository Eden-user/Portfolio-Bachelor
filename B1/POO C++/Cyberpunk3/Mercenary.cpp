#include "Mercenary.hpp"
#include <string>
#include <list>

Mercenary::Mercenary()
{
    mercenaryType = "solo";
}

Mercenary::Mercenary(string newFirstName, string newLastName, int newLifePoints, int newReputation, int newMoney, string newMercenaryType) : Character(newFirstName, newLastName, newLifePoints, newReputation, newMoney)
{
    mercenaryType = newMercenaryType;
}

Mercenary::Mercenary(vector <string> Savefile) : Character(Savefile[0], Savefile[1], Savefile[2], Savefile[3], Savefile[4])
{    
    mercenaryType = Savefile[5];
}

Mercenary::~Mercenary()
{
}

string Mercenary::getStats()
{
    string info = firstName + "\n" + lastName + "\n" + to_string(lifePoints) + "\n" + to_string(reputation) + "\n" + to_string(money) + "\n" + mercenaryType + "\n";
    return info;
}

void Mercenary::bonus()
{
    if (mercenaryType == "solo")
    {
        getAttack(1);
    }
    else if (mercenaryType == "netRunner")
    {
        getReputation(5);
    }
    else if (mercenaryType == "techie")
    {
        getDefense(10);
    }
    else
    {
    }
}