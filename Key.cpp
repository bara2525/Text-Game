//
// Created by Termi27 on 07/05/2021.
//

#include "Key.h"

Key::Key(std::string itemName, std::string type, int itemWeight, int itemPrice, std::string key) : Item(itemName, type, itemWeight, itemPrice){
    m_key = key;
}

void Key::showInfo() {
    std::cout << "Nazev: " << m_itemName << std::endl;
    std::cout << "Typ: " << m_type << std::endl;
    std::cout << "Vaha: " << m_itemWeight << std::endl;
    std::cout << "Cena: " << m_itemPrice << std::endl;
    std::cout << m_key << std::endl;
}
