#ifndef CELL_H
#define CELL_H

#include <vector>
#include "observer.h"
#include "subject.h"

class Cell : public Observer , public Subject {
    char letter = ' ';
    std::vector<Observer*> observers; 
    int r, c; // Row and column
    bool filled; // Stores true if cell is filled

public:
    Cell(int r = 0, int c = 0); // parametric ctor (ADDED WITH BLOCK BRANCH)
    void setLetter(char c); // set letter to c
    char getLetter() const; 
    int getRow() const; // Returns the row number
    int getCol() const; // Returns the column number
    bool isFilled() const; // check if this particualr cell is full
    // void notifyObservers(); // Notify observers of changes to this cell
    void setCoords(int r, int c); // Sets the cell's coordinates
    ~Cell() override;
    
    // Observer interface
    void update(Subject &subject) override;
};

#endif // CELL_H
