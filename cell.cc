#include "cell.h"
#include <string>

Cell::Cell(int x, int y, Grid *grid): 
    col{x}, row{y}, occupied{false}, block{nullptr}, parentGrid{grid} {}

bool Cell::isOccupied() {
    return occupied;
}

void Cell::updateCell(bool newoccupied, Block *newblock){
    occupied = newoccupied;
    block = newblock;
    this->notifyObservers();
}

void Cell::swapCell(Cell &other) {
    std::swap(occupied, other.occupied);
    std::swap(block, other.block);
    this->notifyObservers();
    other.notifyObservers();
}

int Cell::getCol() {
    return col;
}

int Cell::getRow() {
    return row;
}

Block* Cell::getOccupyingBlock(){
    return block;
}

void Cell::incrementRow(){
    ++row;
}

void Cell::shiftCol(int factor){
    col += factor;
}

Grid* Cell::getGrid(){
    return grid;
}
