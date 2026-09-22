#ifndef ITEM_H
#define ITEM_H
#include <string>
using std::string;
#include <variant>
#include "../Items_Templates/Consumable.h"
#include "../Items_Templates/Equipable.h"
#include "../Items_Templates/Usable.h"
using ItemVariant = std::variant<Consumable, Equipable, Usable>;
enum class ItemCategoryType
{
    Equipable,
    Consumable,
    Usable,
    Unknown
};

enum class ItemType
{
    Module,
    Weapon,
    Coin,
    Rubbish,
    Artefact,
    Fragment,
    Chest,
    Money,
    Unknown
};

enum class ItemRarity
{
    Common,
    Rare,
    Epic,
    Legendary,
    Unknown
};

struct Item
{
    ItemType type;
    ItemRarity rarity;
    int id;
    string name;

    Item(int i=0,string n="",ItemType t=ItemType::Unknown, ItemRarity r=ItemRarity::Unknown) : type(t), rarity(r), id(i), name(n) {
    };

};

#endif