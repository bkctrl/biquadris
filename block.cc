#include "block.h"

// to-do : implement display() in each block
Block::Block(int level, char letter) : level(level), letter(letter) {
  init(letter);
}

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
  /*std::vector <Cell *> newPos;
  // do sth to newPos 
  // isvalidMove on the final pos 
  if (isValidMove(,I)){ 
    
  }*/
  for (Cell* cell : blockCells) {
    int newRow = -cell->getCol();
    int newCol = cell->getRow();
    cell->setCoords(newRow, newCol);
  }
  notifyObservers();
}

void Block::rotateCounterClkwise() {
  for (Cell* cell : blockCells) {
    int newRow = cell->getCol();
    int newCol = -cell->getRow();
    cell->setCoords(newRow, newCol);
  }
  notifyObservers();
}

// to-do : check if can't be shifted further
void Block::shiftLeft(int px) {
  // have a check for validity of move
  for (Cell* cell : blockCells) {
    int newColumn = cell->getCol() - px;
    // edge case: when getcol() is 0 would cause UB
    cell->setCoords(cell->getRow(), newColumn);
  }
  
  notifyObservers();
}

// to-do : check if can't be shifted further
void Block::shiftRight(int px) {
  for (Cell* cell : blockCells) {
    int newColumn = cell->getCol() + px;
    cell->setCoords(cell->getRow(), newColumn);
  }
  notifyObservers();
}

// to-do : check if can't be shifted further
void Block::shiftUp(int px) {
  for (Cell* cell : blockCells) {
    int newCol = cell->getCol() + px;
    cell->setCoords(cell->getRow(), newCol);
  }
  notifyObservers();
}

// to-do : check if can't be shifted further
void Block::shiftDown(int px) {
  for (Cell* cell : blockCells) {
    int newCol = cell->getCol() - px;
    cell->setCoords(cell->getRow(), newCol);
  }
  notifyObservers();
}

bool Block::isValidMove(std::vector<Cell *> newBlockCells, char charInput){ 
   for (int i = 0; i < blockCells.size(); i++) {
        blockCells[i]->setLetter(' '); // assign old curblock empty letter
    }
    for (int i = 0; i < newBlockCells.size(); i++) {
        if (newBlockCells[i]->isFilled()) { // if cell is not filled then assign it letter
            for (int i = 0; i < blockCells.size(); i++) {
                blockCells[i]->setLetter(charInput); // 
            }
            return false;
        }
    }
    return true; // newBlockCells does not overlap any existing blocks
}

void Block::display() const {
  
}

// This `update` method is called when the Block as an Observer
// is notified by the Subjects it is observing.
void Block::update(Subject &subject) {
  // Assuming that Cell observes other Cells, it will update its state based on changes in those Cells.
  // If this is not the case, this method will need to be adapted accordingly.
  
  // We should safely check if whoNotified is a Cell
  // Block* changedBlock = dynamic_cast<Block*>(&subject);
  // If there are other Subjects that Cell observes, handle them with additional checks and logic.
}

void Block::init(char letter) {
  switch (letter) {
    case 'I':
      blockCells.push_back(new Cell(0, 0)); 
      blockCells.push_back(new Cell(1, 0));
      blockCells.push_back(new Cell(2, 0));
      blockCells.push_back(new Cell(3, 0));
      break;
    case 'J':
      blockCells.push_back(new Cell(0, 0));
      blockCells.push_back(new Cell(0, 1));
      blockCells.push_back(new Cell(1, 1));
      blockCells.push_back(new Cell(2, 1));
      break;
    case 'L':
      blockCells.push_back(new Cell(2, 0)); 
      blockCells.push_back(new Cell(0, 1));
      blockCells.push_back(new Cell(1, 1));
      blockCells.push_back(new Cell(2, 1));
      break;
    case 'O':
      blockCells.push_back(new Cell(0, 0));
      blockCells.push_back(new Cell(1, 0));
      blockCells.push_back(new Cell(0, 1));
      blockCells.push_back(new Cell(1, 1));
      break;
    case 'S':
      blockCells.push_back(new Cell(0, 0));
      blockCells.push_back(new Cell(1, 0));
      blockCells.push_back(new Cell(1, 1));
      blockCells.push_back(new Cell(2, 1));
      break;
    case 'Z':
      blockCells.push_back(new Cell(1, 0));
      blockCells.push_back(new Cell(2, 0));
      blockCells.push_back(new Cell(0, 1));
      blockCells.push_back(new Cell(1, 1));
      break;
    case 'T':
      blockCells.push_back(new Cell(1, 0));
      blockCells.push_back(new Cell(0, 1));
      blockCells.push_back(new Cell(1, 1));
      blockCells.push_back(new Cell(2, 1));
      break;
    default:
      // Handle invalid letter here
      break;
  }
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
