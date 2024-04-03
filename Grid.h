
// grid would have override update function that does sth simialr to turnon + toggle in A4q1
// grid ctor merely initalize the empty grid (11 x 15)
// need to have an overloaded friend operator<< to draw the gameboard 
// friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
// 2D array of 11 by 15 characters 

// grid init (which is made up of cells)
// grid:: checks if row is full (iteratively checks if all cells in a row is full)
// gird:: clears row 

// block is created inside a grid

// when adding a curblock, curblock moves in a user defined way, when the user drops it, the block becomes part of the grid 
// block is only indepdent when its first added to the grid, other times its part of grid. grid will handle it on its own 

// textdisplay are a bunch of functions that prints the grid

#ifndef GRID_H
#define GRID_H

#include <vector>
#include <iostream>
#include "cell.h"
#include "textdisplay.h"

class Grid {
private:
    int width;
    int height;
    std::vector<std::vector<Cell>> theGrid; // this stores the actual cells within each 18x11 fixed-sized grid for current player
    TextDisplay *td; // textdisplay that 

public:
    Grid(int height, int width);
    void init(); // for setting initial state of the grid

    friend std::ostream& operator<<(std::ostream& out, const Grid& grid);
};

#endif // GRID_H
