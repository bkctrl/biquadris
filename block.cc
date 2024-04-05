#include "block.h"

Block::Block(char type, int orientation, Grid& grid, int row, int col, int level) 
    : letter(type), orientation(orientation), grid(grid), row(row), col(col), 
    level(level) {}

// Block::blockType getType() { return type; } // return the type of block
// block:: validity check 
// pass in: newmovement (ptrs to 4 cells that represents the final destination) + actual block (char)

Block::~Block() {
  for (Cell* cell : blockCells) {
    delete cell;
  }
  blockCells.clear();
}

bool Block::isCleared() const {
  for (Cell* cell : blockCells) {
    if (!cell->isOccupied()) {
      return false;
    }
  }
  return true;
}

int Block::getColor() const {
  switch (letter) {
    case 'I':
      return 0;
    case 'J':
      return 1;
    case 'L':
      return 2;
    case 'O':
      return 3;
    case 'S':
      return 4;
    case 'Z':
      return 5;
    case 'T':
      return 6;
    default:
      return 7;
  }
}

bool Block::isValidPlacement(int row, int col) const {
  if (col < 0 || col > 11 || row < 0 || row > 17) {
    return false;
  }
  // Check if the cell is occupied
  return !grid.accessGrid()[row][col].isOccupied();
}

Cell** Block::getOccupiedCells() {
  return blockCells.empty() ? nullptr : &blockCells[0];
}

void Block::removeFromCell(Cell& cell) {
  cell.updateCell(false, this);
}

void Block::init() {
  switch (letter) {
    case 'I':
      if (isValidPlacement(3, 0) && isValidPlacement(3, 1) && isValidPlacement(3, 2) && isValidPlacement(3, 3)) {
        blockCells.push_back(new Cell(3, 0, &grid)); 
        blockCells.push_back(new Cell(3, 1, &grid));
        blockCells.push_back(new Cell(3, 2, &grid));
        blockCells.push_back(new Cell(3, 3, &grid));
      }
      break;
    case 'J':
      if (isValidPlacement(2, 0) && isValidPlacement(3, 0) && isValidPlacement(3, 1) && isValidPlacement(3, 2)) {
        blockCells.push_back(new Cell(2, 0, &grid));
        blockCells.push_back(new Cell(3, 0, &grid));
        blockCells.push_back(new Cell(3, 1, &grid));
        blockCells.push_back(new Cell(3, 2, &grid));
      }
      break;
    case 'L':
      if (isValidPlacement(2, 0) && isValidPlacement(3, 0) && isValidPlacement(3, 1) && isValidPlacement(3, 2)) {
        blockCells.push_back(new Cell(2, 1, &grid));
        blockCells.push_back(new Cell(2, 2, &grid));
        blockCells.push_back(new Cell(3, 0, &grid));
        blockCells.push_back(new Cell(3, 1, &grid));
      }
      break;
    case 'T':
      if (isValidPlacement(2, 0) && isValidPlacement(2, 1) && isValidPlacement(2, 2) && isValidPlacement(3, 1)) {
        blockCells.push_back(new Cell(2, 1, &grid));
        blockCells.push_back(new Cell(2, 2, &grid));
        blockCells.push_back(new Cell(2, 3, &grid));
        blockCells.push_back(new Cell(3, 2, &grid));
      }
      break;
    case '*':
      blockCells.push_back(new Cell(3, 5, &grid));
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

void Block::rotateClockwise() {
    std::vector<Cell*> newCells;
    // Assume bottom left cell of the block is the pivot
    int pivotCol = leftCol;
    int pivotRow = bottomRow;
    
    // Calculate new positions after rotation
    for (Cell* cell : occupiedCells) {
        int newCol = pivotCol + (cell->getRow() - pivotRow);
        int newRow = pivotRow - (cell->getCol() - pivotCol);
        
        if (!gameGrid.isValidPosition(newCol, newRow) || gameGrid.isOccupied(newCol, newRow)) {
            return; // Can't rotate due to boundary issues or cell being occupied
        }
        newCells.push_back(gameGrid.getCell(newCol, newRow));
    }

    // Perform the rotation since all new positions are valid
    for (size_t i = 0; i < occupiedCells.size(); ++i) {
        occupiedCells[i]->setOccupied(false);
        newCells[i]->setOccupied(true);
        newCells[i]->setBlock(this);
    }
    occupiedCells = newCells;
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

// void Block::setHeavy(int newHeavy) {
//   heavy = newHeavy;
// }

// int Block::getHeavy() {
//   return heavy;
// }

// ---------------------------------- ROTATIONS ----------------------------------

void Block::shiftLeft() {
  // have a check for validity of move
  bool isValid = true;
  for (Cell* cell : blockCells) {
    int newCol = cell->getCol() - 1;
    int newRow = cell->getRow();
    if (level == 3 || level == 4) ++newRow;
    if (isHeavy) newRow += 2;
    if (!isValidPlacement(newRow, newCol)) {
      isValid = false;
      break;
    }
  }
  if (isValid) {
    for (Cell* cell : blockCells) {
      if (level == 3 || level == 4) cell->shiftRow(1);;
      if (isHeavy) cell->shiftRow(2);
      cell->shiftCol(-1);
    }
  }
  notifyObservers();
}


void Block::shiftRight() {
  // have a check for validity of move
  bool isValid = true;
  for (Cell* cell : blockCells) {
    int newCol = cell->getCol() + 1;
    int newRow = cell->getRow();
    if (level == 3 || level == 4) ++newRow;
    if (isHeavy) newRow += 2;
    if (!isValidPlacement(newRow, newCol)) {
      isValid = false;
      break;
    }
  }
  if (isValid) {
    for (Cell* cell : blockCells) {
      if (level == 3 || level == 4) cell->shiftRow(1);;
      if (isHeavy) cell->shiftRow(2);
      cell->shiftCol(1);
    }
  }
  notifyObservers();
}


void Block::shiftDown() {
  // have a check for validity of move
  bool isValid = true;
  for (Cell* cell : blockCells) {
    int newCol = cell->getCol();
    int newRow = cell->getRow();
    if (level == 3 || level == 4) ++newRow;
    if (!isValidPlacement(newRow, newCol)) {
      isValid = false;
      break;
    }
  }
  if (isValid) {
    for (Cell* cell : blockCells) {
      if (level == 3 || level == 4) cell->shiftRow(1);;
      cell->shiftRow(1);
    }
  }
  notifyObservers();
}

void hardDrop(); // drop the block to the lowest possible position
void centerDrop(); // drop the block to the center of the grid


// // This `update` method is called when the Block as an Observer
// // is notified by the Subjects it is observing.
// void Block::update(Subject &subject) {
//   // Assuming that Cell observes other Cells, it will update its state based on changes in those Cells.
//   // If this is not the case, this method will need to be adapted accordingly.
  
//   // We should safely check if whoNotified is a Cell
//   // Block* changedBlock = dynamic_cast<Block*>(&subject);
//   // If there are other Subjects that Cell observes, handle them with additional checks and logic.
// }


IBlock::IBlock(Grid& grid, int level) : Block('I', 0, grid, 7, 2, level) {
  init();
}
void IBlock::rotateClockwise() { 
  // Block::rotateClkwise();
}
void IBlock::rotateCounterClockwise() {
  // Block::rotateCounterClkwise();
}

JBlock::JBlock(Grid& grid, int level) : Block('I', 0, grid, 7, 2, level) {
  init();
}
void JBlock::rotateClockwise() { 
  // Block::rotateClkwise();
}
void JBlock::rotateCounterClockwise() {
  // Block::rotateCounterClkwise();
}

LBlock::LBlock(Grid& grid, int level) : Block('I', 0, grid, 7, 2, level) {
  init();
}
void LBlock::rotateClockwise() { 
  // Block::rotateClkwise();
}
void LBlock::rotateCounterClockwise() {
  // Block::rotateCounterClkwise();
}

OBlock::OBlock(Grid& grid, int level) : Block('I', 0, grid, 7, 2, level) {
  init();
}
void OBlock::rotateClockwise() { 
  // Block::rotateClkwise();
}
void OBlock::rotateCounterClockwise() {
  // Block::rotateCounterClkwise();
}

SBlock::SBlock(Grid& grid, int level) : Block('I', 0, grid, 7, 2, level) {
  init();
}
void SBlock::rotateClockwise() { 
  // Block::rotateClkwise();
}
void SBlock::rotateCounterClockwise() {
  // Block::rotateCounterClkwise();
}

ZBlock::ZBlock(Grid& grid, int level) : Block('I', 0, grid, 7, 2, level) {
  init();
}
void ZBlock::rotateClockwise() { 
  // Block::rotateClkwise();
}
void ZBlock::rotateCounterClockwise() {
  // Block::rotateCounterClkwise();
}

TBlock::TBlock(Grid& grid, int level) : Block('I', 0, grid, 7, 2, level) {
  init();
}
void TBlock::rotateClockwise() { 
  // Block::rotateClkwise();
}
void TBlock::rotateCounterClockwise() {
  // Block::rotateCounterClkwise();
}

StarBlock::StarBlock(Grid& grid, int level) : Block('I', 0, grid, 7, 2, level) {
  init();
}
void StarBlock::rotateClockwise() { 
  // Block::rotateClkwise();
}
void StarBlock::rotateCounterClockwise() {
  // Block::rotateCounterClkwise();
}















// // void IBlock::display() const {

// // }


// void JBlock::rotateClkwise() {
//   // Block::rotateClkwise();
// }

// void JBlock::rotateCounterClkwise() {
//   // Block::rotateCounterClkwise();
// }

// void JBlock::shiftLeft() {
//   Block::shiftLe);
// }

// void JBlock::shiftRight() {
//   Block::shiftRig);
// }

// void JBlock::shiftUp() {
//   Block::shift);
// }

// void JBlock::shiftDown() {
//   Block::shiftDo);
// }

// // void JBlock::display() const {

// // }


// void LBlock::rotateClkwise() {
//   // Block::rotateClkwise();
// }

// void LBlock::rotateCounterClkwise() {
//   // Block::rotateCounterClkwise();
// }

// void LBlock::shiftLeft() {
//   Block::shiftLe);
// }

// void LBlock::shiftRight() {
//   Block::shiftRig);
// }

// void LBlock::shiftUp() {
//   Block::shift);
// }

// void LBlock::shiftDown() {
//   Block::shiftDo);
// }

// // void LBlock::display() const {

// // }



// // rotation on a OBlock effectively has no effect
// void OBlock::rotateClkwise() {
// }

// void OBlock::rotateCounterClkwise() {
// }

// void OBlock::shiftLeft() {
//   Block::shiftLe);
// }

// void OBlock::shiftRight() {
//   Block::shiftRig);
// }

// void OBlock::shiftUp() {
//   Block::shift);
// }

// void OBlock::shiftDown() {
//   Block::shiftDo);
// }

// // void OBlock::display() const {

// // }



// void SBlock::rotateClkwise() {
//   // Block::rotateClkwise();
// }

// void SBlock::rotateCounterClkwise() {
//   // Block::rotateCounterClkwise();
// }

// void SBlock::shiftLeft() {
//   Block::shiftLe);
// }

// void SBlock::shiftRight() {
//   Block::shiftRig);
// }

// void SBlock::shiftUp() {
//   Block::shift);
// }

// void SBlock::shiftDown() {
//   Block::shiftDo);
// }

// // void SBlock::display() const {

// // }



// void ZBlock::rotateClkwise() {
//   // Block::rotateClkwise();
// }

// void ZBlock::rotateCounterClkwise() {
//   // Block::rotateCounterClkwise();
// }

// void ZBlock::shiftLeft() {
//   Block::shiftLe);
// }

// void ZBlock::shiftRight() {
//   Block::shiftRig);
// }

// void ZBlock::shiftUp() {
//   Block::shift);
// }

// void ZBlock::shiftDown() {
//   Block::shiftDo);
// }

// // void ZBlock::display() const {

// // }



// void TBlock::rotateClkwise() {
//   // Block::rotateClkwise();
// }

// void TBlock::rotateCounterClkwise() {
//   // Block::rotateCounterClkwise();
// }

// void TBlock::shiftLeft() {
//   Block::shiftLe);
// }

// void TBlock::shiftRight() {
//   Block::shiftRig);
// }

// void TBlock::shiftUp() {
//   Block::shift);
// }

// void TBlock::shiftDown() {
//   Block::shiftDo);
// }

// // void TBlock::display() const {

// // }


// // StarBlock

// StarBlock::StarBlock(int lvl, const char letter) : Block(lvl, letter) {
//   init(); 
// }

// void StarBlock::init() {
//   blockCells.push_back(new Cell(0, 0));
//   for (Cell* cell : blockCells) cell->setLetter('*');
// }

// // rotation on a StarBlock effectively has no effect
// void StarBlock::rotateClkwise() {
// }

// void StarBlock::rotateCounterClkwise() {
// }

// void StarBlock::shiftLeft() {
//   Block::shiftLe);
// }

// void StarBlock::shiftRight() {
//   Block::shiftRig);
// }

// void StarBlock::shiftUp() {
//   Block::shift);
// }

// void StarBlock::shiftDown() {
//   Block::shiftDo);
// }

// // void StarBlock::display() const {

// // }
