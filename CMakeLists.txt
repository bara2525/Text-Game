cmake_minimum_required(VERSION 3.17)
project(game1)

set(CMAKE_CXX_STANDARD 14)

add_executable(game1 main.cpp Player.cpp Player.h Game.cpp Game.h Location.cpp Location.h Enemy.cpp Enemy.h Item.cpp Item.h Weapon.cpp Weapon.h Shield.cpp Shield.h DifficultyPick.h Trpaslik.cpp Trpaslik.h Drak.cpp Drak.h Kraken.cpp Kraken.h Obr.cpp Obr.h Inventory.cpp Inventory.h PlayerDirector.cpp PlayerDirector.h PlayerBuilder.cpp PlayerBuilder.h VulcanPlayerBuilder.cpp VulcanPlayerBuilder.h HumanPlayerBuilder.cpp HumanPlayerBuilder.h Key.cpp Key.h Potion.cpp Potion.h)

