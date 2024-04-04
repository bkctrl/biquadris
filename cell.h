#ifndef CELL_H
#define CELL_H

#include <string>
#include "subject.h"

class Block;
class Grid;

class Cell : public Subject {
    bool occupied; // true if cell is occupied
    Block* currentBlock; // block that is occupying the cell
    int posX; // x position of the cell
    int posY; // y position of the cell
    Grid* parentGrid; // pointer to the grid that the cell is in

public:
    Cell(int x, int y, Grid* grid); // constructor
    void updateCell(bool isNowOccupied, Block* newBlock); // updates the cell with new block
    void swapCell(Cell& other); // swaps the cell with another cell
    bool isOccupied(); // returns true if cell is occupied
    Block* getOccupyingBlock(); // returns the block that is occupying the cell
    int getX(); // returns x position of the cell
    int getY(); // returns y position of the cell
    void incrementY(); // increments the y position of the cell
    Grid* getParentGrid(); // returns the grid that the cell is in
};

#endif // CELL_H
