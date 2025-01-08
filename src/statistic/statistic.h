#pragma once

#include <iostream>
#include <algorithm>

#include "../stat_type/stat_type.h"

// Class wraper for individual stats
class statistic {
    int health_current, health_max;
    int hungry_current, hungry_max;

public:
    statistic(int Health, int Hungry);

    [[nodiscard]] int getCurrentStat(stat_type type) const;
    [[nodiscard]] int getMaxStat(stat_type type) const;
    void updateCurrentStat(stat_type type, int value);
    void updateMaxStat(stat_type type, int value);
};