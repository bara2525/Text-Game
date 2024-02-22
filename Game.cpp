//
// Created by Barunka on 29.04.2021.
//

#include "Game.h"



Game::Game() {
    m_variable = "";
    m_variable1 = "";
    m_player = nullptr;
    m_currentLocation = nullptr;
    Inventory* i1 = new Inventory();
    playerSetter();
    m_player->equipInventory(i1);
    locationEnemySetter();

}

void Game::locationEnemySetter(){
        //incializade nepratel
    Enemy* kraken = Enemy::createEnemy(DifficultyPick::Kraken);
    Enemy* trpaslik = Enemy::createEnemy(DifficultyPick::Trpaslik);
    Enemy* drak = Enemy::createEnemy(DifficultyPick::Drak);
    Enemy* obr = Enemy::createEnemy(DifficultyPick::Obr);

        //inicializace lokaci
    Location* les = new Location("les",m_player);
    m_location.push_back(les);
    Location* poust = new Location("poust",m_player);
    m_location.push_back(poust);
    Location* mesto = new Location("mesto",m_player);
    m_location.push_back(mesto);
    Location* hrad = new Location("hrad",m_player);
    m_location.push_back(hrad);
    Location* more = new Location("more",m_player);
    m_location.push_back(more);
    Location* hospoda = new Location("hospoda",m_player);
    m_location.push_back(hospoda);
    Location* jeskyne = new Location("jeskyne",m_player);
    m_location.push_back(jeskyne);

        //pridani sousedu
    les->setNeighbours(poust);
    les->setNeighbours(mesto);

    poust->setNeighbours(les);
    poust->setNeighbours(hrad);

    mesto->setNeighbours(les);
    mesto->setNeighbours(hospoda);
    mesto->setNeighbours(more);

    hrad->setNeighbours(poust);
    hrad->setNeighbours(more);

    more->setNeighbours(hrad);
    more->setNeighbours(mesto);

    hospoda->setNeighbours(mesto);
    hospoda->setNeighbours(jeskyne);

    jeskyne->setNeighbours(hospoda);

        //pridani nepratel
    les->setEnemy(trpaslik);
    more->setEnemy(kraken);
    hrad->setEnemy(obr);
    hospoda->setEnemy(drak);

        //itemy
    Weapon* weapon1 = new Weapon("Mec","Weapon",10,100,25);
    Shield* shield1 = new Shield("Generator stitu","Shield",20,150,5);
    Weapon* weapon2 = new Weapon("Excalibur","Weapon",5,1000,70);
    Potion* potion1 = new Potion("Pivo Demon", "Potion", 2, 27, 20);
    Key* key1 = new Key("Klicek 27", "Key", 1, 200, "Tento klicek odemyka me srdce nebo neco takoveho, probably spis pasuje do dveri od sklepa kde schovavam pivo hihi");

    //pridani itemu
    more->setItem(key1);
    hrad->setItem(weapon2);
    poust->setItem(shield1);
    les->setItem(weapon1);
    mesto->setItem(potion1);

    m_currentLocation = les;
}


void Game::playerSetter(){
    std::cout<<"Zvol si rasu sve postavy:"<<std::endl;
    std::cout<<"[h]uman"<<std::endl;
    std::cout<<"[v]ulcan"<<std::endl;
    std::cin>>m_variable1;

    if (m_variable1[0] == 'h'){
        PlayerDirector* playerDirector = new PlayerDirector(new HumanPlayerBuilder);
        Player* p1 = playerDirector->constructPlayer();
        m_player = p1;
    }else{if(m_variable1[0] == 'v'){
        PlayerDirector* playerDirector = new PlayerDirector(new VulcanPlayerBuilder);
        Player* p1 = playerDirector->constructPlayer();
        m_player = p1;}
    else{
        std::cout<<"Zadal jsi spatne, zkus to znova."<<std::endl;
        playerSetter();
    }

}}

void Game::start() {
    bool running;
    running = true;
std::cout<<"Kour a nesnesitelne pipani. Toto by probudilo i mrtveho. Mraz mi projel po zadech. Co se vlastne stalo? Na nic si nevzpominam. Jak se jmenuju?"<<std::endl;
std::cin>>m_variable;
std::cout<<m_variable;
m_player->setName(m_variable);
std::cout<<std::endl;

std::cout<<std::endl<<"Uff, aspon to si jeste pamatuju. Je cas se poradne porozhlednout po okoli a zjistit, co se stalo.";
std::cout<<"Vypada to, ze sedis v nejake lodi a ze vsech pristroju kolem se kouri. Asi by nebylo nejmoudrejsi zde zustavat delsi dobu, nez je nutne. Proto se snazim dostat ven. Nakonec se podari a stojis na pevne zemi. Nekde uprostred lesa. Vypada to, ze jsem s lodi havaroval, pomyslim si.";
std::cout<<"Sahnes rukama do kapes, nebot tak to normalne delam, kdyz jsem v hlubokem premysleni. Tvoje prsty narazi uvnitr kapsy na nejaky papir. Vytahnes ho a poradne si ho prohlednes. Je to dopis od nejakeho ????. Z tonu dopisu vyplyva, ze jsi jeho pritel. zada te, abyste se potkali na planete ??? a abys po ceste vyzvedl tu vec. Jakou vec? To nepise, na druhe strane papiru je mapa. A hele, je tam zakresleny i les. Pokud budeme tedy na moment, predpokladat, ze jsme na spravne planete, tak bychom mohli tu vec najit.";
std::cout<<" cerveny krizek se nachazi nedaleko nejakeho jezera. Na mape je tez vyznacene mesto.";
std::cout<< "Avsak ty jsi uprostred lesa. Mohl bys zkusit jit na sever, tam se zda, ze je i nejaka pesinka, nebo se muzes zkusit prodirat na vychod, tak co to bude?"<<std::endl<<std::endl;;


while (running){
changeLocation(m_currentLocation);

if (m_currentLocation->getNazev() == "jeskyne"){
    std::cout<<"Je zde treba klic, mas ho?"<<std::endl;
    if (m_player->getInventory()->getKey()){
        std::cout<<"Mas klic, tak muzes projit."<<std::endl;
        std::cout<<"Potkas sveho pritele v jeskyni, bohuzel neni tim kym se zdal a vylakal te sem schvalne, musis se s nim utkat."<<std::endl;
        std::cout<<"--KONEC HRY--"<<std::endl;
        running = false;

    }else{
        std::cout<<"Nemas klic, vracis se zpet."<<std::endl;
        m_currentLocation = m_location.at(6);       //pokud by bylo více lokací je potřeba přepsat 6 a místo toho dát m_location.size()-1
    }}
}
}


void Game::changeLocation(Location *location) {
    std::string name;
    name = location->ShowInfo();
    for (int i = 0; i<m_location.size();i++){
        if (name == m_location.at(i)->getNazev()){
            m_currentLocation = m_location.at(i);
        }
    }
}






