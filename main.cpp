#include <iostream>

#include "Game.h"

int main() {
    Game* g1 = new Game();
    g1->start();

    delete g1;
    return 0;
}
