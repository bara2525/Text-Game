//
// Created by Termi27 on 02/05/2021.
//

#ifndef GAME1_SHIELD_H
#define GAME1_SHIELD_H
#include "Item.h"

class Shield: public Item {
    int m_shield;
public:
    Shield(std::string itemName,std::string type, int itemWeight, int itemPrice, int shield);
    int getShield();
    void showInfo() override;
};


#endif //GAME1_SHIELD_H
