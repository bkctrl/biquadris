#ifndef BLOCK_H
#define BLOCK_H

#include "cell.h"
#include "observer.h"
#include "subject.h"
#include <vector>

// add Heavy
// add StarBlock class

// enum blockType {I,J,L,O,S,Z,T};

class Block : public Observer, public Subject {
  protected:
    char letter; // The letter of the block
    int creationLevel; // The level at which the block was created
    bool isHeavy = false; // Whether the block is heavy
    std::vector<Cell*> occupiedCells; // contains the coordinates the cells cover 

    int currentOrientation; // The current orientation of the block
    int color; // Color identifier for the block
    Grid& gameGrid; // Reference to the grid containing the block

    int positionX; // X position of the "anchor" cell for transformations
    int positionY; // Y position of the "anchor" cell for transformations

  public:
    Block(char type, int orientation, Grid& grid, int x, int y, int level); // constructor
    virtual ~Block(); // destructor

    // Methods for block manipulation    
    char getLetter() const; // return the letter of block
    int getColor() const; // return the color of the block
    bool isCleared() const; // check if the block is cleared
    int getCreationLevel() const; // get the creation level of the block

    bool isValidPlacement(Cell& cell, int y, int x) const; // check if the block can be placed at the given cell
    Cell** getOccupiedCells(); // return the cells that the block occupies
    void removeFromCell(Cell& cell); // remove the block from a cell

    virtual void initializeCells() = 0; // initialize the cells of the block
    virtual void rotateClockwise() = 0; // rotate the block clockwise
    virtual void rotateCounterClockwise() = 0; // rotate the block counterclockwise

    void moveLeft(); // move the block left by one cell
    void moveRight(); // move the block right by one cell
    void moveDown(); // move the block down by one cell
    void hardDrop(); // drop the block to the lowest possible position
    void centerDrop(); // drop the block to the center of the grid
};


// class IBlock : public Block {
//   public:
//     IBlock(int level);
//     IBlock(int level, char letter);
//     blockType getType() const { return type; }
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft(int px) override;
//     void shiftRight(int px) override;
//     void shiftUp(int px) override;
//     void shiftDown(int px) override;
//     void display() const override;
// };

// class JBlock : public Block {
//   public:
//     JBlock(int level);
//     JBlock(int level, char letter);
//     blockType getType() const { return type; }
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft(int px) override;
//     void shiftRight(int px) override;
//     void shiftUp(int px) override;
//     void shiftDown(int px) override;
//     void display() const override;
// };

// class LBlock : public Block {
//   public:
//     LBlock(int level);
//     LBlock(int level, char letter);
//     blockType getType() const { return type; }
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft(int px) override;
//     void shiftRight(int px) override;
//     void shiftUp(int px) override;
//     void shiftDown(int px) override;
//     void display() const override;
// };

// class OBlock : public Block {
//   public:
//     OBlock(int level);
//     OBlock(int level, char letter);
//     blockType getType() const { return type; }
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft(int px) override;
//     void shiftRight(int px) override;
//     void shiftUp(int px) override;
//     void shiftDown(int px) override;
//     void display() const override;
// };

// class SBlock : public Block {
//   public:
//     SBlock(int level);
//     SBlock(int level, char letter);
//     blockType getType() const { return type; }
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft(int px) override;
//     void shiftRight(int px) override;
//     void shiftUp(int px) override;
//     void shiftDown(int px) override;
//     void display() const override;
// };

// class ZBlock : public Block {
//   public:
//     ZBlock(int level);
//     ZBlock(int level, char letter);
//     blockType getType() const { return type; }
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft(int px) override;
//     void shiftRight(int px) override;
//     void shiftUp(int px) override;
//     void shiftDown(int px) override;
//     void display() const override;
// };

// class TBlock : public Block {
//   public:
//     TBlock(int level);
//     TBlock(int level, char letter);
//     blockType getType() const { return type; }
//     void rotateClkwise() override;
//     void rotateCounterClkwise() override;
//     void shiftLeft(int px) override;
//     void shiftRight(int px) override;
//     void shiftUp(int px) override;
//     void shiftDown(int px) override;
//     void display() const override;
// };

class StarBlock : public Block {
  public:
    StarBlock(int lvl);
    StarBlock(int lvl, const char letter);
    ~StarBlock();
    void init() override;
    blockType getType() const { return type; }
    void rotateClkwise() override;
    void rotateCounterClkwise() override;
    void shiftLeft(int px) override;
    void shiftRight(int px) override;
    void shiftUp(int px) override;
    void shiftDown(int px) override;
    void display() const override;
};

#endif
