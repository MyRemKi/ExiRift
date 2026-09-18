#ifndef ITEM_H
#define ITEM_H
#include <string>
using std::string;

enum ItemCategoryType
{
    Equipable,
    Consumable,
    Usable,
    Unknown,
};

enum ItemType
{
    Module,
    Weapon,
    Coin,
    Rubbish,
    Artefact,
    Fragment,
    Chest,
    Unknown
};

enum ItemRarity
{
    Common,
    Rare,
    Epic,
    Legendary,
    None
};

struct Item
{
    ItemType type;
    ItemRarity rarity;
    int id;
    string name;

    Item(int i=0, string n="", ItemType t=ItemType::Unknown, ItemRarity r=ItemRarity::None) : type(t), rarity(r), id(i), name(n) {
    }

};

#endif
