//
// Created by Barunka on 29.04.2021.
//

#ifndef GAME1_PLAYER_H
#define GAME1_PLAYER_H
#include <iostream>
#include "Inventory.h"

class Player {
    int m_health;
    std::string m_name;
    int m_credits;
    int m_energy;
    int m_attack;
    int m_defense;
    int m_maxHealth;
    int m_maxEnergy;
    Inventory* m_inventorySlot;


public:
    Player();
    void setName(std::string name);
    void setHealth(int health);
    void setMaxHealth(int health);
    void setAttack(int attack);
    void setEnergy(int energy);
    void setMaxEnergy(int energy);

    std::string getName();
    int getHealth();
    int getEnergy();
    int getAttack();
    int getDefense();
    int getMaxHealth();
    int getMaxEnergy();

    void equipInventory(Inventory* inventory);

    void setCredits(int credits);
    int getCredits();

    void showInfo();

    Inventory* getInventory();





};


#endif //GAME1_PLAYER_H
