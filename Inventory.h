#ifndef INVENTORY_H
#define INVENTORY_H
#include "Template/Item.h"
#include "Equipments/Module.h"
#include "Equipments/Weapon.h"

#include <vector>
using std::vector;

#define SIZE_INVENTORY 30
#define SIZE_IDENTIC_ITEM 60
#define SIZE_WEAPONS_SLOT_MAX 6
#define SIZE_MODULES_SLOT_MAX 4

#include <iostream>
using namespace std;

#include <string>
using std::string;

#pragma once

class Inventory
{
public:
    Inventory();
    bool IsPossibleToGetItem();
    bool IsPossibleToGetWeapon();
    bool IsPossibleToGetModule();
    
    void Help();
    void Print(char c);

    ~Inventory();

private:
    vector<Item> inventory;
    vector<Weapon> weapon;
    vector<Module> module;
};

#endif