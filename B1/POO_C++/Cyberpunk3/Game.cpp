#include "Game.hpp"
#include <string>
#include <list>

void Game::newGame()
{
    string newFirstName;
    string newLastName;
    string mercenaryType;
    cout << "Who are you ? " << endl;
    cout << "First name : ";
    cin >> newFirstName;
    cout << endl
         << "Last name : ";
    cin >> newLastName;
    cout << endl
         << "Choose a Mercenary class (choices are : " << endl;
    cout << " solo (spécialiste combat)" << endl;
    cout << " netRunner (hacker)" << endl;
    cout << " techie (bricoleur))" << endl;
    cin >> mercenaryType;
    Mercenary player(newFirstName, newLastName, 100, 5, 200, mercenaryType);
}
void Game::load()
{
    ifstream saveFile("character.txt");
    string characterTxt;
    vector<string> characterSave;
    while (getline(saveFile, characterTxt))
    {
        characterSave.push_back(characterTxt); 
    }
    saveFile.close();
    Mercenary player(characterSave);
}

void Game::save(Mercenary &player)
{
    ofstream saveFile("test.txt");
    saveFile << player.getStats();
    saveFile.close();
    menu();
}

void Game::menu()
{
    cout << "Welcome to Cyberpunk Simulator 2.0" << endl;
    int userChoice;
    int count = 0;
    cout
        << "Do you want to : " << endl
        << "1) start a new game (enter 1)." << endl
        << "2) load a saved game (enter 2)." << endl
        << "3) exit (enter 3)." << endl;
    cin >> userChoice;
        switch (userChoice)
        {
    case 1:
        newGame();
        break;
    case 2:
        load();
        break;
    case 3:
        abort();
        break;
        }
}
