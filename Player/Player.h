#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "../Template/Item.h"
#include "../Equipments/Weapon.h"
#include "../Template/Position.h"
#include <iostream>
using namespace std;
using std::vector;
class Player : public Position
{
public:
    Player(int h, int a);
    void printItems() const;
    int SetHit() const { return class_weapon_1->giveAttackPoint(); }
    void GetHit(int hit){
        this->health -=hit;
    }
    bool CheckHealth(){
        return this->health <= 0;
    }
    void AddItem(const Item& item) { inventory.push_back(item); }
    ~Player();

private:
    int health;
    int attack;
    vector<Item> inventory;
    Weapon *class_weapon_1 = nullptr, *class_weapon_2 = nullptr;

};

#endif
