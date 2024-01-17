#include "Asteroid.h"
//

Asteroid::Asteroid(float size, sf::Vector2f position) {
    shape.setRadius(size);
    shape.setOrigin(size, size);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
}

bool Asteroid::operator==(const Asteroid& other) const {
    return shape.getPosition() == other.shape.getPosition();
}


std::ostream& operator<<(std::ostream& os, const Asteroid& asteroid){

    os << "Asteroid: Position(" << asteroid.shape.getPosition().x << ", " << asteroid.shape.getPosition().y << ")";

    return os;
}

Asteroid::~Asteroid() {

}


void Asteroid::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Asteroid::getBounds() const {
    return shape.getGlobalBounds();
}

