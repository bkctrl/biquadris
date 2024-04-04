#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include "grid.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"
#include "level.h"
#include "block.h"

class GameEngine {
private:
    // TODO: add and remove the below as necessary
    Grid player1Grid;
    Grid player2Grid;
    TextDisplay* textDisplay; // Handles text display for both grids
    GraphicsDisplay* graphicsDisplay; // Handles graphic display for both grids
    Level* currentLevel; // The current level for both players
    int currentPlayerId; // ID of the current player
    int player1Score;
    int player2Score;
    int highScore;
    bool gameIsActive;

    // Game logic methods
    void switchPlayer();
    void updateScores(int linesCleared, Grid& grid);
    void applySpecialAction(Grid& targetGrid, const std::string& action);
    void updateGameAfterMove(Grid& activeGrid);
    void dropNextBlockForCurrentPlayer();

public:
    GameEngine();
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

    // Other methods
    // ...
};

#endif // GAMEENGINE_H
