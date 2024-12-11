#pragma once

#include <cstdlib>
#include <fstream>
#include <vector>

// Class created as a holder for a map loaded from file.

class map {
private:
    std::vector<std::vector<char>> layout_; // 2D GRID of char which represent a map

public:
    map(int width, int height); // Size of map (2D GRID) later initialized in the game class

    void setCell(int x, int y, char value); // Set certain value in certain place in grid
    [[nodiscard]] char getCell(int x, int y) const; // return value from cell

    [[nodiscard]] std::vector<std::vector<char>> getLayout() const; // return layout (passing map -> 2D GRID)
    void loadFromFile(const std::string& filename); // Loading map template from .txt file
};
