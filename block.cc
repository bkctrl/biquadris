#include "block.h"

// to-do : implement display() in each block
Block::Block(int level, const char letter) : lvl(lvl), letter(letter) {}

// Block::blockType getType() { return type; } // return the type of block
// block:: validity check 
// pass in: newmovement (ptrs to 4 cells that represents the final destination) + actual block (char)

Block::~Block() {
  for (Cell* cell : blockCells) {
    delete cell;
  }
  blockCells.clear();
}

void Block::rotateClkwise() {
  for (Cell* cell : blockCells) {
    int newRow = -cell->getCol();
    int newCol = cell->getRow();
    cell->setCoords(newRow, newCol);
  }
  notify();
}

void Block::rotateCounterClkwise() {
  for (Cell* cell : blockCells) {
    int newRow = cell->getCol();
    int newCol = -cell->getRow();
    cell->setCoords(newRow, newCol);
  }
  notify();
}

// to-do : check if can't be shifted further
void Block::shiftLeft(int px) {
  // have a check for validity of move
  for (Cell* cell : blockCells) {
    int newRow = cell->getRow() - px;
    cell->setCoords(newRow, cell->getCol());
  }
  notify();
}

// to-do : check if can't be shifted further
void Block::shiftRight(int px) {
  for (Cell* cell : blockCells) {
    int newRow = cell->getRow() + px;
    cell->setCoords(newRow, cell->getCol());
  }
  notify();
}

// to-do : check if can't be shifted further
void Block::shiftUp(int px) {
  for (Cell* cell : blockCells) {
    int newCol = cell->getCol() + px;
    cell->setCoords(cell->getRow(), newCol);
  }
  notify();
}

// to-do : check if can't be shifted further
void Block::shiftDown(int px) {
  for (Cell* cell : blockCells) {
    int newCol = cell->getCol() - px;
    cell->setCoords(cell->getRow(), newCol);
  }
  notify();
}

void Block::display() const {

}


// IBlock

IBlock::IBlock(int lvl, const char letter) : Block(lvl, letter) {
  init();
}

void IBlock::init() {
  blockCells.push_back(new Cell(0, 0)); 
  blockCells.push_back(new Cell(1, 0));
  blockCells.push_back(new Cell(2, 0));
  blockCells.push_back(new Cell(3, 0));
}

void IBlock::rotateClkwise() {
  Block::rotateClkwise();
}

void IBlock::rotateCounterClkwise() {
  Block::rotateCounterClkwise();
}

void IBlock::shiftLeft(int px) {
  Block::shiftLeft(px);
}

void IBlock::shiftRight(int px) {
  Block::shiftRight(px);
}

void IBlock::shiftUp(int px) {
  Block::shiftUp(px);
}

void IBlock::shiftDown(int px) {
  Block::shiftDown(px);
}

void IBlock::display() const {

}


// JBlock

JBlock::JBlock(int lvl) : Block(lvl) {
  init(); 
}

void JBlock::init() {
  blockCells.push_back(new Cell(0, 0));
  blockCells.push_back(new Cell(0, 1));
  blockCells.push_back(new Cell(1, 1));
  blockCells.push_back(new Cell(2, 1));
}

void JBlock::rotateClkwise() {
  Block::rotateClkwise();
}

void JBlock::rotateCounterClkwise() {
  Block::rotateCounterClkwise();
}

void JBlock::shiftLeft(int px) {
  Block::shiftLeft(px);
}

void JBlock::shiftRight(int px) {
  Block::shiftRight(px);
}

void JBlock::shiftUp(int px) {
  Block::shiftUp(px);
}

void JBlock::shiftDown(int px) {
  Block::shiftDown(px);
}

void JBlock::display() const {

}


// LBlock

LBlock::LBlock(int lvl) : Block(lvl) {
  init(); 
}

void LBlock::init() {
  blockCells.push_back(new Cell(2, 0)); 
  blockCells.push_back(new Cell(0, 1));
  blockCells.push_back(new Cell(1, 1));
  blockCells.push_back(new Cell(2, 1));
}

void LBlock::rotateClkwise() {
  Block::rotateClkwise();
}

void LBlock::rotateCounterClkwise() {
  Block::rotateCounterClkwise();
}

void LBlock::shiftLeft(int px) {
  Block::shiftLeft(px);
}

void LBlock::shiftRight(int px) {
  Block::shiftRight(px);
}

void LBlock::shiftUp(int px) {
  Block::shiftUp(px);
}

void LBlock::shiftDown(int px) {
  Block::shiftDown(px);
}

void LBlock::display() const {

}


// OBlock

OBlock::OBlock(int lvl) : Block(lvl) {
  init(); 
}

void OBlock::init() {
  blockCells.push_back(new Cell(0, 0));
  blockCells.push_back(new Cell(1, 0));
  blockCells.push_back(new Cell(0, 1));
  blockCells.push_back(new Cell(1, 1));
}

void OBlock::rotateClkwise() {
  Block::rotateClkwise();
}

void OBlock::rotateCounterClkwise() {
  Block::rotateCounterClkwise();
}

void OBlock::shiftLeft(int px) {
  Block::shiftLeft(px);
}

void OBlock::shiftRight(int px) {
  Block::shiftRight(px);
}

void OBlock::shiftUp(int px) {
  Block::shiftUp(px);
}

void OBlock::shiftDown(int px) {
  Block::shiftDown(px);
}

void OBlock::display() const {

}



// SBlock

SBlock::SBlock(int lvl) : Block(lvl) {
  init(); 
}

void SBlock::init() {
  blockCells.push_back(new Cell(0, 0));
  blockCells.push_back(new Cell(1, 0));
  blockCells.push_back(new Cell(1, 1));
  blockCells.push_back(new Cell(2, 1));
}

void SBlock::rotateClkwise() {
  Block::rotateClkwise();
}

void SBlock::rotateCounterClkwise() {
  Block::rotateCounterClkwise();
}

void SBlock::shiftLeft(int px) {
  Block::shiftLeft(px);
}

void SBlock::shiftRight(int px) {
  Block::shiftRight(px);
}

void SBlock::shiftUp(int px) {
  Block::shiftUp(px);
}

void SBlock::shiftDown(int px) {
  Block::shiftDown(px);
}

void SBlock::display() const {

}


// ZBlock

ZBlock::ZBlock(int lvl) : Block(lvl) {
  init(); 
}

void ZBlock::init() {
  blockCells.push_back(new Cell(1, 0));
  blockCells.push_back(new Cell(2, 0));
  blockCells.push_back(new Cell(0, 1));
  blockCells.push_back(new Cell(1, 1));
}

void ZBlock::rotateClkwise() {
  Block::rotateClkwise();
}

void ZBlock::rotateCounterClkwise() {
  Block::rotateCounterClkwise();
}

void ZBlock::shiftLeft(int px) {
  Block::shiftLeft(px);
}

void ZBlock::shiftRight(int px) {
  Block::shiftRight(px);
}

void ZBlock::shiftUp(int px) {
  Block::shiftUp(px);
}

void ZBlock::shiftDown(int px) {
  Block::shiftDown(px);
}

void ZBlock::display() const {

}



// TBlock

TBlock::TBlock(int lvl) : Block(lvl) {
  init(); 
}

void TBlock::init() {
  blockCells.push_back(new Cell(1, 0));
  blockCells.push_back(new Cell(0, 1));
  blockCells.push_back(new Cell(1, 1));
  blockCells.push_back(new Cell(2, 1));
}

void TBlock::rotateClkwise() {
  Block::rotateClkwise();
}

void TBlock::rotateCounterClkwise() {
  Block::rotateCounterClkwise();
}

void TBlock::shiftLeft(int px) {
  Block::shiftLeft(px);
}

void TBlock::shiftRight(int px) {
  Block::shiftRight(px);
}

void TBlock::shiftUp(int px) {
  Block::shiftUp(px);
}

void TBlock::shiftDown(int px) {
  Block::shiftDown(px);
}

void TBlock::display() const {

}

// star block '*' needed for level 4
