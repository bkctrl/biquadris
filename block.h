#ifndef BLOCK_H
#define BLOCK_H

#include "cell.h"
#include "observer.h"
#include "subject.h"
#include <vector>

// add Heavy
// add StarBlock class

enum blockType {I,J,L,O,S,Z,T};

class Block : public Observer, public Subject {
  protected:
    blockType type;
    bool isHeavy = false;
    std::vector<Cell*> blockCells; // contains the coordinates the cells cover 
    std::vector<Observer*> observers; // list of observers
    int lvl;
    const char letter;
    char charInput;

  public:
      blockType getType() const { return type; } // return the type of block
      Block(int level);
      Block(int level, const char letter);
      bool isValidMove(std::vector<Cell *> updatedBlockCells, char charInput);
      virtual void init(); // intialize shape and position
      virtual void rotateClkwise(); 
      virtual void rotateCounterClkwise();
      virtual void shiftLeft(int px); // shift left by n pixels
      virtual void shiftRight(int px); // shift right by n pixels
      virtual void shiftUp(int px); // shift up by n pixels
      virtual void shiftDown(int px); // shift down by n pixels
      virtual void display() const; // display block 
      virtual ~Block();
      void update(Subject &subject) override;
};


class IBlock : public Block {
  public:
    IBlock(int lvl);
    IBlock(int lvl, const char letter);
    ~IBlock();
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

class JBlock : public Block {
  public:
    JBlock(int lvl);
    JBlock(int lvl, const char letter);
    ~JBlock();
    void init();
    blockType getType() const { return type; }
    void rotateClkwise() override;
    void rotateCounterClkwise() override;
    void shiftLeft(int px) override;
    void shiftRight(int px) override;
    void shiftUp(int px) override;
    void shiftDown(int px) override;
    void display() const override;
};

class LBlock : public Block {
  public:
    LBlock(int lvl);
    LBlock(int lvl, const char letter);
    ~LBlock();
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

class OBlock : public Block {
  public:
    OBlock(int lvl);
    OBlock(int lvl, const char letter);
    ~OBlock();
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

class SBlock : public Block {
  public:
    SBlock(int lvl);
    SBlock(int lvl, const char letter);
    ~SBlock();
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

class ZBlock : public Block {
  public:
    ZBlock(int lvl);
    ZBlock(int lvl, const char letter);
    ~ZBlock();
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

class TBlock : public Block {
  public:
    TBlock(int lvl);
    TBlock(int lvl, const char letter);
    ~TBlock();
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
