#ifndef LIST_H
#define LIST_H

#pragma once

#include "Item.h"

class List
{
public:
    List();
    static Item &SearchAndReturnItem(ItemType type, ItemRarity rarity);
    ~List();

private:

};

#endif