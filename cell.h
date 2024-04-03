#ifndef CELL_H
#define CELL_H

#include <vector>
#include "Observer.h"
#include "subject.h"
using namespace std;

class Cell : public Observer , public Subject {
    string letter;
    vector<Observer*> observers; 
    int r, c; // Row and column

public:
    Cell();
    Cell(int r, int c); // parametric ctor (ADDED WITH BLOCK BRANCH)
    void setLetter(string c); // set letter to c
    string getLetter(); 
    bool getType() const; // 
    int getRow() const; // Returns the row number
    int getCol() const; // Returns the column number
    bool isFilled(); // check if this particualr cell is full
    void notifyAll(Cell &c); // Notify changes on certain condition or just have getcoords 
    void setCoords(int r, int c); // Sets the cell's coordinates
    ~Cell();
};

#endif // CELL_H
