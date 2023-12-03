#pragma once
#include <SFML/Graphics.hpp>

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
