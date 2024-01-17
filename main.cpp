//
// Created by Octa on 15.11.2023.
//
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

    TimeBasedScore originalTimeScore;
    originalTimeScore.updateScore();

    std::cout << "Original Time Score: " << originalTimeScore.getScore() << std::endl;

    TimeBasedScore copiedTimeScore = originalTimeScore;

    std::cout << "Copied Time Score: " << copiedTimeScore.getScore() << std::endl;

    try {
        game.run();
    } catch (const AsteroidException& e) {
        std::cerr << "Asteroid Exception: " << e.what() << std::endl;
    }

    return 0;
}
