#include "Grid.h"

// grid needs an overloaded<< operator to display the board (aka grid)

// code doesnt work: rough idea only
Grid::Grid(int height, int width) : height(height), width(width) {
    init(); // ideally no need for this, is there a start command?
}

void Grid::init() { // for setting initial state of the grid
    // theGrid.clear();
    // theGrid.resize(height, std::vector<Cell>(width));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            theGrid[i][j].setCoords(i, j); // Assuming Cell has a setCoords method
            // Initialize other cell properties if needed
        }
    } 
    // attach observer
} 

std::ostream& operator<<(std::ostream& out, const Grid& grid) {
    out << *grid.td;
    return out;
}
