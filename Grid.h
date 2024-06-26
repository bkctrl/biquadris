#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "cell.h"
#include "block.h"
#include "textdisplay.h"
// #include "graphicsdisplay.h"
// #include "observer.h"

// class Level;
class TextDisplay;

class Grid {
private:
    int gridHeight;
    int gridWidth;
    std::vector<Block*> blocksOnGrid;
    int playerId;
    Block* currentBlock;
    Block* nextBlock;
    int currentScore;
    TextDisplay *td;
    bool blindModeActive;
    bool heavyModeActive;
    bool forceModeActive;

    // Private methods that are related to grid's state
    void clearBlocks();
    void removeLines(const std::vector<int>& fullLines);
    int clearFullLines();
    bool createCenterBlock();
    bool switchCurrentBlock(const std::string& blockType);
    
public:
    int highScore;
    // Grid(int player, TextDisplay* td);
    Grid();
    ~Grid();
    std::vector< std::vector<Cell> > theGrid;

    void init();
    void reset();

    bool createNextBlock();

    Block* getNextBlock() const;
    Block* getCurrentBlock() const;

    // void changeLevel(Level* newLevelPtr);
    // int getCurrentLevelNumber() const;
    std::vector< std::vector<Cell> >& accessGrid();
    int getPlayerId() const;
    int getCurrentScore() const;
    void setCurrentScore(int score);

    friend std::ostream& operator<<(std::ostream& out, const Grid& grid);
};

#endif // GRID_H
