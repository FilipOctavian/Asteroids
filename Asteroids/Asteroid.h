#pragma once
#include <SFML/Graphics.hpp>
#include <exception>
#include <string>

class Asteroid {
public:
    Asteroid(float size, sf::Vector2f position);

    ~Asteroid();

    bool operator==(const Asteroid& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Asteroid& asteroid);

    void update(){

    };
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::CircleShape shape;
};

class AsteroidException : public std::exception {
private:
    std::string message;

public:
    explicit AsteroidException(const std::string& msg) : message(msg) {}

    virtual const char* what() const throw() {
        return message.c_str();
    }
};
