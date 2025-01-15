#pragma once

#include <stdlib.h>
#include <string>
#include <algorithm>

#include "../include/cell_names.h"
#include "../statistic/statistic.h"
#include "../stat_type/stat_type.h"
#include "../inventory/inventory.h"
#include "../map/map.h"

class player {
    // Position of player on 2D GRID (map)
    int pos_x_;
    int pos_y_;

    // Player stats
    statistic stats_{10,20};

    int move_counter_;
    static constexpr int HUNGRY_DECAY_MOVES {3};

    void decreaseHungryAtMove();

public:
    // Objects ------------------------------
    inventory inventory_;

    // Functions ----------------------------
    explicit player(int x = 0, int y = 0);

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

    [[nodiscard]] int getCurrentStat(stat_type type) const;
    [[nodiscard]] int getMaxStat(stat_type type) const;
    void updateCurrentStat(stat_type type, int value);
    void updateMaxStat(stat_type type, int value);

    void useItem(const std::string& item_name);

    void resetStats(); // Reset stats to their maximum
    bool isDead() const; // Check if player is dead

    void move(GET_FROM_INPUT dir); // Moving player by one cell in direction taken from input
    void hasMoved();

    void displayStats() const;
    void displayInventory() const;
};
