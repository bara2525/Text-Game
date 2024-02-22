//
// Created by Termi27 on 30/04/2021.
//

#ifndef GAME1_WEAPON_H
#define GAME1_WEAPON_H
#include "Item.h"

class Weapon: public Item{
    int m_weaponDamage;
public:
    Weapon(std::string itemName,std::string type, int itemWeight, int itemPrice, int weaponDamage);
    int getWeaponDamage();
    void showInfo() override;
};


#endif //GAME1_WEAPON_H
