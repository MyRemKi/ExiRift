#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Item.h"
#include <iostream>
using namespace std;
using std::vector;
#define SIZE_INVENTORY 10
class Player
{
public:
    Player(int h, int a);
    void printItems() const;
    int SetHit() const { return class_weapon_1->getDamage(); }
    void AddItem(const Item& item) { inventory.push_back(item); }
    ~Player();

private:
    int health; 
    Item inventory[SIZE_INVENTORY];
    Weapon *class_weapon_1, *class_weapon_2;

};

#endif