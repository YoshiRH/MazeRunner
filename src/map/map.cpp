#include "map.h"
#include "../map_file_manager/map_file_manager.h"


// Constructor filling whole map with '.' which represent empty space in game
map::map(int width, int height)
        : layout_(height, std::vector<char>(width, '.')) {

}

const std::vector<std::vector<char>>& map::getLayout() const {
    return layout_;
}

void map::loadFromFile(std::string &filename) {
    try {
    map_file_manager fileManager(filename); // File handling class
    layout_ = fileManager.loadFromFile(items_on_map_); // Taking loaded map (2D GRID) from file to the map.layout_
    } catch (const std::exception &e) {
        std::cerr << "Error: Failed to load map from file \"" << filename << "\": " << e.what() << '\n';
        throw;
    }

}

// Check if there is an item in the player position and if it's true then add it to the inventory
bool map::pickUpItem(int x, int y, inventory &player_inventory) {
    auto it = items_on_map_.find({x,y});

    if(it != items_on_map_.end()) {
        player_inventory.addItem(std::move(it->second), 1);
        items_on_map_.erase(it);
        return true;
    }
    return false;
}
