#ifndef MOB_H
#define MOB_H

#include <string>
#include "MobType.h"
#include "../Template/Position.h"

struct Mob : public Position {
    std::string name;
    int health;
    int attack;
    MobType type;

    Mob(MobType t)
        : type(t) {}

    Mob(const std::string& n="Unknown", int h=1, int a=0, MobType t=MobType::Unknown)
        : name(n), health(h), attack(a), type(t) {}
};

#endif