#include "DropRules.h"

DropRules::DropRules()
{

}


void DropRules::getRandomItemRarityMob(Rules &rules, Item &item)
{
    ItemType type;
    ItemRarity rarity;

    if(Random::rollChance(0.15f)){
        type = ItemType::Weapon;
        if(Random::rollChance(0.2f)){
        rarity = ItemRarity::Rare;
    }
        else{
            rarity = ItemRarity::Common;
        }
    }
    else if(Random::rollChance(0.05f)){
        type = ItemType::Module;
        
        if(Random::rollChance(0.01f)){
            rarity = ItemRarity::Rare;
        }
        else{
            rarity = ItemRarity::Common;
        }
    }
    else{
        type = ItemType::Money;
        if(Random::rollChance(0.2f)){
            rarity = ItemRarity::Rare;
        }
        else{
            rarity = ItemRarity::Common;
        }
    }

    item = rules.getItemByInfoDropRules(type, rarity);
}

void DropRules::getRandomItemRarityMiniBoss(Rules &rules, Item &item)
{
    ItemType type;
    ItemRarity rarity;

    if(Random::rollChance(0.2f)){
        type = ItemType::Weapon;
        if(Random::rollChance(0.3f)){
            rarity = ItemRarity::Rare;
        }
        else if(Random::rollChance(0.1f)){
            rarity = ItemRarity::Epic;
        }
        else{
            rarity = ItemRarity::Common;
        }
    }
    else if(Random::rollChance(0.2f)){
        type = ItemType::Module;
        if(Random::rollChance(0.2f)){
            rarity = ItemRarity::Rare;
        }
        else if(Random::rollChance(0.1f)){
            rarity = ItemRarity::Epic;
        }
        else{
            rarity = ItemRarity::Common;
        }
    }
    else{
        type = ItemType::Money;
        if(Random::rollChance(0.3f)){
            rarity = ItemRarity::Rare;
        }
        else if(Random::rollChance(0.3f)){
            rarity = ItemRarity::Epic;
        }
        else{
            rarity = ItemRarity::Common;
        }
    }

    item = rules.getItemByInfoDropRules(type, rarity);
}

void DropRules::getRandomItemRarityBoss(Rules &rules, Item &item)
{
    ItemType type;
    ItemRarity rarity;

    if(Random::rollChance(0.4f)){
        type = ItemType::Chest;
        if(Random::rollChance(0.213f)){
            rarity = ItemRarity::Epic;
        }
        else if(Random::rollChance(0.011f)){
            rarity = ItemRarity::Legendary;
        }
        else{
            rarity = ItemRarity::Rare;
        }
    }
    else if(Random::rollChance(0.4f)){
        type = ItemType::Module;
        if(Random::rollChance(0.3f)){
            rarity = ItemRarity::Epic;
        }
        else if(Random::rollChance(0.1f)){
            rarity = ItemRarity::Legendary;
        }
        else{
            rarity = ItemRarity::Rare;
        }
    }
    else{
        type = ItemType::Weapon;
        if(Random::rollChance(0.25f)){
            rarity = ItemRarity::Epic;
        }
        else if(Random::rollChance(0.05f)){
            rarity = ItemRarity::Legendary;
        }
        else{
            rarity = ItemRarity::Rare;
        }
        if(Random::rollChance(0.3f)){
            rarity = ItemRarity::Epic;
        }
        else if(Random::rollChance(0.1f)){
            rarity = ItemRarity::Legendary;
        }
        else{
            rarity = ItemRarity::Rare;
        }
    }

    item = rules.getItemByInfoDropRules(type, rarity);
}

Item DropRules::dropItem(Rules &rules, Mob &mob)
{
    Item item;
    if(mob.type == MobType::Basic){
        getRandomItemRarityMob(rules, item);
    }
    else if(mob.type == MobType::MiniBoss){
        getRandomItemRarityMiniBoss(rules, item);
    }
    else if(mob.type == MobType::Boss){
        getRandomItemRarityBoss(rules, item);
    }
    return item;
}   
DropRules::~DropRules()
{

}