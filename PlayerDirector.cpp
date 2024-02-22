//
// Created by Barunka on 05.05.2021.
//

#include "PlayerDirector.h"

PlayerDirector::PlayerDirector(PlayerBuilder *builder) {
    m_builder = builder;
}

void PlayerDirector::setPlayerBuilder(PlayerBuilder *builder) {
    m_builder = builder;
}

Player *PlayerDirector::constructPlayer() {
    m_builder->createPlayer();
    m_builder->setMaxHealth();
    m_builder->setHealth();
    m_builder->setMaxEnergy();
    m_builder->setEnergy();
    m_builder->setAttack();
    return m_builder->getPlayer();
}
