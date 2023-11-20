//
// Created by Octa on 15.11.2023.
//

#include <SFML/Graphics.hpp>
#include "game.h"
#include "../Player/Player.h"
#include "../Asteroids/Asteroid.h"
#include "../Bullet/Bullet.h"

Game::Game() : window(sf::VideoMode(800, 600), "Simple Game"), player() {
    window.setFramerateLimit(60); // Set a frame rate limit for smooth rendering
    isMenuActive = true;
    initializeMenu();
}

std::ostream& operator<<(std::ostream& os, const Game& gm)
{
    os<<"Window dimensions:800x600";
    os << "Number of asteroids: " << gm.numAsteroids << "\n";
    return os;
}

void Game::initializeMenu() {

    font.loadFromFile("Font/ARIBLK.TTF");

    startText.setFont(font);
    startText.setString("Start Game");
    startText.setCharacterSize(30);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(300,200);

    exitText.setFont(font);
    exitText.setString("Exit Game");
    exitText.setCharacterSize(30);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(300, 300);
}
void Game::handleMenuInput() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // Check if the mouse is over the "Start Game" text
        if (startText.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            isMenuActive = false;
        }

        // Check if the mouse is over the "Exit Game" text
        if (exitText.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            window.close();
        }
    }
}

void Game::run() {
    while (window.isOpen()) {
        handleInput();
        update();
        render();
    }
}

void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if(isMenuActive){

        handleMenuInput();
     }



    // Fire bullets
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        player.fireBullet(bullets);
    }
}

void Game::update() {
    // Update player
    player.update();

    // Update asteroids
    for (auto& asteroid : asteroids) {
        asteroid.update();

    }

    // Update bullets
    for (auto& bullet : bullets) {
        bullet.update();
    }

    // Spawn a new asteroid occasionally
    if (rand() % 100 == 0) {
        spawnAsteroid();
    }

    handleCollisions();


}

void Game::handleCollisions() {
    // Check collisions between bullets and asteroids
    for (auto& bullet : bullets) {
        for (auto& asteroid : asteroids) {
            if (bullet.getBounds().intersects(asteroid.getBounds())) {
                //remove the bullet and asteroid
                bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet), bullets.end());
                asteroids.erase(std::remove(asteroids.begin(), asteroids.end(), asteroid), asteroids.end());
            }
        }
    }
}

void Game::render() {
    window.clear();

    if(isMenuActive){
        window.draw(startText);
        window.draw(exitText);
    }
    else
    {
        // Draw player
        player.draw(window);

        // Draw asteroids
        for (auto& asteroid : asteroids) {
            asteroid.draw(window);
        }

        // Draw bullets
        for (auto& bullet : bullets) {
            bullet.draw(window);
        }

        // Display the contents of the window
        window.display();
    }

}

void Game::spawnAsteroid() {
    Asteroid asteroid(20.0f, sf::Vector2f(window.getSize().x, rand() % window.getSize().y));
    asteroids.push_back(asteroid);
}
