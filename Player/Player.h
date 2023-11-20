#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../Bullet/Bullet.h"
#include <vector>

class Player {
public:
    friend std::ostream& operator<<(std::ostream& os, const Player& pl);

    Player();
    Player& operator=(const Player& player);
    void init();
    void update();
    void draw(sf::RenderWindow& window);
    void fireBullet(std::vector<Bullet>& bullets);

private:
    sf::ConvexShape shape;
    sf::Vector2f position;
    float rotation{};
    float speed;
};
