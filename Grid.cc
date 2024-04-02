#include "Grid.h"

// grid needs an overloaded<< operator to display the board (aka grid)


// code doesnt work: rough idea only
/* Grid::Grid(int width, int height) : width(width), height(height) {
    init();
}

void Grid::init() { // for setting initial state of the grid
    theGrid.clear();
    theGrid.resize(height, std::vector<Cell>(width));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            theGrid[i][j].setCoords(i, j); // Assuming Cell has a setCoords method
            // Initialize other cell properties if needed
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Grid& grid) {
    for (const auto& row : grid.theGrid) {
        for (const auto& cell : row) {
            out << cell; // Assuming Cell has an overloaded operator<<
        }
        out << '\n';
    }
    return out;
}*/ 