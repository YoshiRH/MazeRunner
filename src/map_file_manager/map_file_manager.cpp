#include <utility>

#include "map_file_manager.h"

map_file_manager::map_file_manager(std::string filename)
        : filename_(std::move(filename)) {

}

std::vector<std::vector<char>> map_file_manager::loadFromFile(std::unordered_map<std::pair<int, int>, std::unique_ptr<item>, pair_hash>& items_on_map) {
        std::filesystem::path filePath = "../maps/" + filename_;
        std::ifstream file(filePath);

        if (!file.is_open()) {
            throw std::runtime_error("Couldn't open the map file: " + filePath.string());
        }

        std::string line;
        std::vector<std::vector<char>> temp_layout;  // Temporary grid which later is passed to main map class

        int y = 0; // Row in the file
        while (std::getline(file, line)) {
            if (!line.empty()) {
                std::vector<char> row(line.begin(), line.end());

                // Check if cell on map is an item, if yes then add it to the vector of items on map (and his x,y cords)
                for (int x = 0; x < line.size(); ++x) {
                    if (row[x] == HEALTH_POTION_CELL) {
                        items_on_map[{x, y}] = std::make_unique<health_potion>(6);
                    } else if (row[x] == FOOD_CELL) {
                        items_on_map[{x, y}] = std::make_unique<food>(12);
                    }
                }

                temp_layout.push_back(row);
            }
            y++;
        }

        if (temp_layout.empty()) {
            throw std::runtime_error("Map file is empty! " + filePath.string());
        }

        return temp_layout;  // return map layout
}
