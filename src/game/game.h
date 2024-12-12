#pragma once

// Libs
#include <memory>
#include <iostream>
#include <vector>
#include <conio.h>

// Files
#include "../map/map.h"
#include "../grid/grid.h"
#include "../player/player.h"
#include "../include/cell_names.h"

class game {
private:
    std::unique_ptr<grid> grid_;

    std::vector<std::string> maps_;
    std::shared_ptr<map> current_map_;
    int current_map_index_;

    player player_;

    bool running_;

public:
    explicit game(const std::vector<std::string>& map_files);

    void loadFile(int index);
    int getInput();

    void runGame();
    void nextLevel();
    void showPauseMenu();
    void showMainMenu();

    void movePlayer(DIRECTIONS dir);
};
