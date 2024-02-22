//
// Created by Termi27 on 30/04/2021.
//

#include "Item.h"

Item::Item(std::string itemName,std::string type, int itemWeight, int itemPrice) {
    m_itemName = itemName;
    m_type = type;
    m_itemWeight = itemWeight;
    m_itemPrice = itemPrice;

}

std::string Item::getItemName() {
    return m_itemName;
}

int Item::getItemWeight() {
    return m_itemWeight;
}

int Item::getItemPrice() {
    return m_itemPrice;
}

std::string Item::getType() {
    return m_type;
}

void Item::showInfo() {
    std::cout << "Nazev: " << m_itemName << std::endl;
    std::cout << "Typ: " << m_type << std::endl;
    std::cout << "Vaha: " << m_itemWeight << std::endl;
    std::cout << "Cena: " << m_itemPrice << std::endl;
}
