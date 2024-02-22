//
// Created by Barunka on 05.05.2021.
//

#ifndef GAME1_HUMANPLAYERBUILDER_H
#define GAME1_HUMANPLAYERBUILDER_H
#include "PlayerBuilder.h"
#include "Player.h"

class HumanPlayerBuilder: public PlayerBuilder {
public:
    void setMaxEnergy() override;
    void setEnergy() override;
    void setMaxHealth() override;
    void setHealth() override;
    void setAttack() override;


};


#endif //GAME1_HUMANPLAYERBUILDER_H
