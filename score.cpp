#include "score.h"
//
void SimpleScore::increaseScore() {
    // Scorul crește cu un punct la fiecare apel
    score++;
}

int SimpleScore::getScore() const {
    return score;
}

void DoubleScore::increaseScore() {
    // Scorul crește cu două puncte la fiecare apel
    score += 2;
    handleThresholds();

}

int DoubleScore::getScore() const {
    return score;

}
void DoubleScore::handleThresholds() {
    if (score == 20) {
        score += 2;
    }
}

void TripleScore::increaseScore() {
    score += 3;
    handleThresholds();

}

int TripleScore::getScore() const {
    return score;
}

void TripleScore::handleThresholds() {
    if (score == 30) {
        score += 3;
    }
}