//
// Created by Termi27 on 30/04/2021.
//

#include "Weapon.h"

Weapon::Weapon(std::string itemName,std::string type, int itemWeight, int itemPrice, int weaponDamage) : Item(itemName, type, itemWeight, itemPrice) {
    m_itemName = itemName;
    m_type = type;
    m_itemWeight = itemWeight;
    m_itemPrice = itemPrice;
    m_weaponDamage = weaponDamage;

}

int Weapon::getWeaponDamage() {
    return m_weaponDamage;
}

void Weapon::showInfo() {
    std::cout << "Nazev: " << m_itemName << std::endl;
    std::cout << "Typ: " << m_type << std::endl;
    std::cout << "Vaha: " << m_itemWeight << std::endl;
    std::cout << "Cena: " << m_itemPrice << std::endl;
    std::cout << "Damage: " << m_weaponDamage << std::endl;
}
