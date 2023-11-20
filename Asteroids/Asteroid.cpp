#include "Asteroid.h"

Asteroid::Asteroid(float size, sf::Vector2f position) {
    shape.setRadius(size);
    shape.setOrigin(size, size);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
}

bool Asteroid::operator==(const Asteroid& other) const {
    return shape.getPosition() == other.shape.getPosition();
}

std::ostream& operator<<(std::ostream& os, const Asteroid& ast){

    os << "Asteroid: Position(" << ast.shape.getPosition().x << ", " << ast.shape.getPosition().y << ")";

    return os;
}

Asteroid::~Asteroid() {

}

Asteroid::Asteroid(const Asteroid& other) {

    this->shape = other.shape;
}

void Asteroid::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Asteroid::getBounds() const {
    return shape.getGlobalBounds();
}

