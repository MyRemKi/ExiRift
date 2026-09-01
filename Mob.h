#ifndef MOB_H
#define MOB_H

#include <string>

enum MobType {
    Basic,
    MiniBoss,
    Boss,
    Unknown
};

struct Mob {
    std::string name;
    int health;
    int attack;
    int defense;
    MobType type;

    Mob(MobType t)
        : type(t) {}

    Mob(const std::string& n="Unknown", int h=1, int a=0, int d=0, MobType t=MobType::Unknown)
        : name(n), health(h), attack(a), defense(d), type(t) {}
};

#endif