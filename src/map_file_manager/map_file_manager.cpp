#include <utility>

#include "map_file_manager.h"

map_file_manager::map_file_manager(std::string& filename)
        : filename_(filename) {

}

// Function that take every line from a .txt file to the vector of vector<char> which represent 2D GRID (map)
// Every char in the txt file is a single cell in our 2D GRID (map)
std::vector<std::vector<char>> map_file_manager::loadFromFile() {
    std::filesystem::path filePath = "../maps/" + filename_;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open the map file: " + filePath.string());
    }

    std::string line;
    std::vector<std::vector<char>> temp_layout; // temp grid, which is later passed to the map handling object.

    while (std::getline(file, line)) {
        if(!line.empty()) {
            temp_layout.emplace_back(line.begin(), line.end());
        }
    }

    if(temp_layout.empty()) {
        throw std::runtime_error("Map file is empty! " + filePath.string());
    }

    return temp_layout; // returning 2D GRID (map)
}
