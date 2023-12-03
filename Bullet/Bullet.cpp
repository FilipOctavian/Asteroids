#include "Bullet.h"
#include <cmath>

Bullet::Bullet(sf::Vector2f playerPosition, float playerRotation) {

    shape.setSize(sf::Vector2f(6.0f, 6.0f));
    shape.setOrigin(3.0f, 3.0f);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(playerPosition);

    float radians = playerRotation * 3.14159265f / 180.0f;
    float speed = 5.0f;
    velocity = sf::Vector2f(speed * std::sin(radians), -speed * std::cos(radians));
}
std::ostream& operator<<(std::ostream& os, const Bullet& bt){

    os << "Bullet: Position(" << bt.shape.getPosition().x << ", " << bt.shape.getPosition().y << ")";

    return os;
}


bool Bullet::operator==(const Bullet& other) const {
    // Compare relevant attributes for equality
    return shape.getPosition() == other.shape.getPosition();
}

void Bullet::update() {
    shape.move(velocity);
}

void Bullet::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

sf::FloatRect Bullet::getBounds() const {
    return shape.getGlobalBounds();
}



