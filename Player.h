#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Item.h"
#include <iostream>
using namespace std;
using std::vector;

class Player
{
public:
    Player(int h, int a);
    void printItems() const;
    int SetHit() const { return attack; }
    void AddItem(const Item& item) { inventory.push_back(item); }
    ~Player();

private:
    int health; 
    int attack;
    vector<Item> inventory;

};

#endif