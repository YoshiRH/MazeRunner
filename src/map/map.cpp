#include "map.h"
#include "../map_file_manager/map_file_manager.h"


// Constructor filling whole map with '.' which represent empty space in game
map::map(int width, int height)
        : layout_(height, std::vector<char>(width, '.')) {

}

void map::setCell(int x, int y, char value) {
    if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) { // Check if x,y is in the grid
        layout_[y][x] = value;
    } else
        throw std::out_of_range("Cell is out of the grid");
}

char map::getCell(int x, int y) const {
    if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) { // Check if x,y is in the grid
        return layout_[y][x];
    } else
        throw std::out_of_range("Cell is out of the grid!");
}

const std::vector<std::vector<char>>& map::getLayout() const {
    return layout_;
}

void map::loadFromFile(const std::string &filename) {
    try {
    map_file_manager fileManager(filename); // File handling class
    layout_ = fileManager.loadFromFile(); // Taking loaded map (2D GRID) from file to the map.layout_
    } catch (const std::exception &e) {
        std::cerr << "Error: Failed to load map from file \"" << filename << "\": " << e.what() << '\n';
        throw;
    }


}
