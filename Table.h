#ifndef TABLE_H
#define TABLE_H
#include "Item.h"
#pragma once
#define SIZE_INVENTORY 10

class Table
{
public:
    Table();
    void change Item(int index, const Item& newItem);
    int getSizeInventory() const { return SIZE_INVENTORY; }
    int returnItemId(int index) const { return inventory[index].id; }
    void printItems() const;
    ~Table();

private:
    Item inventory[SIZE_INVENTORY];
};

#endif