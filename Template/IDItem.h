#ifndef IDITEM_H
#define IDITEM_H
#include <string>
using std::string;

#include "../Items_Templates/Consumable.h"
#include "../Items_Templates/Equipable.h"
#include "../Items_Templates/Usable.h"

#pragma once

class IDItem
{
public:
    IDItem();
    int ReturnId(){return id;};
    string ReturnTexturePath(){return texture_path;};
    ~IDItem();

private:
    int id=0;
    string texture_path="";
};

#endif