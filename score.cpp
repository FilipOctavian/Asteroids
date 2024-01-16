#include "score.h"

TimeBasedScore::TimeBasedScore() : Score(0), timeSinceLastIncrement(0.0f) {

}

void TimeBasedScore::updateScore() {
    float currentTime = clock.getElapsedTime().asSeconds();
    if (currentTime - timeSinceLastIncrement >= 1.0f) {
        score += 1;
        timeSinceLastIncrement = currentTime;
    }
}

// Implementare AsteroidHitScore
void AsteroidHitScore::addScore() {
    score += 10; 
}

void AsteroidHitScore::updateScore() {

}

ComboScore::ComboScore() : Score(0), timeSinceLastIncrement(0.0f), comboMultiplier(1) {

}



void ComboScore::updateScore() {
    float currentTime = clock.getElapsedTime().asSeconds();
    if (currentTime - timeSinceLastIncrement >= 10.0f) {
        comboMultiplier++;
        score += 5 * comboMultiplier;
        timeSinceLastIncrement = currentTime;
    }
}

