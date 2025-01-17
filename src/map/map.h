#pragma once

#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>
#include <memory>
#include <unordered_map>

#include "../include/cell_names.h"
#include "../Additional/pair_hash/pair_hash.h"
#include "../inventory/inventory.h"

class item;

// Class created as a holder for a map loaded from file.
class map {
private:
    std::vector<std::vector<char>> layout_; // 2D GRID of char which represent a map
    std::unordered_map<std::pair<int, int>, std::unique_ptr<item>, pair_hash> items_on_map_{};
public:
    explicit map(int width = GRID_SIZE, int height = GRID_SIZE); // Size of map (2D GRID) later initialized in the game class

    bool pickUpItem(int x, int y, inventory& player_inventory);

    [[nodiscard]] const std::vector<std::vector<char>>& getLayout() const; // return layout (passing map -> 2D GRID)
    void loadFromFile(std::string& filename); // Loading map template from .txt file
};
