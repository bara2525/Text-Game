//
// Created by Barunka on 05.05.2021.
//

#ifndef GAME1_VULCANPLAYERBUILDER_H
#define GAME1_VULCANPLAYERBUILDER_H

#include "PlayerBuilder.h"

class VulcanPlayerBuilder: public PlayerBuilder {
public:
    void setMaxHealth() override;
    void setMaxEnergy() override;
    void setEnergy() override;
    void setHealth() override;
    void setAttack() override;
};


#endif //GAME1_VULCANPLAYERBUILDER_H
