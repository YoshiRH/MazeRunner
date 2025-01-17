#include "inventory.h"
#include "../Items/health_potion/health_potion.h"
#include "../Items/food/food.h"

#include <iostream>

inventory::inventory() {
    addItem(std::make_unique<food>(12),3);
    addItem(std::make_unique<health_potion>(6),2);
}

void inventory::addItem(std::unique_ptr<item>item, int amount) {
    const std::string& item_name = item->getName();

    auto it = inventory_.find(item_name);

    // Check if item is already in inventory, if yes then increase the amount
    // if not, then add it to the inventory
    if(it != inventory_.end()) {
        it->second.second += amount;
    } else {
        inventory_.emplace(item_name, std::make_pair(std::move(item), amount));
    }

}

void inventory::useItem(const std::string &item_name, player &player) {
    auto it = inventory_.find(item_name);

    if(it != inventory_.end()) {
        if(it->second.second > 0) {
            it->second.first->use(player);
            it->second.second--;
        }
    } else {
        std::cout << "Item " << item_name << " not found in the inventory.\n";
    }
}

void inventory::showInventory() const {
    std::cout << "Inventory:\n";

    for(const auto& [name, item_pair] : inventory_) {
        std::cout << name << ": " << item_pair.second << " | ";
    }

    std::cout << '\n';
}


