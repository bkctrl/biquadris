#include "block.h"

Block::Block(char type, int orientation, Grid& grid, int x, int y, int level) 
    : letter(type), orientation(orientation), grid(grid), col(x), 
    row(y), level(level) {}

// Block::blockType getType() { return type; } // return the type of block
// block:: validity check 
// pass in: newmovement (ptrs to 4 cells that represents the final destination) + actual block (char)

Block::~Block() {
  for (Cell* cell : blockCells) {
    delete cell;
  }
  blockCells.clear();
}

char Block::getLetter() const { return letter; }
int Block::getColor() const {}
bool Block::isCleared() const {}
int Block::getLevel() const { return level; }

bool Block::isValidPlacement(Cell& cell, int y, int x) const {
  if (x < 0 || x > 11 || y < 0 || y > 15) {
    return false;
  }
  // Check if the cell is occupied
  return !cell.isOccupied();
}

Cell** Block::getOccupiedCells() {
  return blockCells.empty() ? nullptr : &blockCells[0];
}

void Block::removeFromCell(Cell& cell) {
  cell.updateCell(false, this);
}

void Block::init(char letter) {
  switch (letter) {
    case 'I':
      blockCells.push_back(new Cell(0, 0, &grid)); 
      blockCells.push_back(new Cell(1, 0, &grid));
      blockCells.push_back(new Cell(2, 0, &grid));
      blockCells.push_back(new Cell(3, 0, &grid));
      break;
    case 'J':
      blockCells.push_back(new Cell(0, 0, &grid));
      blockCells.push_back(new Cell(0, 1, &grid));
      blockCells.push_back(new Cell(1, 1, &grid));
      blockCells.push_back(new Cell(2, 1, &grid));
      break;
    case 'L':
      blockCells.push_back(new Cell(2, 0, &grid)); 
      blockCells.push_back(new Cell(0, 1, &grid));
      blockCells.push_back(new Cell(1, 1, &grid));
      blockCells.push_back(new Cell(2, 1, &grid));
      break;
    case 'O':
      blockCells.push_back(new Cell(0, 0, &grid));
      blockCells.push_back(new Cell(1, 0, &grid));
      blockCells.push_back(new Cell(0, 1, &grid));
      blockCells.push_back(new Cell(1, 1, &grid));
      break;
    case 'S':
      blockCells.push_back(new Cell(0, 0, &grid));
      blockCells.push_back(new Cell(1, 0, &grid));
      blockCells.push_back(new Cell(1, 1, &grid));
      blockCells.push_back(new Cell(2, 1, &grid));
      break;
    case 'Z':
      blockCells.push_back(new Cell(1, 0, &grid));
      blockCells.push_back(new Cell(2, 0, &grid));
      blockCells.push_back(new Cell(0, 1, &grid));
      blockCells.push_back(new Cell(1, 1, &grid));
      break;
    case 'T':
      blockCells.push_back(new Cell(1, 0, &grid));
      blockCells.push_back(new Cell(0, 1, &grid));
      blockCells.push_back(new Cell(1, 1, &grid));
      blockCells.push_back(new Cell(2, 1, &grid));
      break;
    default:
      // Handle invalid letter here
      break;
  }
}

// ---------------------------------- ROTATIONS ----------------------------------

void Block::rotateClockwise() {
  /*std::vector <Cell *> newPos;
  // do sth to newPos 
  // isvalidMove on the final pos 
  if (isValidMove(,I)){ 
  }*/
  // for (Cell* cell : blockCells) {
  //   int newRow = -cell->getCol();
  //   int newCol = cell->getRow();
  //   cell->setCoords(newRow, newCol);
  // }
  // if (isHeavy) shiftDown(1);
  // notifyObservers();
}

void Block::rotateCounterClockwise() {
  // for (Cell* cell : blockCells) {
  //   int newRow = cell->getCol();
  //   int newCol = -cell->getRow();
  //   cell->setCoords(newRow, newCol);
  // }
  // if (isHeavy) shiftDown(1);
  // notifyObservers();
}

// ---------------------------------- ROTATIONS ----------------------------------

void Block::shiftLeft() {
  // have a check for validity of move
  bool isValid = true;
  for (Cell* cell : blockCells) {
    int newCol = cell->getCol() - 1;
    int newRow = cell->getRow();
    if (isHeavy) newCol -= 1;
    if (!isValidPlacement(*cell, newRow, newCol)) {
      isValid = false;
    }
    if (isValid) {
      for (Cell* cell : blockCells) {
        cell->shiftCol(-1);
      }
    }
  }
  notifyObservers();
}






void Block::shiftRight() {
  for (Cell* cell : blockCells) {
    int newColumn = cell->getCol();
    cell->setCoords(cell->getRow(), newColumn);
  }
  notifyObservers();
}

void Block::shiftUp() {
  for (Cell* cell : blockCells) {
    int newCol = cell->getCol();
    cell->setCoords(cell->getRow(), newCol);
  }
  notifyObservers();
}

void Block::shiftDown() {
  for (Cell* cell : blockCells) {
    int newCol = cell->getCol();
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



void IBlock::rotateClkwise() { 
    Block::rotateClkwise();
  
}

void IBlock::rotateCounterClkwise() {
  Block::rotateCounterClkwise();
}

void IBlock::shiftLeft() {
  Block::shiftLe);
}

void IBlock::shiftRight() {
  Block::shiftRig);
}

void IBlock::shiftUp() {
  Block::shift);
}

void IBlock::shiftDown() {
  Block::shiftDo);
}

void IBlock::display() const {

}


void JBlock::rotateClkwise() {
  Block::rotateClkwise();
}

void JBlock::rotateCounterClkwise() {
  Block::rotateCounterClkwise();
}

void JBlock::shiftLeft() {
  Block::shiftLe);
}

void JBlock::shiftRight() {
  Block::shiftRig);
}

void JBlock::shiftUp() {
  Block::shift);
}

void JBlock::shiftDown() {
  Block::shiftDo);
}

void JBlock::display() const {

}


void LBlock::rotateClkwise() {
  Block::rotateClkwise();
}

void LBlock::rotateCounterClkwise() {
  Block::rotateCounterClkwise();
}

void LBlock::shiftLeft() {
  Block::shiftLe);
}

void LBlock::shiftRight() {
  Block::shiftRig);
}

void LBlock::shiftUp() {
  Block::shift);
}

void LBlock::shiftDown() {
  Block::shiftDo);
}

void LBlock::display() const {

}



// rotation on a OBlock effectively has no effect
void OBlock::rotateClkwise() {
}

void OBlock::rotateCounterClkwise() {
}

void OBlock::shiftLeft() {
  Block::shiftLe);
}

void OBlock::shiftRight() {
  Block::shiftRig);
}

void OBlock::shiftUp() {
  Block::shift);
}

void OBlock::shiftDown() {
  Block::shiftDo);
}

void OBlock::display() const {

}



void SBlock::rotateClkwise() {
  Block::rotateClkwise();
}

void SBlock::rotateCounterClkwise() {
  Block::rotateCounterClkwise();
}

void SBlock::shiftLeft() {
  Block::shiftLe);
}

void SBlock::shiftRight() {
  Block::shiftRig);
}

void SBlock::shiftUp() {
  Block::shift);
}

void SBlock::shiftDown() {
  Block::shiftDo);
}

void SBlock::display() const {

}



void ZBlock::rotateClkwise() {
  Block::rotateClkwise();
}

void ZBlock::rotateCounterClkwise() {
  Block::rotateCounterClkwise();
}

void ZBlock::shiftLeft() {
  Block::shiftLe);
}

void ZBlock::shiftRight() {
  Block::shiftRig);
}

void ZBlock::shiftUp() {
  Block::shift);
}

void ZBlock::shiftDown() {
  Block::shiftDo);
}

void ZBlock::display() const {

}



void TBlock::rotateClkwise() {
  Block::rotateClkwise();
}

void TBlock::rotateCounterClkwise() {
  Block::rotateCounterClkwise();
}

void TBlock::shiftLeft() {
  Block::shiftLe);
}

void TBlock::shiftRight() {
  Block::shiftRig);
}

void TBlock::shiftUp() {
  Block::shift);
}

void TBlock::shiftDown() {
  Block::shiftDo);
}

void TBlock::display() const {

}


// StarBlock

StarBlock::StarBlock(int lvl, const char letter) : Block(lvl, letter) {
  init(); 
}

void StarBlock::init() {
  blockCells.push_back(new Cell(0, 0));
  for (Cell* cell : blockCells) cell->setLetter('*');
}

// rotation on a StarBlock effectively has no effect
void StarBlock::rotateClkwise() {
}

void StarBlock::rotateCounterClkwise() {
}

void StarBlock::shiftLeft() {
  Block::shiftLe);
}

void StarBlock::shiftRight() {
  Block::shiftRig);
}

void StarBlock::shiftUp() {
  Block::shift);
}

void StarBlock::shiftDown() {
  Block::shiftDo);
}

void StarBlock::display() const {

}
