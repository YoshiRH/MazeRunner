#pragma once

#include <string>

#include "../../w_item/item.h"
#include "../../player/player.h"

class food : public item {
    int hungry_amount_;

public:
    explicit food(int value);
    [[nodiscard]] std::string getName() const override;
    void use(player& player) override;
};