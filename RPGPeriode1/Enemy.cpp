#include "Enemy.h"
#include "Player.h"
#include <iostream>

Enemy::Enemy(std::string aName, float hp)
{
	SetEnemyName(aName);
	SetEnemyHP(hp);
}

Enemy::~Enemy()
{
}

void Enemy::SetEnemyName(std::string aName)
{
	name = aName;
}

std::string Enemy::GetEnemyName()
{
	return name;
}

void Enemy::SetEnemyHP(float hp)
{
	enemyHP = hp;
}

float Enemy::GetEnemyHP()
{
	return enemyHP;
}

void Enemy::DamageAmount(float amount, Player& player)
{
	takeDamage = (amount * player.GetAttackMultiplier());
}

float Enemy::GetDamage()
{
	return takeDamage;
}

void Enemy::TakeDamage()
{
	enemyHP -= takeDamage;
}

void Enemy::EnemyStats() 
{
	std::cout << "Enemy: " << GetEnemyName() << "\n" << "HP: " << GetEnemyHP() << "\n";
}

void Enemy::GameOver()
{
	std::cout << "Enemy slain! You win! \n Battle again? (1. Yes 0. Quit) \n";
}
