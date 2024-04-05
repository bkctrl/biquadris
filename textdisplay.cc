#include "textdisplay.h"
#include <iostream>
#include <string>

TextDisplay::TextDisplay() : theDisplay(18, std::vector<char>(11, ' ')), width(11), height(18) {}

// updates the display with the changed cell state upon notification from said cell
void TextDisplay::notify(Cell &c) {
  int row = c.getRow();
  int col = c.getCol();
  theDisplay[row][col] = c.isOccupied() ? ' ' : c.getOccupyingBlock()->getLetter();
}

// void TextDisplay::displayboard() {
//   for (const auto &row : theDisplay) { // for every row
//     for (char cell : row) { // for every cell in each row
//       std::cout << cell;
//     }
//     std::cout << std::endl;
//   }
// }


std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
  out << "-----------" << std::endl;
  for (const auto &row : td.theDisplay) { // for every row
    for (char cell : row) { // for every cell in each row
      out << cell;
    }
    out << std::endl;
  }
  out << "-----------" << std::endl;
  return out;
}
