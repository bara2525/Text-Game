//
// Created by Barunka on 29.04.2021.
//

#include "Player.h"
#include "Location.h"

Player::Player() {
    m_name = "";
    m_health = 0;
    m_credits = 100;
    m_energy = 0;
    m_attack = 0;
    m_defense = 0;
    m_inventorySlot = nullptr;
    m_maxHealth = 0;
    m_maxEnergy = 0;

}


void Player::setAttack(int attack) {
    m_attack = attack;
}

void Player::setName(std::string name) {
    m_name = name;
}

void Player::setHealth(int health) {
    m_health = health;
}
void Player::setMaxHealth(int health) {
    m_maxHealth = health;
}
std::string Player::getName() {
    return m_name;
}

int Player::getHealth() {
    return m_health;
}

void Player::setCredits(int credits) {
    m_credits = credits;
}

int Player::getCredits() {
    return m_credits;
}

void Player::setEnergy(int energy) {
    m_energy = energy;
}

void Player::setMaxEnergy(int energy) {
    m_maxEnergy = energy;
}

int Player::getEnergy() {
    return m_energy;
}
int Player::getMaxEnergy() {
    return m_maxEnergy;
}
int Player::getMaxHealth() {
    return m_maxHealth;
}


int Player::getAttack() {
    if (m_inventorySlot->getWeaponSlot() == nullptr){
        return m_attack; //základní útok, jako pěsti
    }
    else{
        return m_attack + m_inventorySlot->getWeaponSlot()->getWeaponDamage();
    }
}

int Player::getDefense() {
    if (m_inventorySlot->getShieldSlot() == nullptr){
        return m_defense; //základní defense, idk, asi 0
    }
    else{
        return m_defense + m_inventorySlot->getShieldSlot()->getShield();
    }
}


void Player::showInfo() {
    std::cout << "Jmenuji se: " << getName() << std::endl;
    std::cout << "Zivoty: " << getHealth() << std::endl;
    std::cout << "Energie: " << getEnergy() << std::endl;
    std::cout << "Kredity: " << getCredits() << std::endl;
    std::cout << "Maximalni nosnost: " << m_inventorySlot->getMaxWeight() << std::endl;
    std::cout << "Utok: " << getAttack() << std::endl;
    std::cout << "Obrana: " << getDefense() << std::endl;
    std::cout << " -----------------"<<std::endl;
}

void Player::equipInventory(Inventory* inventory) {
    if (m_inventorySlot == nullptr){
        m_inventorySlot = inventory;
    }
    else{
        std::cout << "??????????????????????aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa??????????????????????????" << std::endl;
    }
}

Inventory *Player::getInventory() {
    return m_inventorySlot;
}

