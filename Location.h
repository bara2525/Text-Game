//
// Created by Barunka on 30.04.2021.
//

#ifndef GAME1_LOCATION_H
#define GAME1_LOCATION_H
#include "Enemy.h"
#include<vector>
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <iomanip>

class Location {
    std::string m_nazev;
    Player* m_player;
    Enemy* m_enemy;
    std::vector<Location*> m_location;
    Item* m_item;
    int m_pokus;
public:
    Location(std::string nazev, Player* player);
    std::string getNazev();
    void setNeighbours(Location* location);
    std::string ShowInfo();
    std::vector<Location*>getListOfNeighbours();
    void setEnemy(Enemy* enemy);
    void setItem(Item* item);
    void showNeighbours();
    std::string options();



};


#endif //GAME1_LOCATION_H
