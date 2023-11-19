#include "Asteroid.h"

Asteroid::Asteroid(float size, sf::Vector2f position) {
    shape.setRadius(size);
    shape.setOrigin(size, size);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
}



void Asteroid::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Asteroid::getBounds() const {
    return shape.getGlobalBounds();
}
