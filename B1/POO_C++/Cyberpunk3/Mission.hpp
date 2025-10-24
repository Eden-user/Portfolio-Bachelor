#include <iostream>
#include <random>
#include "Character.hpp"
#include "Mercenary.hpp"
using namespace std;
#pragma once

class Mission
{
protected:
    string description;
    int difficulty;
    int cashReward;
    int reputationReward;

public:
    Mission();
    bool executeMission(Character &player);
};