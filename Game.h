

#ifndef GAME1_GAME_H
#define GAME1_GAME_H
#include <vector>
#include <iostream>
#include "Drak.h"
#include "Player.h"
#include "Location.h"
#include "Trpaslik.h"
#include "Inventory.h"
#include "PlayerBuilder.h"
#include "DifficultyPick.h"
#include "PlayerDirector.h"
#include "HumanPlayerBuilder.h"
#include "VulcanPlayerBuilder.h"


class Game {
    Player* m_player;
    std::string m_variable;
    std::string m_variable1;
    std::vector<Location*> m_location;
    Location* m_currentLocation;
public:
    Game();
    void start();
    void changeLocation(Location* location);
    void locationEnemySetter();
    void playerSetter();


};


#endif //GAME1_GAME_H
