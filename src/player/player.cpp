#include <iostream>

#include "player.h"
#include "../include/cell_names.h"


player::player(int x, int y)
        : pos_x{x}, pos_y{y}, moveCounter_{0} {

}

int player::getX() const {
    return pos_x;
}

int player::getY() const {
    return pos_y;
}

// Additional function to decrease the amount of repetitive code
void player::hasMoved() {
    moveCounter_++;
    decreaseHungryAtMove();
}

// Function that take direction (1-4) and depending on that moving player in the right directory
void player::move(GET_FROM_INPUT dir) {
    switch (dir) {
        case DOWN:
            if(pos_y < GRID_SIZE) {
                pos_y++;
                hasMoved();
            }
            break;
        case UP:
            if(pos_y > 0) {
                pos_y--;
                hasMoved();
            }
            break;
        case LEFT:
            if(pos_x > 0) {
                pos_x--;
                hasMoved();
            }
            break;
        case RIGHT:
            if(pos_x < GRID_SIZE) {
                pos_x++;
                hasMoved();
            }
            break;
        case START_POSITION:
            pos_x = 0;
            pos_y = 0;
            break;
        default:
            std::cerr << "Invalid direction\n";
    }
}


// Reset stats to their maximum
void player::resetStats() {
    stats_.updateCurrentStat(stat_type::Health, stats_.getMaxStat(stat_type::Health));
    stats_.updateCurrentStat(stat_type::Hungry, stats_.getMaxStat(stat_type::Hungry));
    moveCounter_ = 0;
}

// Check if player is dead (His health is <= 0)
bool player::isDead() const {
    return stats_.getCurrentStat(stat_type::Health) <= 0;
}

// At every "HUNGRY_DECAY_MOVE" (3 at default) step, decrease the hungry stat, and if hungry is equal to 0
// then decrease hp by one;
void player::decreaseHungryAtMove() {
    if (moveCounter_ % HUNGRY_DECAY_MOVES == 0) {
        if(stats_.getCurrentStat(stat_type::Hungry) == 0)
            stats_.updateCurrentStat(stat_type::Health, -1);
        else
            stats_.updateCurrentStat(stat_type::Hungry, -1);
    }
}

void player::displayStats() const {
    std::cout << "Health: " << stats_.getCurrentStat(stat_type::Health) << "/" << stats_.getMaxStat(stat_type::Health)
              << "  |  Hungry: " << stats_.getCurrentStat(stat_type::Hungry) << "/"
              << stats_.getMaxStat(stat_type::Hungry);
}

int player::getCurrentStat(stat_type type) const {
    return stats_.getCurrentStat(type);
}

int player::getMaxStat(stat_type type) const {
    return stats_.getMaxStat(type);
}

void player::updateCurrentStat(stat_type type, int value) {
    stats_.updateCurrentStat(type, value);
}

void player::updateMaxStat(stat_type type, int value) {
    stats_.updateMaxStat(type, value);
}
