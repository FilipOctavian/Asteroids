#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
public:
    friend std::ostream& operator<<(std::ostream& os, const Bullet& bt);

    Bullet(sf::Vector2f playerPosition, float playerRotation);
    void update();
    void draw(sf::RenderWindow &window);
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
};

