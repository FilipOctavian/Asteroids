#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <valarray>

Player::Player() {
    speed = 3.0f;
    shape.setPointCount(3);
    shape.setPoint(0, sf::Vector2f(0, -20));
    shape.setPoint(1, sf::Vector2f(-15, 15));
    shape.setPoint(2, sf::Vector2f(15, 15));
    shape.setFillColor(sf::Color::Blue);
    init();
}

Player::Player(const Player& other) {
    // Copiază atributele din alt jucător
    this->speed = other.speed;
    this->shape = other.shape;
    this->position = other.position;
    this->rotation = other.rotation;
}

Player& Player::operator=(const Player& player){

    if (this != &player) {

        this->position = player.position;
        this->rotation = player.rotation;
        this->speed = player.speed;

    }
    return *this;

}


std::ostream& operator<<(std::ostream& os, const Player& pl){
    os << "Player: Position(" << pl.position.x << ", " << pl.position.y << "), Rotation(" << pl.rotation << ")";
    return os;
}


void Player::init() {
    position = sf::Vector2f(400, 300);
    rotation = 0.0f;
    shape.setPosition(position);
}



void Player::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rotation -= 5.0f; //rotation speed.
        shape.setRotation(rotation);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rotation += 5.0f; 
        shape.setRotation(rotation);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        position.y -= speed * std::cos(rotation * 3.14159265f / 180.0f);
        position.x += speed * std::sin(rotation * 3.14159265f / 180.0f);
        shape.setPosition(position);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        position.y += speed * std::cos(rotation * 3.14159265f / 180.0f);
        position.x -= speed * std::sin(rotation * 3.14159265f / 180.0f);
        shape.setPosition(position);
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Player::fireBullet(std::vector<Bullet>& bullets) {
    // Calculate the position of the bullet based on player's position and rotation
    sf::Vector2f bulletPosition(
            position.x + 20.0f * std::sin(rotation * 3.14159265f / 180.0f),
            position.y - 20.0f * std::cos(rotation * 3.14159265f / 180.0f)
    );

    Bullet bullet(bulletPosition, rotation);
    bullets.push_back(bullet);
}


