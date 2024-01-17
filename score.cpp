#include "score.h"

TimeBasedScore::TimeBasedScore() : Score(0), timeSinceLastIncrement(0.0f) {

}

void TimeBasedScore::updateScore() {
    float currentTime = clock.getElapsedTime().asSeconds();
    if (currentTime - timeSinceLastIncrement >= 1.0f) { // Verifică dacă a trecut o secundă
        score += 1;
        timeSinceLastIncrement = currentTime;
    }
}

// Implementare AsteroidHitScore
void AsteroidHitScore::addScore() {
    score += 10; // 10 puncte pentru fiecare asteroid distrus
}

void AsteroidHitScore::updateScore() {
    // Nu face nimic în update, scorul este actualizat manual
}

// Implementare ComboScore
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

