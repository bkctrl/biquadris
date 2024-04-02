#include "score.h"

Score::Score(): currentScore{0}, hiScore{0} {}

void Score::addScore(int score) {
    currentScore += score;
    if (currentScore > hiScore) {
        hiScore = currentScore;
    }
}

int Score::getCurrentScore() {
    return currentScore;
}

int Score::getHighScore() {
    return hiScore;
}

void Score::resetScore() {
    currentScore = 0;
}