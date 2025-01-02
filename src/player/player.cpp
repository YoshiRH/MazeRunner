#include <iostream>

#include "player.h"
#include "../include/cell_names.h"


player::player(int x, int y)
        : pos_x{x}, pos_y{y}, health_{20,20}, hungry_{20,20}, moveCounter_{0} {

}

int player::getX() const { // Getter
    return pos_x;
}

int player::getY() const { // Getter
    return pos_y;
}

// Additional function to decrease the amount of repetitive code
void player::hasMoved() {
    moveCounter_++;
    decreaseHungryAtMove();
}

// Function that take direction (1-4) and depending on that moving player in the right directory
void player::move(DIRECTIONS dir) {
    switch (dir) {
        case 1:
            pos_y--;
            hasMoved();
            break;
        case 2:
            pos_y++;
            hasMoved();
            break;
        case 3:
            pos_x--;
            hasMoved();
            break;
        case 4:
            pos_x++;
            hasMoved();
            break;
        case 5:
            pos_x = 0;
            pos_y = 0;
            break;
        default:
            std::cerr << "Invalid direction\n";
    }
}

int player::getCurrentHealth() const {
    return health_.get("current");
}

int player::getCurrentHungry() const {
    return hungry_.get("current");
}

int player::getMaxHealth() const {
    return health_.get("max");
}

int player::getMaxHungry() const {
    return hungry_.get("max");
}

// Update function
void player::updateHealthByValue(int value) {
    health_.update("current", value);
}

// Update function
void player::updateHungryByValue(int value) {
    hungry_.update("current", value);
}

// Update function
void player::updateMaxHealthByValue(int value) {
    health_.update("max", value);
}

// Update function
void player::updateMaxHungryByValue(int value) {
    hungry_.update("max", value);
}

// Reset stats to their maximum
void player::resetStats() {
    health_ = statistic{health_.get("max"), health_.get("max")};
    hungry_ = statistic{hungry_.get("max"), hungry_.get("max")};
    moveCounter_ = 0;
}

// Check if player is dead (His health is <= 0)
bool player::isDead() const {
    return health_.isZero();
}

// At every "HUNGRY_DECAY_MOVE" (3 at default) step, decrease the hungry stat, and if hungry is equal to 0
// then decrease hp by one;
void player::decreaseHungryAtMove() {
    if(moveCounter_ % HUNGRY_DECAY_MOVES == 0) {
        if(hungry_.get("current") == 0)
            health_.update("current", -1);
        else
            hungry_.update("current",-1);
    }
}

void player::displayStats() const {
    std::cout << "Health: " << health_.get("current") << "/" << health_.get("max")
    << "  |  Hungry: " << hungry_.get("current") << "/" << hungry_.get("max");
}
