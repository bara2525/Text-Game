//
// Created by Barunka on 05.05.2021.
//

#ifndef GAME1_PLAYERDIRECTOR_H
#define GAME1_PLAYERDIRECTOR_H

#include "PlayerBuilder.h"
#include "Player.h"

class PlayerDirector {
    PlayerBuilder* m_builder;
public:
    PlayerDirector(PlayerBuilder* builder);
    void setPlayerBuilder(PlayerBuilder* builder);
    Player* constructPlayer();
};


#endif //GAME1_PLAYERDIRECTOR_H
