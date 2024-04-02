
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