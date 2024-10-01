#pragma once
#include <string>
#include "Player.h"
class Player;
class Enemy
{
public:
	Enemy(std::string aName, float hp);
	~Enemy();
	
	void SetEnemyName(std::string aName);
	std::string GetEnemyName();

	void SetEnemyHP(float hp);
	float GetEnemyHP();

	void DamageAmount(float amount, Player& player);
	float GetDamage();
	void TakeDamage();

	void EnemyStats();
	void GameOver();

private:
	std::string name;
	float enemyHP;
	float takeDamage;
};

