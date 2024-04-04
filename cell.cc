#include "cell.h"

Cell::Cell(int row, int col) : letter(' '), r(row), c(col), filled(false) {}

#include <algorithm> // Add missing include statement for the algorithm library

Cell::~Cell() {}

void Cell::setLetter(char c) {
    letter = c;
    filled = (c != ' ');
    notifyObservers();
}

char Cell::getLetter() const {
  return letter;
}

int Cell::getCol() const {
    return c;
}

bool Cell::isFilled() const {
    return filled;
}

void Cell::setCoords(int row, int col) {
    r = row;
    c = col;
    notifyObservers(); // Notify observers of the coordinate change
}

// This `update` method is called when the Cell as an Observer
// is notified by the Subjects it is observing.
void Cell::update(Subject &subject) {
    // Assuming that Cell observes other Cells, it will update its state based on changes in those Cells.
    // If this is not the case, this method will need to be adapted accordingly.
    
    // We should safely check if whoNotified is a Cell
    Cell* changedCell = dynamic_cast<Cell*>(&subject);
    if (changedCell) {
        // Now you can safely use changedCell to access Cell-specific methods and members.
        // For example, if we want to mirror the state (represented by letter) of the changed cell:
        if (changedCell->isFilled() && !this->isFilled()) {
            this->setLetter(changedCell->getLetter());
        }
    }
    // If there are other Subjects that Cell observes, handle them with additional checks and logic.
}
