#pragma once

#include <stdlib.h>
#include <string>
#include <algorithm>

#include "../include/cell_names.h"
#include "../statistic/statistic.h"
#include "../stat_type/stat_type.h"

class player {
private:
    // Position of player on 2D GRID (map)
    int pos_x;
    int pos_y;

    // Player stats
    statistic stats_{20,20};

    int moveCounter_;
    static constexpr int HUNGRY_DECAY_MOVES {3};

public:
    explicit player(int x = 0, int y = 0);

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

    int getCurrentStat(stat_type type) const;
    int getMaxStat(stat_type type) const;
    void updateCurrentStat(stat_type type, int value);
    void updateMaxStat(stat_type type, int value);

    void resetStats();
    bool isDead() const;

    void move(GET_FROM_INPUT dir); // Moving player by one cell in direction taken from input
    void hasMoved();

    void displayStats() const;

private:

    void decreaseHungryAtMove();
};
