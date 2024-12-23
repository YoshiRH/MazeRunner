#pragma once

#include <stdlib.h>
#include <string>
#include <algorithm>

#include "../include/cell_names.h"
#include "../statistic/statistic.h"

class player {
private:
    // Position of player on 2D GRID (map)
    int pos_x;
    int pos_y;

    // Player stats
    statistic health_;
    statistic hungry_;

    int moveCounter_;
    static constexpr int HUNGRY_DECAY_MOVES {3};

public:
    explicit player(int x = 0, int y = 0);

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

    [[nodiscard]] int getCurrentHealth() const;
    [[nodiscard]] int getCurrentHungry() const;
    [[nodiscard]] int getMaxHealth() const;
    [[nodiscard]] int getMaxHungry() const;

    void updateHealthByValue(int value);
    void updateHungryByValue(int value);
    void updateMaxHealthByValue(int value);
    void updateMaxHungryByValue(int value);

    void resetStats();
    bool isDead() const;

    void move(DIRECTIONS dir); // Moving player by one cell in direction taken from input
    void hasMoved();

    void displayStats() const;

private:

    void decreaseHungryAtMove();
};
