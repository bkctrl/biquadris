#ifndef BLOCK_H
#define BLOCK_H

#include "cell.h"
#include "observer.h"
#include <vector>

enum blockType {I,J,L,O,S,Z,T,STAR};

class Block  : public Observer {
  protected:
    int level;
    blockType type;
    Cell* bottomLeft;
    std::vector<Cell*> blockCells; // contains the coordinates the cells cover 
    std::vector<Observer*> observers; // list of observers

  public:
    blockType getType() const { return type; } // return the type of block
    Block() {}
    Block(int level) : level(level) {} 
    virtual void init(); // intialize shape and position
    virtual void rotateClkwise(); 
    virtual void rotateCounterClkwise();
    virtual void shiftLeft(int px); // shift left by n pixels
    virtual void shiftRight(int px); // shift right by n pixels
    virtual void shiftUp(int px); // shift up by n pixels
    virtual void shiftDown(int px); // shift down by n pixels
    virtual ~Block();

  // observer methods
  void attach(Observer* observer) {
    observers.emplace_back(observer);
  }
  void detach(Observer* observer) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
      if (*it == observer) {
        observers.erase(it);
        break;
      }
    }
  }
  void notify() {
    for (Observer* observer : observers) {
        observer->update();
    }
  }
};


class IBlock : public Block {
  public:
    IBlock(int numLevel);
    ~IBlock();
    void init() override;
    blockType getType() const { return type; }
    void rotateClkwise() override;
    void rotateCounterClkwise() override;
    void shiftLeft(int px) override;
    void shiftRight(int px) override;
    void shiftUp(int px) override;
    void shiftDown(int px) override;
};

class JBlock : public Block {
  public:
    JBlock(int numLevel);
    ~JBlock();
    void init();
    blockType getType() const { return type; }
    void rotateClkwise() override;
    void rotateCounterClkwise() override;
    void shiftLeft(int px) override;
    void shiftRight(int px) override;
    void shiftUp(int px) override;
    void shiftDown(int px) override;
};

class LBlock : public Block {
  public:
    LBlock(int numLevel);
    ~LBlock();
    void init() override;
    blockType getType() const { return type; }
    void rotateClkwise() override;
    void rotateCounterClkwise() override;
    void shiftLeft(int px) override;
    void shiftRight(int px) override;
    void shiftUp(int px) override;
    void shiftDown(int px) override;
};

class OBlock : public Block {
  public:
    OBlock(int numLevel);
    ~OBlock();
    void init() override;
    blockType getType() const { return type; }
    void rotateClkwise() override;
    void rotateCounterClkwise() override;
    void shiftLeft(int px) override;
    void shiftRight(int px) override;
    void shiftUp(int px) override;
    void shiftDown(int px) override;
};

class SBlock : public Block {
  public:
    SBlock(int numLevel);
    ~SBlock();
    void init() override;
    blockType getType() const { return type; }
    void rotateClkwise() override;
    void rotateCounterClkwise() override;
    void shiftLeft(int px) override;
    void shiftRight(int px) override;
    void shiftUp(int px) override;
    void shiftDown(int px) override;
};

class ZBlock : public Block {
  public:
    ZBlock(int numLevel);
    ~ZBlock();
    void init() override;
    blockType getType() const { return type; }
    void rotateClkwise() override;
    void rotateCounterClkwise() override;
    void shiftLeft(int px) override;
    void shiftRight(int px) override;
    void shiftUp(int px) override;
    void shiftDown(int px) override;
};

class TBlock : public Block {
  public:
    TBlock(int numLevel);
    ~TBlock();
    void init() override;
    blockType getType() const { return type; }
    void rotateClkwise() override;
    void rotateCounterClkwise() override;
    void shiftLeft(int px) override;
    void shiftRight(int px) override;
    void shiftUp(int px) override;
    void shiftDown(int px) override;
};

class StarBlock : public Block {
  public:
    StarBlock(int numLevel);
    ~StarBlock();
    void init() override;
    blockType getType() const { return type; }
    void rotateClkwise() override;
    void rotateCounterClkwise() override;
    void shiftLeft(int px) override;
    void shiftRight(int px) override;
    void shiftUp(int px) override;
    void shiftDown(int px) override;
};

#endif
