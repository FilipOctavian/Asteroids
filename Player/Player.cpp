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
    Player& Player::operator=(const Player& player){

}
std::ostream& operator<<(std::ostream& os, const Player& pl){
    //os << pl.mo << '/' << pl.da << '/' << pl.yr;
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
    Bullet bullet(position, rotation);
    bullets.push_back(bullet);
}
