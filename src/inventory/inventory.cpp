#include "inventory.h"
#include "../Items/health_potion.h"

#include <iostream>

inventory::inventory() {
    addItem(std::make_unique<health_potion>(6),3);
}

void inventory::addItem(std::unique_ptr<item>item, int amount) {
    const std::string& item_name = item->getName();

    auto it = inventory_.find(item_name);

    if(it != inventory_.end()) {
        it->second.second += amount;
    } else {
        inventory_[item_name] = {std::move(item), amount};
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
    auto hp = inventory_.find("Health Potion");
    std::cout << "Potions: " << hp->second.second << '\n';
}


