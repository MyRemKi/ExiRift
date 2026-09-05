#ifndef WEAPON_H
#define WEAPON_H
#include <string>
using namespace std;
using std::string;

class Weapon
{
public:
    Weapon(string name, int attack_point,int reload_time,int current_munitions,int max_munitions);
    int giveAttackPoint() const;
    void reload();
    void giveMunitions(int munitions);
    void 
    ~Weapon();

private:
    int attack_point;
    int reload_time;
    int current_munitions, max_munitions;
    string name;

};

#endif