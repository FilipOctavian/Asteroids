#pragma once
#include <SFML/Graphics.hpp>
#include "../Asteroids/Asteroid.h"

class Bullet {
public:

    friend std::ostream& operator<<(std::ostream& os, const Bullet& bt);
    bool operator==(const Bullet& other) const;

    Bullet(sf::Vector2f playerPosition, float playerRotation);
    void update();
    void draw(sf::RenderWindow &window);
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;

};

