#pragma once
#include <SFML/Graphics.hpp>

class Asteroid {
public:
    Asteroid(float size, sf::Vector2f position);

    bool operator==(const Asteroid& other) const;

    void update(){

    };
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::CircleShape shape;
};
