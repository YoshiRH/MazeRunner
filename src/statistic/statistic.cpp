#include "statistic.h"

// Constructor
statistic::statistic(int health, int hungry)
        : health_current{health}, health_max{health}, hungry_current{hungry}, hungry_max{hungry} {

}

int statistic::getCurrentStat(stat_type type) const {
    switch (type) {
        case stat_type::Health:
            return health_current;
        case stat_type::Hungry:
            return hungry_current;
        default:
            return 0;
    }

    return 0;
}

int statistic::getMaxStat(stat_type type) const {
    switch (type) {
        case stat_type::Health:
            return health_max;
        case stat_type::Hungry:
            return hungry_max;
    }

    return 0;
}

void statistic::updateCurrentStat(stat_type type, int value) {
    switch (type) {
        case stat_type::Health:
            health_current = std::clamp(health_current + value, 0, health_max);
            break;
        case stat_type::Hungry:
            hungry_current = std::clamp(hungry_current + value, 0, hungry_max);
            break;
    }
}

void statistic::updateMaxStat(stat_type type, int value) {
    switch (type) {
        case stat_type::Health:
            health_max = std::clamp(health_max + value, 1, 100);
            health_current = std::min(health_current, health_max);
            break;
        case stat_type::Hungry:
            hungry_max = std::clamp(hungry_max + value, 1, 100);
            hungry_current = std::min(hungry_current, hungry_max);
            break;
    }
}
