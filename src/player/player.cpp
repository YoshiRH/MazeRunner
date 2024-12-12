#include <iostream>

#include "player.h"
#include "../include/cell_names.h"


player::player(int x, int y)
: pos_x{x}, pos_y{y}{

}

int player::getX() const { // Getter
    return pos_x;
}

int player::getY() const { // Getter
    return pos_y;
}

// Function that take direction (1-4) and depending on that moving player in the right directory
void player::move(DIRECTIONS dir) {
    switch (dir) {
        case 1:
                pos_y--;
            break;
        case 2:
                pos_y++;
            break;
        case 3:
                pos_x--;
            break;
        case 4:
                pos_x++;
            break;
        default:
            std::cerr << "Invalid direction\n";
    }
}
