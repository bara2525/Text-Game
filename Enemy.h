//
// Created by Barunka on 30.04.2021.
//

#ifndef GAME1_ENEMY_H
#define GAME1_ENEMY_H

#include <iostream>
#include <vector>
#include "DifficultyPick.h"


class Enemy{
protected:
    DifficultyPick m_difficultyPick;
    std::string m_name;
    int m_health;
    int m_strength;
    std::string m_dialog;     //Kdyby každá příšera byla vytvořena s nějakým dialogem nebo jen hláškou, hru by to možná oživilo.

//std::vector<Predmet*>m_predmet; //z nepřítele může a nemusí něco vypadnout po zabití. Stálo by za to zvážít.
    Enemy(DifficultyPick difficultyPick, std::string name, int health, int strength, std::string dialog);

public:
    static Enemy* createEnemy(DifficultyPick difficultyPick);
    int getHealth();
    int getStrength();
    virtual std::string getName();
    std::string getDialog();
    void setHealth(int health);
};


#endif //GAME1_ENEMY_H
