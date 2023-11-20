//
// Created by Octa on 15.11.2023.
//
#include "Game/game.h"
#include<iostream>

int main() {
    Game game;
    game.run();

    Player originalPlayer;
    std::cout << "Original Player: " << originalPlayer << std::endl;

    Player copiedPlayer = originalPlayer;
    std::cout << "Copied Player: " << copiedPlayer << std::endl;


    return 0;
}
