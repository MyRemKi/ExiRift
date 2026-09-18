#ifndef GAME_H
#define GAME_H
#include "../Player/Player.h"
#include <string>
using std::string;

#include "../Inventory/Inventory.h"
#include "../Random/Random.h"

#include "../Enemy/Mob.h"
#define SIZE_SPAWN_MOBS 10
#pragma once

class Game
{
public:
    Game();
    void Init();
    void Run();
    void Exit();
    void PrintCommand();
    string ReturnRequest();
    void Play();
    void CheckInventory();
    void CheckEquipments();
    void CommandSelectionToMethodCalling(string &request);
    ~Game();

private:
    Random rand;
    bool loop = true;
    Player *player;
    Inventory *inventory;
    vector<Mob*> mobs;
};

#endif