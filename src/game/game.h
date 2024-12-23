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
    std::unique_ptr<grid> grid_; // Actual grid

    std::vector<std::string> maps_; // Vector of all maps in game
    std::shared_ptr<map> current_map_; // Map obiect of current map
    int current_map_index_;

    player player_; // player object

    bool running_; // Check if game is running

public:
    explicit game(const std::vector<std::string>& map_files);

    void loadFile(int index); // Load specific map by index
    int getInput(); // Get input from user

    void runGame(); // Loop function that is running whole game
    void nextLevel(); // Funtion to load next level

    void showPauseMenu(); // Pause menu
    void showMainMenu(); // Main menu
    void showGameOverMenu(); // Game over menu

    void movePlayer(DIRECTIONS dir); // Function to move player in specific direction
};
