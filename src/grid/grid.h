#pragma once
#include <cstdlib>
#include <vector>
#include <memory>

#include "../include/cell_names.h"
#include "../map/map.h"

class grid {
private:
    std::vector<std::vector<char>> grid_;

public:
    explicit grid(const std::shared_ptr<map>& map);

    void setCell(int x, int y, char value); // Set certain value in certain place in grid
    [[nodiscard]] char getCell(int x, int y) const; // return value from cell
    void clearCell(int x, int y); // Set cell as '.' which represent empty space in out 2D GRID (map)

    void displayMap() const; // Print map in console
};
