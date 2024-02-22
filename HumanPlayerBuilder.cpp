//
// Created by Barunka on 05.05.2021.
//

#include "HumanPlayerBuilder.h"

void HumanPlayerBuilder::setMaxEnergy() {
    m_player->setMaxEnergy(100);
}
void HumanPlayerBuilder::setEnergy() {
    m_player->setEnergy(100);
}

void HumanPlayerBuilder::setMaxHealth() {
    m_player->setMaxHealth(170);
}

void HumanPlayerBuilder::setHealth() {
    m_player->setHealth(170);
}

void HumanPlayerBuilder::setAttack() {
    m_player->setAttack(100);
}
