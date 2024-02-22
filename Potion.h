//
// Created by Termi27 on 07/05/2021.
//

#ifndef GAME1_POTION_H
#define GAME1_POTION_H
#include "Item.h"

class Potion: public Item {
    int m_bonus;
public:
    Potion(std::string itemName,std::string type, int itemWeight, int itemPrice, int bonus);
    int getBonus();
    void showInfo() override;
};


#endif //GAME1_POTION_H
