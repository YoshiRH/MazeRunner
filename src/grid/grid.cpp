#include <iostream>

#include "grid.h"

// Constructor that taking 2D GRID (map) from map object and passing it to out grid
grid::grid(const std::shared_ptr<map> &map)
        : grid_(map->getLayout()) {

}

// Created function to check if the cell is in the grid to decrease the amount of code
bool grid::isInBounds(int x, int y, int width, int height) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

void grid::setCell(int x, int y, char value) {
    if (isInBounds(x, y, GRID_SIZE, GRID_SIZE)) { // Check if x,y is in the grid
        grid_[y][x] = value;
    } else
        throw std::out_of_range("Cell is out of the grid");
}

char grid::getCell(int x, int y) const {
    if (isInBounds(x, y, GRID_SIZE, GRID_SIZE)) { // Check if x,y is in the grid
        return grid_[y][x];
    } else
        throw std::out_of_range("Cell is out of the grid");
}

void grid::clearCell(int x, int y) {
    grid::setCell(x, y, EMPTY_CELL);
}

// Display 2D grid (map) in the console
void grid::displayMap(int playerX, int playerY) const {
    // Grid of bools with the same size as our map grid, false -> not visible, true -> visible
    // if certain cell has visible state in this vector we can print that cell in the console
    auto visibility = calculateVisibility(playerX, playerY);

    // Iterate through the whole grid and print out our map
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            std::cout << std::setw(2) << (visibility[y][x] ? grid_[y][x] : HIDDEN_CELL) << ' ';
        }
        std::cout << '\n';
    }
}

// Bool function that detect if there is a wall in the player view, if yes then block the sight
// behind the wall
// StartX,Y -> Player position | TargetX,Y -> certain Cell position in the player view
bool grid::blockedByWall(int startX, int startY, int targetX, int targetY) const {
    int x = std::abs(targetX - startX); // Calculate distance between player and a target
    int y = std::abs(targetY - startY);
    int checkX = (startX < targetX) ? 1 : -1; // Set the direction to check (Bresenham algorithm)
    int checkY = (startY < targetY) ? 1 : -1;
    int err = x - y;

    while (true) {
        if (startX == targetX && startY == targetY) {
            return false; // There is no Wall in the player sight
        }

        if (grid_[startY][startX] == OBSTACLE_CELL) {
            return true; // Found wall in the line sight
        }

        // Calculate next step thanks to Bresenham algorithm
        int e2 = 2 * err;
        if (e2 > -y) {
            err -= y;
            startX += checkX;
        }
        if (e2 < x) {
            err += x;
            startY += checkY;
        }

    }
}

// Function that set the view area of player, take player position and check terrain around him (of viewDistance cells)
std::vector<std::vector<bool>>
grid::calculateVisibility(int playerX, int playerY) const {

    // Vector with the same size as our map, each cell in this vector mean if the same cell on our map is visible
    // true -> visible | false -> hidden
    std::vector<std::vector<bool>> visible(GRID_SIZE, std::vector<bool>(GRID_SIZE, false));

    // Iterate around the player
    for (int y = -viewDistance_; y <= viewDistance_; y++) {
        for (int x = -viewDistance_; x <= viewDistance_; x++) {
            int cellX = playerX + x;
            int cellY = playerY + y;

            // Check if there is a obstacle in player view, if no,then set this cell as visible
            if (isInBounds(cellX, cellY, GRID_SIZE, GRID_SIZE) && !blockedByWall(playerX, playerY, cellX, cellY)) {
                visible[cellY][cellX] = true;
            }
        }
    }

    // return grid with player view area
    return visible;
}
