//
// Created by Octa on 15.11.2023.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <ranges>
#include <iostream>
#include "game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Simple Game"), player() {
    window.setFramerateLimit(60); // Set a frame rate limit for smooth rendering

    inMenu = true;

    font.loadFromFile("Font/ARIBLK.TTF");

    startButton.setSize(sf::Vector2f(200.0f, 50.0f));
    startButton.setPosition(300.0f, 250.0f);
    startButton.setFillColor(sf::Color::Green);

    exitButton.setSize(sf::Vector2f(200.0f, 50.0f));
    exitButton.setPosition(300.0f, 350.0f);
    exitButton.setFillColor(sf::Color::Red);

    startText.setFont(font);
    startText.setString("Start Game");
    startText.setCharacterSize(20);
    startText.setFillColor(sf::Color::Black);
    startText.setPosition(330.0f, 260.0f);

    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(20);
    exitText.setFillColor(sf::Color::Black);
    exitText.setPosition(370.0f, 360.0f);

    score = new SimpleScore();

}
void Game::displayScore() {
    sf::Font scoreeFont;
    scoreFont.loadFromFile("Font/ARIBLK.TTF");

    sf::Text scoreeText;
    scoreText.setFont(scoreFont);
    scoreText.setString("Score: " + std::to_string(score->getScore()));  // Obține scorul sub formă de șir
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.0f, 10.0f);  // Ajustează poziția textului pe ecran

    window.draw(scoreText);
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


void Game::run() {
    while (window.isOpen()) {
        if (inMenu) {
            handleMenuInput();
            drawMenu();
        } else {
            handleInput();
            update();
            render();
        }
    }
}

void Game::handleMenuInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (startButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    inMenu = false;
                }
                else if (exitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    window.close();
                }
            }
        }
    }
}


void Game::drawMenu() {
    window.clear();

    window.draw(startButton);
    window.draw(exitButton);
    window.draw(startText);
    window.draw(exitText);

    window.display();
}

void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
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
                score->increaseScore();
                if (score->getScore() == 20 && !dynamic_cast<DoubleScore*>(score)) {
                    delete score;
                    score = new DoubleScore();
                }

                if (score->getScore() == 30 && !dynamic_cast<TripleScore*>(score)) {
                    delete score;
                    score = new TripleScore();
                }
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

    displayScore();

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

void Game::spawnAsteroid() {
    Asteroid asteroid(20.0f, sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y));
    asteroids.push_back(asteroid);
}

Game::~Game() {
    delete score;
}


