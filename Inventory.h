//
// Created by Termi27 on 05/05/2021.
//

#ifndef GAME1_INVENTORY_H
#define GAME1_INVENTORY_H
#include <iostream>
#include <vector>
#include "Item.h"
#include "Weapon.h"
#include "Shield.h"
#include "Potion.h"
#include "Key.h"


class Inventory {
    int m_maxWeight;
    Weapon* m_weaponSlot;
    Shield* m_shieldSlot;
    std::vector<Item*> m_inventory;

public:
    Inventory();
    int getMaxWeight();
    bool canItFit(Item* item);

    void addItem(Item* item); //pro sebrání věci
    void removeItem(int item); //pro zahození/ztracení věci

    void showInventory();
    int inventoryWeight();

    void inventoryMenu();

    void equipWeapon(int weapon); //z inventáře do vybavení
    void unequipWeapon(); //z vybavení do inventáře

    void equipShield(int shield); //z inventáře do vybavení
    void unequipShield(); //z vybavení do inventáře

    bool getKey();

    Weapon* getWeaponSlot();
    Shield* getShieldSlot();

    Potion* getPotion(int potion);

    /*  void buyItem(Item* item);
  void sellItem(std::string item); */

};


#endif //GAME1_INVENTORY_H
