#ifndef CELL_H
#define CELL_H

#include <vector>
#include "Observer.h"
#include "subject.h"

class Cell : public Observer , public Subject{
    bool isOn;
    std::vector<Observer*> observers; 
    int r, c; // Row and column

public:
    Cell();
    bool getType() const; // 
    int getRow() const; // Returns the row number
    int getCol() const; // Returns the column number
    void notify(Cell &c) override; // Notify changes on certain condition
    // or just have getcoords 
    void setType(char); // Sets the type of cell 
    void setCoords(int r, int c); // Sets the cell's coordinates

    ~Cell();
};

#endif // CELL_H
