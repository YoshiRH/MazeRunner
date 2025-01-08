#pragma once

#include <cstdlib>
#include <fstream>
#include <vector>
#include <filesystem>
#include <iostream>

// Class created as a fileManager for map files.

class map_file_manager {
private:
    std::string filename_;

public:
    explicit map_file_manager(std::string& filename);

    std::vector<std::vector<char>> loadFromFile();
};
