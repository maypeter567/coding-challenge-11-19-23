//
// Created by Peter May on 2023-11-19.
//

#include <iostream>
#include "Game.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        cerr << "Usage: " << argv[0] << " doesn't take inputs";
        return 1;
    }
    Game game;
    game.run();
    return 0;
}
