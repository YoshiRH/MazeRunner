#pragma once

#include <cstdlib>
#include <fstream>
#include <vector>
#include <filesystem>
#include <iostream>
#include <unordered_map>

#include "../Additionals/pair_hash/pair_hash.h"
#include "../Items/health_potion/health_potion.h"
#include "../Items/food/food.h"
#include "../include/cell_names.h"

class item;
// Class created as a fileManager for map files.

class map_file_manager {
private:
    std::string filename_;

public:
    explicit map_file_manager(std::string filename);

    std::vector<std::vector<char>>
    loadFromFile(std::unordered_map<std::pair<int, int>, std::unique_ptr<item>, pair_hash> &items_on_map);
};
