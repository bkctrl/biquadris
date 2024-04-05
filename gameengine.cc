#include "gameengine.h"

GameEngine::GameEngine() : currentLevel{0}, player1Score{0}, player2Score{0}, highScore{0} {}

~GameEngine();

// TODO: add and remove the below as necessary
void startGame();
void executeCommand(const std::string& command);
void levelUp();
void levelDown();
void noRandom(const std::string& filename);
void randomize();
void executeSequenceFile(const std::string& filename);
void restartGame();
void setSeed(int seed);

// Getters
int getCurrentLevel() const;
int getPlayer1Score() const;
int getPlayer2Score() const;
int getHighScore() const;
