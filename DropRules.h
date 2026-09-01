#ifndef DROPRULES_H
#define DROPRULES_H
#include <vector>
#include <utility>
#include "Rules.h"
#include "Item.h"
#include "Random.h"
#include "Mob.h"
#include "Loot.h"
class DropRules
{
public:
    DropRules();
    Item dropItem(Rules &rules, Mob &mob);
    void getRandomItemRarityMob(Rules &rules, Item &item);
    void getRandomItemRarityMiniBoss(Rules &rules, Item &item);
    void getRandomItemRarityBoss(Rules &rules, Item &item);
    ~DropRules();
private:
};

#endif