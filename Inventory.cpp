//
// Created by Termi27 on 05/05/2021.
//

#include "Inventory.h"

Inventory::Inventory() {
    m_maxWeight = 100;
    m_weaponSlot = nullptr;
    m_shieldSlot = nullptr;
}

int Inventory::getMaxWeight() {
    return m_maxWeight;
}

bool Inventory::canItFit(Item *item) {
    if ((inventoryWeight() + item->getItemWeight()) <= m_maxWeight){
        return true;
    }
    else {
        return false;
    }
}

void Inventory::addItem(Item* item) {
    if (canItFit(item)){
        m_inventory.push_back(item);
    }
    else{
        std::cout << item->getItemName() <<" se do inventare uz nevleze" << std::endl;
    }
}

void Inventory::removeItem(int item) {
    m_inventory.erase(m_inventory.begin()+item);
}

void Inventory::showInventory() {
    if (m_inventory.empty()){
        std::cout << "Inventar je prazdny" << std::endl;
    }
    else{
        std::cout << "Tvuj inventar obsahuje: " << std::endl;
        for (int i = 0; i < m_inventory.size();i++){
            std::cout << "Predmet cislo " << i << ": " << std::endl;
            m_inventory.at(i)->showInfo();
            std::cout << "****************************" << std::endl;
        }
        std::cout << "Obsah tveho inventare vazi: " << inventoryWeight() << std::endl;
    }
    if (m_weaponSlot != nullptr){
        std::cout << "Jsi vybaven zbrani: "<<std::endl;
        m_weaponSlot->showInfo();
    }
    else{
        std::cout << "Nemas zadnou zbran" << std::endl;
    }
    if (m_shieldSlot != nullptr){
        std::cout << "Jsi vybaven generatorem stitu: "<<std::endl;
        m_weaponSlot->showInfo();
    }
    else{
        std::cout << "Nemas zadny generator stitu" << std::endl;
    }
}

bool Inventory:: getKey(){
    bool m_variable;
    m_variable = false;
    for (int i = 0; i < m_inventory.size();i++){
        if (m_inventory.at(i)->getType() == "Key"){
            m_variable = true;
        }else{
            m_variable =false;
        }}
    return m_variable;}




int Inventory::inventoryWeight() {
    if (m_inventory.empty()){
        return 0;
    }
    else{
        int vaha=0;
        for (int i = 0; i < m_inventory.size();i++){
            vaha += m_inventory.at(i)->getItemWeight();
        }
        return vaha;
    }
}

void Inventory::inventoryMenu() {
    int variable2;
    std::cout<<"Co chces delat?"<<std::endl;
    std::cout<<"0 - vypis inventare"<<std::endl;
    std::cout<<"1 - zahodit predmet"<<std::endl;
    std::cout<<"2 - vybavit zbran"<<std::endl;
    std::cout<<"3 - sundat zbran"<<std::endl;
    std::cout<<"4 - vybavit generator stitu"<<std::endl;
    std::cout<<"5 - sundat generator stitu"<<std::endl;
    std::cout<<"Tvoje volba: ";
    std::cin>>variable2;
    std::cout<<"-----------------"<<std::endl;
    switch (variable2) {

        case 0:
            showInventory();
            std::cout<<"-----------------"<<std::endl;

            break;

        case 1: {
            showInventory();
            int predmet;
            if (inventoryWeight() != 0){
                std::cout << "Vyber pozici predmetu co chces zahodit: ";
                std::cin>>predmet;
                if (predmet <= m_inventory.size()){
                    removeItem(predmet);
                }
                else{
                    std::cout << "Spatna pozice v inventari" << std::endl;
                }
            }
            else{
                std::cout << "Tvuj inventar je prazdny, nemuzes nic zahodit" << std::endl;
            }

            std::cout<<"-----------------"<<std::endl;
            break;
        }

        case 2: {
            showInventory();
            int zbran;
            if (inventoryWeight() != 0) {
                std::cout << "Vyber pozici zbrane co si chces nasadit: ";
                std::cin >> zbran;
                if (zbran <= m_inventory.size()){
                    equipWeapon(zbran);
                }
                else{
                    std::cout << "Spatna pozice v inventari" << std::endl;
                }
            }
            else{
                std::cout << "Tvuj inventar je prazdny, nemuzes si nic nasadit" << std::endl;
            }
            std::cout<<"-----------------"<<std::endl;
            break;
        }
        case 3:
            if (m_weaponSlot != nullptr){
                unequipWeapon();
                std::cout << "Sundal sis zbran" << std::endl;
            }
            else{
                std::cout << "Tvuj slot na zbran je prazdny, nemuzes si ji sundat" << std::endl;
            }

            std::cout<<"-----------------"<<std::endl;
            break;
        case 4:{
            showInventory();
            int stit;
            if (inventoryWeight() != 0) {
                std::cout << "Vyber pozici generatoru stitu co si chces nasadit: ";
                std::cin >> stit;
                if (stit <= m_inventory.size()){
                    equipShield(stit);
                }
                else{
                    std::cout << "Spatna pozice v inventari" << std::endl;
                }
            }
            else{
                std::cout << "Tvuj inventar je prazdny, nemuzes si nic nasadit" << std::endl;
            }
            std::cout<<"-----------------"<<std::endl;
            break;
        }

        case 5:
            if (m_weaponSlot != nullptr) {
                unequipShield();
                std::cout << "Sundal sis generator stitu" << std::endl;
            }
            else {
                std::cout << "Tvuj slot na generator stitu je prazdny, nemuzes si ho sundat" << std::endl;
            }

            std::cout<<"-----------------"<<std::endl;
            break;

        default:
            std::cout<<"Zadal jsi spatne cislo, zkus to znova"<<std::endl;
            std::cout<<"-----------------"<<std::endl;
            inventoryMenu();
            break;
    }
}

void Inventory::equipWeapon(int weapon) {
    if (m_weaponSlot == nullptr){
        if (m_inventory.at(weapon)->getType() == "Weapon"){
            m_weaponSlot = dynamic_cast<Weapon *>(m_inventory.at(weapon));
            m_inventory.erase(m_inventory.begin()+weapon);
        }
        else{
            std::cout << "Toto neni zbran" << std::endl;
        }

    }
    else{
        std::cout << "Uz mas zbran nasazenou" << std::endl;
    }
}

void Inventory::unequipWeapon() {
    addItem(m_weaponSlot);
    m_weaponSlot = nullptr;
}

void Inventory::equipShield(int shield) {
    if (m_shieldSlot == nullptr){
        if (m_inventory.at(shield)->getType() == "Shield"){
            m_shieldSlot = dynamic_cast<Shield *>(m_inventory.at(shield));
            m_inventory.erase(m_inventory.begin()+shield);
        }
        else{
            std::cout << "Toto neni generator stitu" << std::endl;
        }

    }
    else{
        std::cout << "Uz mas generator stitu nasazeny" << std::endl;
    }
}

void Inventory::unequipShield() {
    addItem(m_shieldSlot);
    m_shieldSlot = nullptr;
}

Weapon *Inventory::getWeaponSlot() {
    return m_weaponSlot;
}

Shield *Inventory::getShieldSlot() {
    return m_shieldSlot;
}

Potion *Inventory::getPotion(int potion) {
    if (potion <= m_inventory.size()){
        if (m_inventory.at(potion)->getType() == "Potion"){
            return dynamic_cast<Potion *>(m_inventory.at(potion));
        }
        else{
            std::cout << "Toto neni lektvar" << std::endl;
            return nullptr;
        }
    }
    else{
        std::cout << "Spatna pozice v inventari" << std::endl;
        return nullptr;
    }
}

/*
void Player::buyItem(Item* item) {
    if (canItFit(item)){
        m_credits -= item->getItemPrice();
        addItem(item);
    }
    else{
        std::cout << item->getItemName() <<" se do inventare uz nevleze" << std::endl;
    }
}

void Player::sellItem(Item* item) {
    m_credits += item->getItemPrice();
    removeItem(item);
}
*/