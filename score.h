#ifndef SCORE_H
#define SCORE_H

class Score {
    int currentScore;
    int hiScore;
public:
    Score();
    void addScore(int);
    int getCurrentScore();
    int getHighScore();
    void resetScore();
};

#endif 