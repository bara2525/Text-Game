//
// Created by Barunka on 05.05.2021.
//

#include "VulcanPlayerBuilder.h"

void VulcanPlayerBuilder::setMaxEnergy() {
    m_player->setMaxEnergy(120);
}
void VulcanPlayerBuilder::setEnergy() {
    m_player->setEnergy(120);
}

void VulcanPlayerBuilder::setMaxHealth() {
    m_player->setMaxHealth(150);
}

void VulcanPlayerBuilder::setHealth() {
    m_player->setHealth(150);
}

void VulcanPlayerBuilder::setAttack() {
    m_player->setAttack(80);
}
