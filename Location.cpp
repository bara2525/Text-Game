//
// Created by Barunka on 30.04.2021.
//

#include "Location.h"

Location::Location(std::string nazev, Player* player) {
    m_nazev = nazev;
    m_player = player;
    m_enemy = nullptr;
    m_item = nullptr;
    m_pokus = 0;
}
std::string Location:: getNazev(){
    return m_nazev;
}
void Location::setNeighbours(Location* location){
    m_location.push_back(location);
}

std::vector<Location*> Location::getListOfNeighbours(){
    return  m_location;
}
void Location::showNeighbours(){
    std::cout<<std::endl<<"SEZNAM SOUSEDNICH LOKACI:"<<std::endl;
    std::cout<<"------------------------"<<std::endl;
    if(m_location.empty()){
        std::cout<<"- zadna sousedni lokace"<<std::endl;
    }else{
    for (int i =0; i < m_location.size(); i++){
        std::cout<<std::setw(5);
        std::cout<<i<<") "<<m_location.at(i)->getNazev();
        std::cout<<std::endl;
    }std::cout<<"------------------------"<<std::endl<<std::endl;
    }
}
std::string Location::ShowInfo() {
    std::string b;
    std::cout<<"| *** "<<m_nazev<<" *** |"<<std::endl<<std::endl;
    if (m_enemy == nullptr) {
        std::cout << "Nastesti zde neni nepritel"<<std::endl;
    }else{
        std::cout<<"Je zde nepritel "<<m_enemy->getName()<<std::endl;
    }
    showNeighbours();
    return options();

}
std::string Location::options(){

    int variable;
    std::cout<<"CO CHCES DELAT?"<<std::endl;
    std::cout<<"0 - cestovat"<<std::endl;
    std::cout<<"1 - prohledat"<<std::endl;
    std::cout<<"2 - spat"<<std::endl;
    std::cout<<"3 - inventar"<<std::endl;
    std::cout<<"4 - souboj s nepritelem"<<std::endl;
    std::cout<<"5 - vypit lektvar"<<std::endl;
    std::cout<<"6 - vypsat informace o postave"<<std::endl;
    std::cout<<"7 - ukoncit hru :')"<<std::endl;
    std::cout<<"Tvoje volba: ";
    std::cin>>variable;
    std::cout<<"-----------------"<<std::endl;
    switch (variable) {
        case 0:
            std::cout<<"Vybral jsi, ze chces cestovat, tam kam chces jet?"<<std::endl;
            showNeighbours();
            std::cin>>m_pokus;
            return getListOfNeighbours().at(m_pokus)->getNazev();
        case 1:
            if (m_item == nullptr){
                std::cout<<"Hledal jsi, ale marne."<<std::endl;
            }else{
                std::cout<<"Neco tu je!"<<std::endl;
                std::cout<<m_item->getItemName()<<std::endl;
                m_player->getInventory()->addItem(m_item);
                m_item = nullptr;
            }
            std::cout<<"-----------------"<<std::endl;
            options();
            break;

        case 2:
            if (m_player->getMaxEnergy() > m_player->getEnergy()+20){
                m_player->setEnergy(m_player->getEnergy()+20);
            }else{
                m_player->setEnergy(m_player->getMaxEnergy());
                std::cout<<"Uz mas plnou energii, ale stejne sis dal slofika."<<std::endl;
            }


            if (m_player->getMaxHealth() > m_player->getHealth()+20){
                m_player->setHealth(m_player->getHealth()+20);
            }else{
                m_player->setHealth(m_player->getMaxHealth());
                std::cout<<"Uz mas plne zdravi."<<std::endl;
            }

            std::cout<<"-Vyspal ses-"<<std::endl;
            m_player->showInfo();
            std::cout<<"-----------------"<<std::endl;
            options();
            break;
        case 3:
            m_player->getInventory()->inventoryMenu();
            std::cout<<"-----------------"<<std::endl;
            options();
            break;
        case 4:
            int a;
            int fight;
            fight = 0;
            if(m_enemy == nullptr){
                std::cout<<"Mas stesti, neni zde nepritel"<<std::endl;
            }else {
                std::cout<<m_enemy->getName()<<": ";
                std::cout<<m_enemy->getDialog()<<std::endl;
                while((m_enemy->getHealth() > 0 and m_player->getHealth() > 0) and fight == 0){
                    std::cout<<"Zadej volbu"<<std::endl;
                    std::cout<<"1: boj"<<std::endl;
                    std::cout<<"2: utek"<<std::endl;
                    std::cin>>a;
                    switch (a){
                    case 1:
                        m_enemy->setHealth(m_enemy->getHealth() - m_player->getAttack());
                            if(m_enemy->getStrength() > m_player->getDefense()){
                                m_player->setHealth(m_player->getHealth() - (m_enemy->getStrength()-m_player->getDefense()));}
                            std::cout << "Zbyva ti " << m_player->getHealth() << " zivota" << std::endl;
                            std::cout << "Nepriteli zbyva " << m_enemy->getHealth() << " zivota" << std::endl;
                            break;
                    case 2:
                        std::cout<<"Zbabele si utekl"<< std::endl;;
                        fight = 1;
                        break;
                    default:
                        std::cout<<"Zadal jsi spatne"<< std::endl;;
                            break;}
                }
            if (m_enemy->getHealth() <= 0){
                std::cout << "Vyhral jsi, nepritel byl premozen." << std::endl;
                m_enemy = nullptr;}
            if(m_player->getHealth() <= 0){
                std::cout << "Zemrel jsi." << std::endl;
                std::cout << "KONEC HRY" << std::endl;
                exit(0);}}

            options();
            break;

        case 5:
            if (m_player->getInventory()->inventoryWeight() != 0) {
                m_player->getInventory()->showInventory();
                int potion;
                std::cout << "Vyber pozici Potionu, ktery chces vypit: ";
                std::cin >> potion;
                if (m_player->getInventory()->getPotion(potion) != nullptr){
                    if (m_player->getMaxHealth() > (m_player->getInventory()->getPotion(potion)->getBonus()) + m_player->getHealth()){
                        m_player->setHealth(m_player->getHealth() + m_player->getInventory()->getPotion(potion)->getBonus());
                        std::cout << "Lektvar ti doplnil " << m_player->getInventory()->getPotion(potion)->getBonus() << " zivota! AYYYYYYYYYYY" << std::endl;
                        m_player->getInventory()->removeItem(potion);
                    }
                    else{
                        std::cout << "Zivota mas dost" << std::endl;
                    }

                }
                else{
                    std::cout << "Nemas zadny lektvar" << std::endl << std::endl;
                }

            }
            else{
                std::cout << "Tvuj inventar je prazdny, nemuzes si dat potion" << std::endl;
            }

            options();
            break;
        case 6:
            std::cout<<"*** PLAYER ***"<<std::endl;
            m_player->showInfo();
            options();
            break;

        case 7:
            std::cout<<"snad sis hru uzil";
            exit(0);
        default:
            std::cout<<"Zadal jsi spatne cislo, zkus to znova"<<std::endl;
            std::cout<<"-----------------"<<std::endl;
            options();
            break;

    }
    if(m_pokus<10){
    return getListOfNeighbours().at(m_pokus)->getNazev();}
    return "nothing";

}

void Location::setEnemy(Enemy* kraken) {
    m_enemy = kraken;
}
void Location::setItem(Item* item){
    m_item = item;
}
