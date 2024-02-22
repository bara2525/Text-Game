//
// Created by Termi27 on 02/05/2021.
//

#include "Shield.h"

Shield::Shield(std::string itemName, std::string type ,int itemWeight, int itemPrice, int shield) : Item(itemName, type, itemWeight, itemPrice) {
    m_itemName = itemName;
    m_type = type;
    m_itemWeight = itemWeight;
    m_itemPrice = itemPrice;
    m_shield = shield;

}

int Shield::getShield() {
    return m_shield;
}

void Shield::showInfo() {
    std::cout << "Nazev: " << m_itemName << std::endl;
    std::cout << "Typ: " << m_type << std::endl;
    std::cout << "Vaha: " << m_itemWeight << std::endl;
    std::cout << "Cena: " << m_itemPrice << std::endl;
    std::cout << "Defense: " << m_shield << std::endl;
}
