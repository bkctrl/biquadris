#include "block.h"

Block::Block(char type, int orientation, Grid& grid, int bottomRow, int leftCol, int level) 
    : letter(type), orientation(orientation), grid(grid), bottomRow(bottomRow), leftCol(leftCol), level(level) {}


Block::~Block() {
  for (Cell* cell : blockCells) {
    delete cell;
  }
  blockCells.clear();
}

int Block::getColor() const {}
bool Block::isCleared() const {}

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
    if (level == 3 || level == 4) ++newRow;
    if (isHeavy) newRow += 2;
    // item == grid.accessGrid()[newRow][newCol]
    if (!isValidPlacement(newRow, newCol) &&
         std::find(blockCells.begin(), blockCells.end(), grid.accessGrid()[newRow][newCol]) == blockCells.end()) {
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
    if (!isValidPlacement(newRow, newCol) &&
         std::find(blockCells.begin(), blockCells.end(), grid.accessGrid()[newRow][newCol]) == blockCells.end()) {
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
    if (!isValidPlacement(newRow, newCol) &&
         std::find(blockCells.begin(), blockCells.end(), grid.accessGrid()[newRow][newCol]) == blockCells.end()) {
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

void Block::hardDrop() {
  bool canDrop = true;
  int minRow = 17;
  for (Cell* cell : blockCells) {
    int newRow = cell->getRow();
    for (int i = 0; i < 17-bottomRow; ++i) {
      ++newRow;
      if (!isValidPlacement(newRow, cell->getCol()) &&
         std::find(blockCells.begin(), blockCells.end(), grid.accessGrid()[newRow][cell->getCol()]) == blockCells.end()) { // a cell collides with a cell of another block
         // this means check the next cell in blockcells
        if (newRow-1 < minRow) minRow = newRow - 1; // collision at newRow
        break;
      }
    }
  }
  for (Cell* cell : blockCells) {
    cell->shiftRow(minRow - bottomRow);
  }
  notifyObservers();
}



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

JBlock::JBlock(Grid& grid, int level) : Block('J', 0, grid, 7, 2, level) {
  init();
}
void JBlock::rotateClockwise() { 
  // Block::rotateClkwise();
}
void JBlock::rotateCounterClockwise() {
  // Block::rotateCounterClkwise();
}

LBlock::LBlock(Grid& grid, int level) : Block('L', 0, grid, 7, 2, level) {
  init();
}
void LBlock::rotateClockwise() { 
  // Block::rotateClkwise();
}
void LBlock::rotateCounterClockwise() {
  // Block::rotateCounterClkwise();
}

OBlock::OBlock(Grid& grid, int level) : Block('O', 0, grid, 7, 2, level) {
  init();
}
void OBlock::rotateClockwise() {}
void OBlock::rotateCounterClockwise() {}

SBlock::SBlock(Grid& grid, int level) : Block('S', 0, grid, 7, 2, level) {
  init();
}
void SBlock::rotateClockwise() { 
  // Block::rotateClkwise();
}
void SBlock::rotateCounterClockwise() {
  // Block::rotateCounterClkwise();
}

ZBlock::ZBlock(Grid& grid, int level) : Block('Z', 0, grid, 7, 2, level) {
  init();
}
void ZBlock::rotateClockwise() { 
  // Block::rotateClkwise();
}
void ZBlock::rotateCounterClockwise() {
  // Block::rotateCounterClkwise();
}

TBlock::TBlock(Grid& grid, int level) : Block('T', 0, grid, 7, 2, level) {
  init();
}
void TBlock::rotateClockwise() { 
  // Block::rotateClkwise();
}
void TBlock::rotateCounterClockwise() {
  // Block::rotateCounterClkwise();
}

StarBlock::StarBlock(Grid& grid, int level) : Block('*', 0, grid, 7, 2, level) {
  init();
}
void StarBlock::rotateClockwise() {}
void StarBlock::rotateCounterClockwise() {}

