//
// Created by Termi27 on 07/05/2021.
//

#include "Potion.h"

Potion::Potion(std::string itemName, std::string type, int itemWeight, int itemPrice, int bonus) : Item(itemName, type, itemWeight, itemPrice){
    m_bonus = bonus;
}

int Potion::getBonus() {
    return m_bonus;
}

void Potion::showInfo() {
    std::cout << "Nazev: " << m_itemName << std::endl;
    std::cout << "Typ: " << m_type << std::endl;
    std::cout << "Vaha: " << m_itemWeight << std::endl;
    std::cout << "Cena: " << m_itemPrice << std::endl;
    std::cout << "Tento lektvar vyleci "<<m_bonus << " zdravi"<<std::endl;
}


