#include <iostream>

#include "player.h"


player::player(int x, int y)
        : pos_x_{x}, pos_y_{y}, move_counter_{0} {
}

int player::getX() const {
    return pos_x_;
}

int player::getY() const {
    return pos_y_;
}

// Additional function to decrease the amount of repetitive code
void player::hasMoved() {
    move_counter_++;
    decreaseHungryAtMove();
}

// Function that take direction (1-4) and depending on that moving player in the right directory
void player::move(GET_FROM_INPUT dir) {
    switch (dir) {
        case GET_FROM_INPUT::DOWN:
            pos_y_++;
            hasMoved();
            break;
        case GET_FROM_INPUT::UP:
            pos_y_--;
            hasMoved();
            break;
        case GET_FROM_INPUT::LEFT:
            pos_x_--;
            hasMoved();
            break;
        case GET_FROM_INPUT::RIGHT:
            pos_x_++;
            hasMoved();
            break;
        case GET_FROM_INPUT::START_POSITION:
            pos_x_ = 0;
            pos_y_ = 0;
            break;
        default:
            std::cerr << "Invalid direction\n";
    }
}


// Reset stats to their maximum
void player::resetStats() {
    stats_.updateCurrentStat(stat_type::Health, stats_.getMaxStat(stat_type::Health));
    stats_.updateCurrentStat(stat_type::Hungry, stats_.getMaxStat(stat_type::Hungry));
    move_counter_ = 0;
}

// Check if player is dead (His health is <= 0)
bool player::isDead() const {
    return stats_.getCurrentStat(stat_type::Health) <= 0;
}

// At every "HUNGRY_DECAY_MOVE" (3 at default) step, decrease the hungry stat, and if hungry is equal to 0
// then decrease hp by one by every step;
void player::decreaseHungryAtMove() {
    if(stats_.getCurrentStat(stat_type::Hungry) > 0 && (move_counter_ % HUNGRY_DECAY_MOVES == 0)) {
        stats_.updateCurrentStat(stat_type::Hungry, -1);
    }
    else if (stats_.getCurrentStat(stat_type::Hungry) <= 0) {
        stats_.updateCurrentStat(stat_type::Health,-1);
    }
}

void player::displayStats() const {
    auto drawBar = [](int current, int max, int barWidth) {
        int filledWidth = (current * barWidth) / max;
        std::cout << "[";
        for (int i = 0; i < barWidth; ++i) {
            if (i < filledWidth) std::cout << "#";
            else std::cout << " ";
        }
        std::cout << "]";
    };


    std::cout << "Health: ";
    drawBar(stats_.getCurrentStat(stat_type::Health), stats_.getMaxStat(stat_type::Health), 10);
    std::cout << "  |  Hungry: ";
    drawBar(stats_.getCurrentStat(stat_type::Hungry), stats_.getMaxStat(stat_type::Hungry),5);
    std::cout << "\n";
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

void player::displayInventory() const {
    inventory_.showInventory();
}

void player::useItem(const std::string &item_name) {
    inventory_.useItem(item_name, *this);
}
