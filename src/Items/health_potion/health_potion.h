#pragma once

#include "../../w_item/item.h"
#include "../../player/player.h"

class health_potion : public item {
    int heal_value_;

public:
    explicit health_potion(int value);
    [[nodiscard]] std::string getName() const override;
    void use(player& player) override;
};