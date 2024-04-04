#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "cell.h"
#include "block.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"
#include "observer.h"
#include "subject.h"

class Level;

class Grid : public Subject {
private:
    std::vector<std::vector<Cell>> theGrid;
    int gridHeight;
    int gridWidth;
    std::vector<Block*> blocksOnGrid;
    int playerId;
    Block* activeBlock;
    Block* nextBlock;
    int currentScore;

    // Private methods that are related to grid's state
    void clearBlocks();
    void removeLines(const std::vector<int>& fullLines);
    int clearFullLines();
    bool createCenterBlock();
    bool switchActiveBlock(const std::string& blockType);
    
public:
    Grid(int player, TextDisplay* td, GraphicsDisplay* gd);
    ~Grid();

    void initialize();
    void resetGrid();

    bool createNextBlock();

    Block* getNextBlock() const;
    Block* getActiveBlock() const;

    void changeLevel(Level* newLevelPtr);
    int getCurrentLevelNumber() const;
    std::vector<std::vector<Cell>>& accessGrid();
    int getPlayerId() const;
    int getCurrentScore() const;
    void setCurrentScore(int score);

    // // TODO: Observer pattern methods should be implemented in grid like in A4, remove the 3 funcs below
    // void attach(Observer* observer);
    // void detach(Observer* observer);
    // void notifyObservers();

    friend std::ostream& operator<<(std::ostream& out, const Grid& grid);
};

#endif // GRID_H
