//
// Created by Barunka on 05.05.2021.
//

#ifndef GAME1_PLAYERBUILDER_H
#define GAME1_PLAYERBUILDER_H

#include "Player.h"

class PlayerBuilder {
protected:
    Player* m_player;
public:
    PlayerBuilder();
    void createPlayer();
    virtual void setMaxHealth()=0;
    virtual void setMaxEnergy()=0;
    virtual void setEnergy()=0;
    virtual void setHealth()=0;
    virtual void setAttack()=0;
    Player* getPlayer();
};


#endif //GAME1_PLAYERBUILDER_H
