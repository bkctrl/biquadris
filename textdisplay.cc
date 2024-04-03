#include "textdisplay.h"
#include <iostream>
#include <string>

TextDisplay::TextDisplay(int width, int height) : width(width), height(height) {
  theDisplay = std::vector< std::vector<char> >(height, std::vector<char>(width, ' '));
}

TextDisplay::~TextDisplay() {}

void TextDisplay::notify(Cell &c) {
  int row = c.getRow();
  int col = c.getCol();
  theDisplay[row][col] = c.isFilled() ? ' ' : c.getLetter();
}

void TextDisplay::displayboard() {
  for (const auto &row : theDisplay) { // for every row
    for (char cell : row) { // for every cell in each row
      std::cout << cell;
    }
    std::cout << std::endl;
  }
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
  for (const auto &row : td.theDisplay) { // for every row
    for (char cell : row) { // for every cell in each row
      out << cell;
    }
    out << std::endl;
  }
  return out;
}
