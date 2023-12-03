//
// Created by Octa on 15.11.2023.
//

#include <SFML/Graphics.hpp>
#include <ranges>
#include "game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Simple Game"), player() {
    window.setFramerateLimit(60); // Set a frame rate limit for smooth rendering
    isMenuActive = true;
    initializeMenu();
}

std::ostream& operator<<(std::ostream& os, const Game& gm)
{
    os<<"Window dimensions:800x600";
    os << "Number of asteroids: " << gm.numAsteroids << "\n";

    os<<"Bullets:\n";
    for(const auto& bullet : gm.bullets)

        os<<bullet<<"\n";


    os<<"Bullets:\n";

    for(const auto& bullet : gm.bullets)

        os<< bullet<<"\n";


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
    std::vector<size_t> bulletsToRemove;
    std::vector<size_t> asteroidsToRemove;

    for (size_t i = 0; i < bullets.size(); ++i) {
        for (size_t j = 0; j < asteroids.size(); ++j) {
            if (bullets[i].getBounds().intersects(asteroids[j].getBounds())) {
                bulletsToRemove.push_back(i);
                asteroidsToRemove.push_back(j);
            }
        }
    }

    // Eliminate bullets that collided
    for (auto it = bulletsToRemove.rbegin(); it != bulletsToRemove.rend(); ++it) {
        bullets.erase(bullets.begin() + *it);
    }

    // Eliminate asteroids that collided
    for (auto it = asteroidsToRemove.rbegin(); it != asteroidsToRemove.rend(); ++it) {
        asteroids.erase(asteroids.begin() + *it);
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
