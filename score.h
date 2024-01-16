//
// Created by Octa on 29.12.2023.
//

#ifndef OOP_SCORE_H
#define OOP_SCORE_H

#endif //OOP_SCORE_H
//
#pragma once

#include <SFML/System/Clock.hpp>


class Score {
protected:
    int score;

public:
    Score(int initialScore = 0) : score(initialScore) {}
    virtual void updateScore() = 0;

    int getScore() const {
        return score;
    }
    Score(const Score& other) : score(other.score) {}

    Score& operator=(const Score& other) {
        if (this != &other) {
            score = other.score;
        }
        return *this;
    }

    virtual ~Score() = default;
};

// Scor bazat pe timp
class TimeBasedScore : public Score {

private:
    sf::Clock clock;
    float timeSinceLastIncrement;

public:
    TimeBasedScore();
    void updateScore() override;
};



// Scor bazat pe asteroizi distruși
class AsteroidHitScore : public Score {
public:
    void addScore();
    void updateScore() override;
};

// Scor bazat pe combo-uri
class ComboScore : public Score {
private:
    sf::Clock clock;
    float timeSinceLastIncrement;
    int comboMultiplier;

public:
    ComboScore();
    void updateScore() override;
};

class TotalScore {
private:
    Score* timeScore;
    Score* asteroidScore;
    Score* comboScore;

public:
    TotalScore(Score* time, Score* asteroid, Score* combo)
            : timeScore(time), asteroidScore(asteroid), comboScore(combo) {}

    [[nodiscard]] int calculateTotalScore() const {
        return timeScore->getScore() + asteroidScore->getScore() + comboScore->getScore();
    }
};