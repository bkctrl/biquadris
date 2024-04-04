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

  public:
      blockType getType() const { return type; } // return the type of block
      // Block(blockType type) : type(type) {} // default parametric constructor
      Block(int level);
      virtual void init(); // intialize shape and position
      virtual void rotateClkwise(); 
      virtual void rotateCounterClkwise();
      virtual void shiftLeft(int px); // shift left by n pixels
      virtual void shiftRight(int px); // shift right by n pixels
      virtual void shiftUp(int px); // shift up by n pixels
      virtual void shiftDown(int px); // shift down by n pixels
      virtual void display() const; // display block 
      virtual ~Block();
    // observer methods
      void update(Subject &subject) override;
  // void attach(Observer* observer) {
  //   observers.emplace_back(observer);
  // }
  // void detach(Observer* observer) {
  //   for (auto it = observers.begin(); it != observers.end(); ++it) {
  //     if (*it == observer) {
  //       observers.erase(it);
  //       break;
  //     }
  //   }
  // }
  // void notify() {
  //   for (Observer* observer : observers) {
  //       observer->update();
  //   }
  // }
};


class IBlock : public Block {
  public:
    IBlock(int lvl);
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

#endif


// you need to have individual init for each block since they are displayed differently 
// block has virtual init func that does nothing, specifics are implemented in its subclasses that override the init method

// block has a vector of pointers to cells called blockCells 
// this vector contains the coordinates the cells cover (cell contains itself's coordinate information inside cell class)

// cell knows about the changes
// grid cares about the changes (ex. to clear row(s))

