#pragma once
#include <cstdlib>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>

#include "../include/cell_names.h"
#include "../map/map.h"

class grid {
private:
    std::vector<std::vector<char>> grid_;
    static int constexpr viewDistance_ {2};

public:
    explicit grid(const std::shared_ptr<map>& map);

    void setCell(int x, int y, char value); // Set certain value in certain place in grid
    [[nodiscard]] char getCell(int x, int y) const; // return value from cell
    void clearCell(int x, int y); // Set cell as '.' which represent empty space in out 2D GRID (map)

    void displayMap(int playerX, int playerY) const; // Print map in console

    // Additional function for displayMap, for detecting walls and blocking vision behind them
    [[nodiscard]] bool blockedByWall(int startX, int startY, int targetX, int targetY) const;
    // Function to check if certain [x,y] position is in the bounds (use for check if cell is in the grid)
    [[nodiscard]] static bool isInBounds(int x, int y, int width, int height) ;

    // Calculate the area of player view
    [[nodiscard]] std::vector<std::vector<bool>> calculateVisibility(int playerX, int playerY) const;


};
