#include <iostream>

#include "grid.h"

// Constructor that taking 2D GRID (map) from map object and passing it to out grid
grid::grid(const std::shared_ptr<map> &map)
: grid_(map->getLayout()){

}

void grid::setCell(int x, int y, char value) {
    if(x >= 0 && x < grid_[0].size() && y >= 0 && y < grid_.size()){ // Check if x,y is in the grid
        grid_[y][x] = value;
    }
    else
        throw std::out_of_range("Cell is out of the grid");
}

char grid::getCell(int x, int y) const {
    if(x >= 0 && x < grid_[0].size() && y >= 0 && y < grid_.size()){ // Check if x,y is in the grid
        return grid_[y][x];
    }
    else
        return '\0';
}

void grid::clearCell(int x, int y) {
    grid::setCell(x,y,'.');
}

void grid::displayMap() const {
    std::cout.flush();
    std::cout << system("cls"); // Clear console

    std::cout << "[Use arrows to move around]\n";

    for(const auto& row : grid_) { // Printing whole map in console
        for(const auto& cell : row) {
            std::cout << cell << ' ';
        }

        std::cout << '\n';
    }
}
