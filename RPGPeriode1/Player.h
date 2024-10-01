#pragma once
#include <string>
#include "Item.h"
class Item;
class Player
{
public:
	Player(std::string aName, float hp);
	~Player();

	void SetName(std::string aName);
	std::string GetName();

	void SetHP(float hp);
	float GetHP();
	void TakeDamage(float dmg);
	float GetAttackMultiplier();
	float GetDefenceMultiplier();

	void boostStats(Item& item);

	void GetStats();
	void GameOver();

private:
	std::string name;
	float hpcount;
	float attackmultiplier = 1.00;
	float defencemultiplier = 1.00;
};

