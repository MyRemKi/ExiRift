#include "Weapon.h"

Weapon::Weapon(string name, int attack_point, int reload_time, int current_munitions, int max_munitions)
    : attack_point(attack_point), reload_time(reload_time), current_munitions(current_munitions), max_munitions(max_munitions), name(name)
{

}

Weapon::~Weapon()
{

}