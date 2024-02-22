//
// Created by Barunka on 30.04.2021.
//

#include "Enemy.h"
#include "Trpaslik.h"
#include "Drak.h"
#include "Kraken.h"
#include "Obr.h"

Enemy *Enemy::createEnemy(DifficultyPick difficultyPick) {
    switch (difficultyPick) {
        case DifficultyPick::Trpaslik:
            new Trpaslik();
            break;
        case DifficultyPick::Drak:
            new Drak();
            break;
        case DifficultyPick::Kraken:
            new Kraken();
            break;
        case DifficultyPick::Obr:
            new Obr();
            break;
        default:
            break;
    }
}

Enemy::Enemy(DifficultyPick difficultyPick, std::string name, int health, int strength, std::string dialog) {
    m_name = name;
    m_health = health;
    m_strength = strength;
    m_dialog = dialog;
    m_difficultyPick = difficultyPick;

}

int Enemy::getHealth() {
    return m_health;
}

int Enemy::getStrength() {
    return m_strength;
}

std::string Enemy::getName() {
    return m_name;
}

std::string Enemy::getDialog() {
    return m_dialog;
}

void Enemy::setHealth(int health) {
    m_health = health;
}
