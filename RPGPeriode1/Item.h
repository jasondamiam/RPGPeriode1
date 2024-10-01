#pragma once
#include <string>
#include "Player.h"
class Player;
class Item
{
public:
	Item(std::string aName, float atk, float def, float hpboost);
	~Item();

	std::string GetName();
	std::string GetDesc();
	float GetATKBoost();
	float GetDefBoost();
	float GetHPBoost();
	void SetName(std::string aName);
	void SetDescription(std::string aDescription);

	void GetItemName();
	void GetItemDescription();

	void Consume(Player& Player);

protected:
	std::string name;
	std::string description;
	float atkboost;
	float defboost;
	float hprecovery;
};