#ifndef ITEM_H
#define ITEM_H

#include <string>
using std::string;

enum ItemType
{
    Weapon,
    Chest,
    Money,
    Module
};

enum ItemRarity
{
    Common,
    Rare,
    Epic,
    Legendary
};

struct Item
{
    int id;
    std::string name;
    ItemType type;
    ItemRarity rarity;

    Item() : id(0), name(""), type(ItemType::Weapon), rarity(ItemRarity::Common) {}

    Item(int id, const std::string& name, ItemType type, ItemRarity rarity): id(id), name(name), type(type), rarity(rarity)
    {

    };
};

#endif