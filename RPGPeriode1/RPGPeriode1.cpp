#include <iostream>
#include <random>
#include <cstdlib>
#include "Player.h"
#include "Enemy.h"
#include "Inventory.h"
#include "Item.h"

bool gameIsRunning = true;

enum attackDmg
{
    basic = 10,
    heavy = 25
};

int main()
{
    std::vector<attackDmg> dmgCount = { basic, heavy };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, dmgCount.size() - 1);

    Inventory inv;
    Item stone("Stone", 0.5f, 0.0f, 0.0f); // atk - def - hp
    Item bread("Bread", 0.0f, 0.0f, 200.0f);
    Item basicArmor("Basic Armor", 0.0f, 0.5f, 0.0f);
    inv.AddItem(&stone);
    inv.AddItem(&bread);
    inv.AddItem(&basicArmor);
    stone.SetDescription("The magical stone. Increases ATK by 0.5.");
    for (int i = 0; i < inv.GetItems().size(); i++) {
        std::cout << inv.GetItems().at(i)->GetName() << "\n";
    }

    Player player1("Joe", 20); // name - hp
    Enemy clockie("Clockie", 1000); // name - hp

    int skillPoints = 3;

    while (gameIsRunning)
    {
        system("pause");
        system("cls");
        int randomIndex = distr(gen);
        attackDmg randomAttack = dmgCount[randomIndex];

        if (skillPoints > 5) // limits the skill point count to max 5
        {
            skillPoints = 5;
        }


        int x = 0;
        clockie.EnemyStats();
        std::cout << "\n" << "Your HP: " << player1.GetHP() << "\n";
        std::cout << "Skill Points: " << skillPoints << "\n";
        std::cout << "\n 1: Attack \n 2: View Items \n 3: View Stats \n";
        std::cin >> x;


        if (x == 1)
        {
            int attackChoice = 0;
            std::cout << "1. Basic \n2. Skill \n";
            std::cin >> attackChoice;
            if (attackChoice == 1)
            {
                skillPoints += 1;
                clockie.DamageAmount(20, player1);
                clockie.TakeDamage();
                std::cout << "Clockie has taken " << clockie.GetDamage() << " Damage! \n";
                player1.TakeDamage(randomAttack);
                std::cout << "You have taken " << randomAttack << " Damage!" << "\n";
                x = 0;
            }
            else if (attackChoice == 2)
            {
                if (skillPoints == 0)
                {
                    std::cout << "No skill points! \n";
                    x == 1;
                }
                else {
                    skillPoints -= 1;
                    clockie.DamageAmount(60, player1);
                    clockie.TakeDamage();
                    std::cout << "Clockie has taken " << clockie.GetDamage() << " Damage! \n";
                    player1.TakeDamage(randomAttack);
                    std::cout << "You have taken " << randomAttack << " Damage!" << "\n";
                    x = 0;
                }
            }
            else
            {
                x = 0;
            }
        }
        else if (x == 2) // View and use items
        {
            if (inv.GetItems().empty()) {
                std::cout << "No items in inventory.\n";
            }
            else {
                // Display available items
                for (int i = 0; i < inv.GetItems().size(); i++) {
                    std::cout << i + 1 << ": " << inv.GetItems().at(i)->GetName() << "\n";
                }

                int itemChoice = 0;
                std::cout << "Select an item number to view, or press 0 to go back.\n";
                std::cin >> itemChoice;

                if (itemChoice > 0 && itemChoice <= inv.GetItems().size()) {
                    // Get the selected item
                    Item* selectedItem = inv.GetItems().at(itemChoice - 1);

                    std::cout << "Item: " << selectedItem->GetName() << "\n";
                    std::cout << "Description: " << selectedItem->GetDesc() << "\n";
                    std::cout << "Attack Boost: " << selectedItem->GetATKBoost() << "\n";
                    std::cout << "Defence Boost: " << selectedItem->GetDefBoost() << "\n";
                    std::cout << "HP Boost: " << selectedItem->GetHPBoost() << "\n";

                    // Ask if they want to use the item
                    int useChoice = 0;
                    std::cout << "Do you want to use this item? (1 for Yes, 0 for No)\n";
                    std::cin >> useChoice;

                    if (useChoice == 1) {
                        // Use the item and apply its effect
                        selectedItem->Consume(player1);  // Apply item effect to player
                        std::cout << "You have used the " << selectedItem->GetName() << "!\n";

                        // Remove the item from inventory
                        inv.RemoveItem(selectedItem);
                        std::cout << "The item has been removed from your inventory.\n";
                        player1.TakeDamage(randomAttack);
                        std::cout << "You have taken " << randomAttack / player1.GetDefenceMultiplier() << " damage! \n";
                    }
                    else {
                        std::cout << "You chose not to use the item.\n";
                    }
                }
                else if (itemChoice == 0)
                {
                    std::cout << "Going back to the main menu.\n";
                }
                else
                {
                    std::cout << "Invalid item selection.\n";
                }
            }
        }

        else if (x == 3)
        {
            player1.GetStats();
        }
        else
        {
            std::cout << "Exiting...\n";
            gameIsRunning = false;
        }

        if (player1.GetHP() < 0.1) // if player dies game over
        {
            system("cls");
            int retry;
            player1.SetHP(0);
            player1.GameOver();
            std::cin >> retry;

            if (retry == 1) {
                player1.SetHP(200);
                clockie.SetEnemyHP(1000);
                skillPoints = 3;
                continue;
            }
            else 
            {
                break;
            }
        }

        if (clockie.GetEnemyHP() < 0.1) 
        {
            system("cls");
            int retry;
            clockie.SetEnemyHP(0);
            clockie.GameOver();
            std::cin >> retry;

            if (retry == 1) 
            {
                player1.SetHP(200);
                clockie.SetEnemyHP(1000);
                skillPoints = 3;
                continue;
            }
            else 
            {
                break;
            }
        }
    }
}