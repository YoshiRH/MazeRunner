#pragma once

#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>

#include "../include/cell_names.h"

// Class created as a holder for a map loaded from file.

class map {
private:
    std::vector<std::vector<char>> layout_; // 2D GRID of char which represent a map

public:
    map(int width = GRID_SIZE, int height = GRID_SIZE); // Size of map (2D GRID) later initialized in the game class

    void setCell(int x, int y, char value); // Set certain value in certain place in grid
    [[nodiscard]] char getCell(int x, int y) const; // return value from cell

    [[nodiscard]] const std::vector<std::vector<char>>& getLayout() const; // return layout (passing map -> 2D GRID)
    void loadFromFile(const std::string& filename); // Loading map template from .txt file
};
