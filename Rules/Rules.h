#ifndef RULES_H
#define RULES_H
#include <vector>
#include <iostream>
#include "Random.h"
using namespace std;
using std::vector;

#include "Item.h"

class Rules
{
public:
    Rules();
    void printItems() const;
    int getItemsCount() const { return datas.size(); }
    Item getItemByInfoDropRules(ItemType type, ItemRarity rarity) const;
    ~Rules();

private:
    vector<Item> datas;
};

#endif