//
// Created by Octa on 15.11.2023.
//


// game.h
#pragma once
#include <SFML/Graphics.hpp>
#include "../Bullet/Bullet.h"
#include "../Player/Player.h"
#include "../Asteroids/Asteroid.h"
#include "../score.h"
class Game {
public:
    friend std::ostream& operator<<(std::ostream& os, const Game& gm);

    Game();
    void run();

private:
    bool inMenu;
    sf::Font font;
    sf::RectangleShape startButton;
    sf::RectangleShape exitButton;
    sf::Text startText;
    sf::Text exitText;
    sf::RenderWindow window;
    Player player;
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    TimeBasedScore timeScore;
    ComboScore comboScore;
    AsteroidHitScore asteroidScore;
    TotalScore totalScore;
    int numAsteroids{};
    void handleInput();
    void update();
    void render();
    void spawnAsteroid();
    void handleCollisions();
    void drawMenu();
    void handleMenuInput();

};