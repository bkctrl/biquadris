#include "Cell.h"

Cell::Cell() : letter(" "), r(0), c(0) {}

Cell::Cell(int row, int col) : letter(" "), r(row), c(col) {}

Cell::~Cell() {}

void Cell::setLetter(char c) {
  letter = c;
  update();
}

char Cell::getLetter() {
  return letter;
}

int Cell::getRow() const {
  return r;
}

int Cell::getCol() const {
  return c;
}

bool Cell::isFilled() {
  if (letter == " ") {
    return false;
  } else {
    return true;
  }
}

void Cell::notifyAll(Cell &c) {
  for (auto it : observers) {
    it->update(); 
  }
}

void Cell::setCoords(int row, int col) {
  r = row;
  c = col;
  update();
}
