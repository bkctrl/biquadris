#include "cell.h"
#include <string>

Cell::Cell(int x, int y, Grid *grid): 
    col(x), row(y), occupied(false), block(nullptr), grid(grid) {}

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

void Cell::attach(Observer *o) {
    observers.emplace_back(o);
}

void Cell::detach(Observer *o) {
    observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
}

void Cell::notifyObservers() {
    for (auto &ob : observers) {
        ob->notify(*this);
    }
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

void Cell::shiftRow(int factor){
    row += factor;
}

void Cell::shiftCol(int factor){
    col += factor;
}

Grid* Cell::getGrid(){
    return grid;
}
