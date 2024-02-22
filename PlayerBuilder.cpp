//
// Created by Barunka on 05.05.2021.
//

#include "PlayerBuilder.h"


PlayerBuilder::PlayerBuilder() {
    m_player = nullptr;
}

void PlayerBuilder::createPlayer() {
    m_player = new Player();
}

Player *PlayerBuilder::getPlayer() {
    return m_player;
}
