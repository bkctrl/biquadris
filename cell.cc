#include "cell.h"
#include <string>

Cell::Cell(int x, int y, Grid *grid): posX{x}, posY{y}, occupied{false}, currentBlock{nullptr}, parentGrid{grid} {}

bool Cell::isOccupied() {
    return occupied;
}

void Cell::updateCell(bool newoccupied, Block *newCurrentBlock){
    occupied = newoccupied;
    currentBlock = newCurrentBlock;
    this->notifyObservers();
}

void Cell::swapCell(Cell &other) {
    std::swap(occupied, other.occupied);
    std::swap(currentBlock, other.currentBlock);
    this->notifyObservers();
    other.notifyObservers();
}

int Cell::getX() {
    return posX;
}

int Cell::getY() {
    return posY;
}

Block* Cell::getOccupyingBlock(){
    return currentBlock;
}

void Cell::incrementY(){
    ++posY;
}

Grid* Cell::getParentGrid(){
    return parentGrid;
}
