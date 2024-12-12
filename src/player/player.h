#pragma once

#include <stdlib.h>
#include <string>

#include "../include/cell_names.h"

class player {
private:
    // Position of player on 2D GRID (map)
    int pos_x;
    int pos_y;

public:
    explicit player(int x = 0, int y = 0);

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

    void move(DIRECTIONS dir); // Moving player by one cell in direction taken from input
};
