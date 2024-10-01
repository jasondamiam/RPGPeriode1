#pragma once
#include <string>
#include "Item.h"
class Consumable :
    public Item
{
public:
    Consumable(std::string aName);
    ~Consumable();

private:
    int amountOfHealth;
    int amountOfAttackMultiplier;
    int amountOfMagic;
    int amountOfMana;
};

