//
// Created by Termi27 on 30/04/2021.
//

#ifndef GAME1_ITEM_H
#define GAME1_ITEM_H
#include "iostream"

class Item {
protected:
    std::string m_itemName;
    std::string m_type;
    int m_itemWeight;
    int m_itemPrice;

public:
    Item(std::string itemName,std::string type , int itemWeight, int itemPrice);
    std::string getItemName();
    std::string getType();
    int getItemWeight();
    int getItemPrice();
    virtual void showInfo();

};


#endif //GAME1_ITEM_H
