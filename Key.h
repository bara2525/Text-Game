//
// Created by Termi27 on 07/05/2021.
//

#ifndef GAME1_KEY_H
#define GAME1_KEY_H
#include "Item.h"

class Key: public Item{
    std::string m_key;
public:
    Key(std::string itemName,std::string type, int itemWeight, int itemPrice, std::string key);
    void showInfo() override;
};


#endif //GAME1_KEY_H
