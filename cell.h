#ifndef CELL_H
#define CELL_H

#include <string>
#include "subject.h"

class Block;
class Grid;

class Cell : public Subject {
    bool occupied; // true if cell is occupied
    Block* block; // block that is occupying the cell
    int col; // x position of the cell
    int row; // y position of the cell
    Grid* grid; // pointer to the grid that the cell is in

public:
    Cell(int x, int y, Grid* grid); // constructor
    void updateCell(bool isNowOccupied, Block* newBlock); // updates the cell with new block
    void swapCell(Cell& other); // swaps the cell with another cell
    bool isOccupied(); // returns true if cell is occupied
    Block* getOccupyingBlock(); // returns the block that is occupying the cell
    int getCol(); // returns x position of the cell
    int getRow(); // returns y position of the cell
    void incrementRow(); // increments the y position of the cell
    Grid* getGrid(); // returns the grid that the cell is in
};

#endif // CELL_H
