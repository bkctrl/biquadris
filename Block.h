#ifndef BLOCK_H
#define BLOCK_H

#include "cell.h"
#include "observer.h"
#include "subject.h"
#include "grid.h"
#include <vector>

class Block : public Observer, public Subject {
  protected:
    char letter; // The letter of the block
    int level; // The level at which the block was created
    bool isHeavy = false; 
    std::vector<Cell*> blockCells; // contains the coordinates the cells cover 

    int orientation; // The current orientation of the block
    int color; // Color identifier for the block
    Grid& grid; // Reference to the grid containing the block

    int col = 7; // X position of the "anchor" cell for transformations
    int row = 2; // Y position of the "anchor" cell for transformations

  public:
    Block(char type, int orientation, Grid& grid, int row, int col, int level); // constructor
    virtual ~Block(); // destructor

    // Methods for block manipulation 
    char getLetter() const { return letter; }; // return the letter of block
    int getColor() const; // return the color of the block
    bool isCleared() const; // check if the block is cleared
    int getLevel() const { return level; }; // get the creation level of the block

    bool isValidPlacement(int row, int col) const; // check if the block can be placed at the given cell
    Cell** getOccupiedCells(); // return the cells that the block occupies
    void removeFromCell(Cell& cell); // remove the block from a cell

    virtual void init() = 0; // initialize the cells of the block
    virtual void rotateClockwise() = 0; // rotate the block clockwise
    virtual void rotateCounterClockwise() = 0; // rotate the block counterclockwise

    void shiftLeft(); // move the block left by one cell
    void shiftRight(); // move the block right by one cell
    void shiftDown(); // move the block down by one cell
    void hardDrop(); // drop the block to the lowest possible position
    void centerDrop(); // drop the block to the center of the grid
};


class IBlock : public Block {
  public:
    IBlock(Grid& grid, int level);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};
class JBlock : public Block {
  public:
    JBlock(Grid& grid, int level);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};
class LBlock : public Block {
  public:
    LBlock(Grid& grid, int level);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};
class OBlock : public Block {
  public:
    OBlock(Grid& grid, int level);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};
class SBlock : public Block {
  public:
    SBlock(Grid& grid, int level);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};
class ZBlock : public Block {
  public:
    ZBlock(Grid& grid, int level);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};
class TBlock : public Block {
  public:
    TBlock(Grid& grid, int level);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};
class StarBlock : public Block {
  public:
    StarBlock(Grid& grid, int level);
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};














// class JBlock : public Block {
//   public:
//     JBlock(int level);
//     JBlock(int level, char letter);
//  
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft();
//     void shiftRight();
//     void shiftDown();
// };

// class LBlock : public Block {
//   public:
//     LBlock(int level);
//     LBlock(int level, char letter);
//  
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft();
//     void shiftRight();
//     void shiftDown();
// };

// class OBlock : public Block {
//   public:
//     OBlock(int level);
//     OBlock(int level, char letter);
//  
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft();
//     void shiftRight();
//     void shiftDown();
// };

// class SBlock : public Block {
//   public:
//     SBlock(int level);
//     SBlock(int level, char letter);
//  
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft();
//     void shiftRight();
//     void shiftDown();
// };

// class ZBlock : public Block {
//   public:
//     ZBlock(int level);
//     ZBlock(int level, char letter);
//  
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft();
//     void shiftRight();
//     void shiftDown();
// };

// class TBlock : public Block {
//   public:
//     TBlock(int level);
//     TBlock(int level, char letter);
//  
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft();
//     void shiftRight();
//     void shiftDown();
// };

// class StarBlock : public Block {
//   public:
//     StarBlock(int lvl);
//     StarBlock(int lvl, const char letter);
//     ~StarBlock();
//     void init();
//  
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft();
//     void shiftRight();
//     void shiftDown();
// };

#endif
