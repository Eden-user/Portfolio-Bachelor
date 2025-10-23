#include <iostream>
#include "Character.hpp"
#include "Increase.hpp"
#include "Mission.hpp"
#include "Mercenary.hpp"
#include <fstream>
using namespace std;

class Game
{
public:
    void newGame();
    void load();
    void save(Mercenary &player);
    void menu();
};