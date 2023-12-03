//
// Created by Octa on 15.11.2023.
//


// game.h
#pragma once
#include <SFML/Graphics.hpp>
#include "../Bullet/Bullet.h"
#include "../Player/Player.h"
#include "../Asteroids/Asteroid.h"

class Game {
public:
    friend std::ostream& operator<<(std::ostream& os, const Game& gm);

    Game();
    void run();

private:
    sf::Font font;
    sf::Text startText;
    sf::Text exitText;
    sf::RenderWindow window;
    Player player;
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    bool isMenuActive;
    int numAsteroids{};
    void handleInput();
    void update();
    void render();
    void spawnAsteroid();
    void handleCollisions();

};
