#ifndef CELL_H
#define CELL_H

#include <vector>
#include "Observer.h"
#include "subject.h"
using namespace std;

class Cell : public Observer , public Subject {
    bool isOn;
    string letter;
    vector<Observer*> observers; 
    int r, c; // Row and column

public:
    Cell();
    Cell(int r, int c); // parametric ctor (ADDED WITH BLOCK BRANCH)
    void setLetter(char c); // set letter to c
    string getLetter(); 
    bool getType() const; // 
    int getRow() const; // Returns the row number
    int getCol() const; // Returns the column number
    bool isFilled(); // check if this particualr cell is full
    void notify(Cell &c) override; // Notify changes on certain condition
    // or just have getcoords 
    void setType(char); // Sets the type of cell 
    void setCoords(int r, int c); // Sets the cell's coordinates
    ~Cell();
};

#endif // CELL_H
