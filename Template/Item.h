#ifndef ITEM_H
#define ITEM_H
#include <string>
using std::string;

#include "ItemCategoryType.h"
#include "ItemType.h"
#include "ItemRarity.h"

#include "IDItem.h"

struct Item : public IDItem
{
    ItemType type;
    ItemRarity rarity;
    int id;
    string name;

    Item(int i=0, string n="", ItemType t=ItemType::Unknown, ItemRarity r=ItemRarity::None) : type(t), rarity(r), id(i), name(n) {
    }

};

#endif
