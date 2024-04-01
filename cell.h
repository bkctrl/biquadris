#ifndef CELL_H
#define CELL_H

#include <vector>
#include "Observer.h"

class Cell : public Observer {
    bool isOn;
    std::vector<Observer*> observers; 
    int r, c; // Row and column

public:
    Cell();
    bool getType() const; // 
    int getRow() const; // Returns the row number
    int getCol() const; // Returns the column number
    // or just have getcoords 
    void setType(char); // Sets the type of cell 
    void setCoords(int r, int c); // Sets the cell's coordinates

    void attach(Observer *o); // Attach an observer
    void notify(Cell &c) override; // Notify changes on certain condition
    void notifyObservers(); // Notify only the attached observers of a change in this cell

    ~Cell();
};

#endif // CELL_H
