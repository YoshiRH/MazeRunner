#include "health_potion.h"

#include <iostream>

health_potion::health_potion(int value)
:heal_value_{value}{

}

std::string health_potion::getName() const {
    return "Health Potion";
}

void health_potion::use(player &player) {
    player.updateCurrentStat(stat_type::Health, heal_value_);
}
