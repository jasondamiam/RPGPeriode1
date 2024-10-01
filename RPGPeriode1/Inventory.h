#pragma once
#include <vector>
#include <string>
#include "Item.h"
class Inventory
{
public:
	Inventory();
	~Inventory();

public:
	void AddItem(Item* anItem);
	std::vector<Item*> GetItems();
	void RemoveItem(Item* anItem);

private:
	std::vector<Item*> items;
	int capacity;
	std::string color;
};

