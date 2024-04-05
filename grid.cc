#include <iostream>
#include <algorithm>
#include "grid.h"

Grid::Grid(): 
    playerId{}, gridWidth{11}, gridHeight{18}, td(nullptr),
    currentScore{0}, highScore{0},
    // currentLevelNumber{0}, currentLevel{nullptr},
    currentBlock{nullptr}, nextBlock{nullptr}, blindModeActive{false}, heavyModeActive{false}, forceModeActive{false} {
    init();
}

Grid::~Grid() {
    delete td;
    // delete graphicsDisplay;
    clearBlocks();
}

void Grid::init() {
    theGrid.resize(gridHeight, std::vector<Cell>(gridWidth, Cell{0, 0, this}));
    delete td;
    td = new TextDisplay();
    for (int row = 0; row < gridHeight; row++) {
        for (int col = 0; col < gridWidth; col++) {
            theGrid[row][col] = Cell(col, row, this);
            theGrid[row][col].attach(td); // Attach textDisplay to each cell
            // if (graphicsDisplay) {
            //     theGrid[row][col].attach(graphicsDisplay);
            // }
        }
    }
}

void Grid::reset() {
    if (currentScore > highScore) {
        highScore = currentScore;
    }
    currentScore = 0;
    blindModeActive = false;
    heavyModeActive = false;
    forceModeActive = false;
    clearBlocks();
    currentBlock = nullptr;
    nextBlock = nullptr;
    for (int row = 0; row < gridHeight; row++) {
        for (int col = 0; col < gridWidth; col++) {
            theGrid[row][col].updateCell(false, nullptr);
        }
    }
}

void Grid::clearBlocks() {
    for (auto block : blocksOnGrid) {
        delete block;
    }
    blocksOnGrid.clear();
}

Block* Grid::getNextBlock() const {
    return nextBlock;
}

Block* Grid::getCurrentBlock() const {
    return currentBlock;
}

int Grid::clearFullLines() {
    std::vector<int> fullLines;
    for (int row = 0; row < gridHeight; row++) {
        bool fullLine = true;
        for (int col = 0; col < gridWidth; col++) {
            if (!theGrid[row][col].isOccupied()) {
                fullLine = false;
                break;
            }
        }
        if (fullLine) {
            fullLines.emplace_back(row);
        }
    }
    if (fullLines.empty()) {
        return 0;
    }
    removeLines(fullLines);
    return fullLines.size();
}

void Grid::removeLines(const std::vector<int>& fullLines) {
    for (int row : fullLines) {
        for (int col = 0; col < gridWidth; col++) {
            theGrid[row][col].updateCell(false, nullptr);
        }
        for (int i = row; i > 0; i--) {
            for (int col = 0; col < gridWidth; col++) {
                theGrid[i][col].swapCell(theGrid[i - 1][col]);
            }
        }
    }
}

int Grid::getPlayerId() const {
    return playerId;
}

std::vector<std::vector<Cell>>& Grid::accessGrid() {
    return theGrid;
}

std::ostream& operator<<(std::ostream& out, const Grid& grid) {
    out << *grid.td;
    return out;
}

// LEVEL STUFF

// bool Grid::createNextBlock() {
//     Block *newBlock = currentLevel->createBlock(currentLevelNumber, nextBlock->getType());
//     blocksOnGrid.push_back(newBlock);
//     activeBlock = nextBlock;
//     nextBlock = newBlock;
//     if (activeBlock) {
//         activeBlock->initializeTiles();
//         Cell **cells = activeBlock->getTiles();
//         for (int i=0; i < 4; i++){
//             if (cells[i]->isOccupied()){
//                 return true;
//             }
//             cells[i]->updateTile(true, activeBlock);
//         }
//     }
//     return false;
// }

// bool Grid::createCenterBlock() {
//     activeBlock = currentLevel->createCenterBlock();
//     if (activeBlock) {
//         blocksOnGrid.push_back(activeBlock);
//         return true;
//     }
//     return false;
// }

// bool Grid::switchActiveBlock(const std::string& blockType) {
//     Block* newBlock = currentLevel->createBlock(blockType);
//     if (newBlock) {
//         blocksOnGrid.emplace_back(newBlock);
//         activeBlock = newBlock;
//         return true;
//     }
//     return false;
// }

// void Grid::changeLevel(int newLevel, Level* newLevelPtr) {
//     currentLevelNumber = newLevel;
//     currentLevel = newLevelPtr;
// }
