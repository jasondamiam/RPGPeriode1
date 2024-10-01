#include "Item.h"
#include "Player.h"
#include <iostream>

Item::Item(std::string aName, float atk, float def, float hpboost)
{
    name = aName;
    atkboost = atk;
    defboost = def;
    hprecovery = hpboost;
}

Item::~Item()
{
}

std::string Item::GetName()
{
    return name;
}

std::string Item::GetDesc()
{
    return description;
}

float Item::GetATKBoost()
{
    return atkboost;
}

float Item::GetDefBoost()
{
    return defboost;
}

float Item::GetHPBoost()
{
    return hprecovery;
}

void Item::SetName(std::string aName)
{
    name = aName;
}

void Item::SetDescription(std::string aDescription)
{
    description = aDescription;
}

void Item::GetItemName()
{
    std::cout << GetName() << "\n";
}

void Item::GetItemDescription()
{
    std::cout << GetDesc() << "\n";
}

void Item::Consume(Player& Player)
{
    Player.boostStats(*this);
}
