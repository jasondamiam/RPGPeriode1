#include "Player.h"
#include "Item.h"
#include <iostream>

Player::Player(std::string aName, float hp)
{
	SetName(aName);
	SetHP(hp);
}

Player::~Player() 
{

}

void Player::SetName(std::string aName) 
{
	name = aName;
}

std::string Player::GetName() 
{
	return name;
}

void Player::SetHP(float hp) 
{
	hpcount = hp;
}

float Player::GetHP() 
{
	return hpcount;
}

void Player::TakeDamage(float dmg)
{
	float reducedDamage = dmg / defencemultiplier;

	hpcount -= reducedDamage;
}

float Player::GetAttackMultiplier()
{
	return attackmultiplier;
}

float Player::GetDefenceMultiplier() 
{
	return defencemultiplier;
}
void Player::boostStats(Item& item)
{
	attackmultiplier += item.GetATKBoost();
	defencemultiplier += item.GetDefBoost();
	hpcount += item.GetHPBoost();
}
void Player::GetStats() 
{
	std::cout << "Player Name: " << GetName() << "\n" << "HP: " << GetHP() << "\n" << "ATK: " << GetAttackMultiplier() << "\n" << "DEF:" << GetDefenceMultiplier() << "\n";
}

void Player::GameOver()
{
	std::cout << "Game Over! You have died :( \n Retry? (1. Yes, 0 for No) \n ";
	system("pause");
}
