#include "food.h"

food::food(int value)
: hungry_amount_{value}{

}

std::string food::getName() const {
    return "Food";
}

void food::use(player &player) {
    player.updateCurrentStat(stat_type::Hungry, hungry_amount_);
}
