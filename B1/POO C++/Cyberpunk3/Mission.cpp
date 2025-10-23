#include "Mission.hpp"

int random(int min, int max)
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

Mission::Mission()
{
    difficulty = random(0, 100);
    cashReward = random(100, 1000);
    reputationReward = random(5, 15);
}
bool Mission::executeMission(Character &player)
{
    if (difficulty > player.getReputation(0))
    {
        int damages = player.getReputation(0)/difficulty;
        cout << "The mission got the best of you, you lost " << reputationReward << " reputation and took " << damages << " damages." << endl;
        player.getReputation(-reputationReward);
    }
    else
    {
        cout << "Well done, you received " << reputationReward << " reputation and " << cashReward << " cash units." << endl;
        player.getReputation(reputationReward);
        player.getMoney(cashReward);
    }
}
