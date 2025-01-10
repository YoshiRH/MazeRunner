#pragma once

#include <unordered_map>
#include <string>
#include <memory>

#include "../w_item/item.h"

class player;

class inventory {
    std::unordered_map<std::string, std::pair<std::unique_ptr<item>, int>> inventory_;

public:
    inventory();

    void addItem(std::unique_ptr<item> item, int amount);
    void useItem(const std::string& item_name, player& player);
    void showInventory() const;

};