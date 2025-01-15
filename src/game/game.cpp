#include "game.h"

game::game(const std::vector<std::string> &map_files)
        : maps_{map_files}, current_map_index_{0}, running_{true}, player_{0, 0} {

}

// Load map
void game::loadFile(int index) {
    if (index < 0 || index >= maps_.size())
        throw std::runtime_error("Index of the map is invalid");

    current_map_ = std::make_unique<map>(GRID_SIZE, GRID_SIZE);
    try{
        current_map_->loadFromFile(maps_[current_map_index_]);
    } catch (std::exception& e) {
        std::cerr << "Error, unable to load map from \"game.cpp\": " << e.what() << '\n';
        running_ = false;
    }


    grid_ = std::make_unique<grid>(current_map_);
}

GET_FROM_INPUT game::getInput() {
    int key = _getch();

    switch (key) {
            case 72:
                return GET_FROM_INPUT::UP;
            case 80:
                return GET_FROM_INPUT::DOWN;
            case 75:
                return GET_FROM_INPUT::LEFT;
            case 77:
                return GET_FROM_INPUT::RIGHT;
            case 'x':
                return GET_FROM_INPUT::PAUSE_MENU;
            case '1':
                return GET_FROM_INPUT::USE_POTION;
            case '2':
                return GET_FROM_INPUT::EAT_FOOD;
            default:
                return GET_FROM_INPUT::WRONG_INPUT;
    }
}

void game::runGame() {
    while (running_) {
        displayFrame();
        auto input = getInput();
        handleInput(input);
        managePlayerPosition(input);
    }

}

void game::nextLevel() {
    ++current_map_index_;
    if (current_map_index_ >= maps_.size()) {
        using namespace std::chrono_literals;
        std::cout << "=== Congratulations! that's the end of the game ===\n";

        std::this_thread::sleep_for(2s);
        running_ = false;
    }

    loadFile(current_map_index_);

    player_.move(GET_FROM_INPUT::START_POSITION);
    grid_->setCell(player_.getX(), player_.getY(), PLAYER_CELL);
}

void game::showPauseMenu() {
    while (true) {
        clearScreen();

        std::cout << "=== PAUSE MENU ===\n";
        std::cout << "1. Resume game\n";
        std::cout << "2. Controls\n";
        std::cout << "3. Restart game\n";
        std::cout << "4. Back to title\n";
        std::cout << "0. Exit game\n\n";
        std::cout << "Chose option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                return;
            case 2:
                showControls();
                break;
            case 3:
                newGame();
                return;
            case 4:
                showMainMenu();
                return;
            case 0:
                running_ = false;
            default:
                std::cout << "Incorrect input, try again\n";
        }
    }
}

void game::showMainMenu() {
    while (true) {
        clearScreen();

        std::cout << "=== MAIN MENU ===\n";
        std::cout << "1. New game\n";
        std::cout << "2. Controls\n";
        std::cout << "3. Exit game\n\n";
        std::cout << "Chose option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                newGame();
                return;
            case 2:
                showControls();
                break;
            case 3:
                running_ = false;
            default:
                std::cout << "Incorrect input, try again\n";
        }
    }
}

void game::showGameOverMenu() {
    while (true) {
        clearScreen();

        std::cout << "=== GAME OVER, YOU DIED ===\n";
        std::cout << "1. New game\n";
        std::cout << "2. Exit game\n";
        std::cout << "Chose option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                newGame();
                return;
            case 2:
                running_ = false;
            default:
                std::cout << "Incorrect input, try again\n";
        }
    }
}

void game::showControls() {
    while (true) {
        clearScreen();

        std::cout << "=== CONTROLS ===\n";
        std::cout << "[ARROWS] -  Use arrows to move around\n";
        std::cout << "[X] - Open up pause menu\n\n";
        std::cout << "[1] - Use Health potion\n";
        std::cout << "[2] - Eat Food\n\n";
        std::cout << "0. Exit\n";

        std::cout << "Enter: ";

        int choice;
        std::cin >> choice;

        if(choice == 0) {
            break;
        }
    }
}

void game::movePlayer(GET_FROM_INPUT dir) {
    // Map that give us a value in which direction player would move depending on the key
    static const std::map<GET_FROM_INPUT, std::pair<int, int>> direction_map = {
            {GET_FROM_INPUT::UP, {0, -1}},
            {GET_FROM_INPUT::DOWN, {0, 1}},
            {GET_FROM_INPUT::LEFT, {-1, 0}},
            {GET_FROM_INPUT::RIGHT, {1, 0}}
    };

    auto it = direction_map.find(dir);
    if (it != direction_map.end()) {
        int new_x = player_.getX() + it->second.first;
        int new_y = player_.getY() + it->second.second;

        // Check if the next cell where player want's to move is clear
        if (new_x >= 0 && new_x < GRID_SIZE &&
            new_y >= 0 && new_y < GRID_SIZE &&
            grid_->getCell(new_x, new_y) != OBSTACLE_CELL) {
            player_.move(dir);
        }
    }
}

void game::showGameInfo() const {
    std::cout << "[Current floor: " << current_map_index_+1 << "/" << maps_.size() << "]\n\n";
}



void game::displayFrame() {
    clearScreen();

    player_.displayStats();
    grid_->displayMap(player_.getX(), player_.getY());
    player_.displayInventory();
    showGameInfo();
}

void game::handleInput(GET_FROM_INPUT input) {
    switch (input) {
        case GET_FROM_INPUT::PAUSE_MENU:
            showPauseMenu();
            break;
        case GET_FROM_INPUT::USE_POTION:
            player_.useItem("Health Potion");
            break;
        case GET_FROM_INPUT::EAT_FOOD:
            player_.useItem("Food");
            break;
        default:
            return;
    };
}

void game::newGame() {
    current_map_index_ = 0;
    loadFile(current_map_index_);
    player_ = player(0, 0);
    grid_->setCell(player_.getX(), player_.getY(), PLAYER_CELL);
}

void game::managePlayerPosition(GET_FROM_INPUT input) {
    grid_->clearCell(player_.getX(), player_.getY());
    movePlayer(input);

    if (player_.isDead()) {
        showGameOverMenu();
        return;
    }

    auto cell = grid_->getCell(player_.getX(), player_.getY());

    switch (cell) {
        case NEXT_LEVEL_CELL:
            nextLevel();
            break;
        case HEALTH_POTION_CELL:
        case FOOD_CELL:
            current_map_->pickUpItem(player_.getX(), player_.getY(), player_.inventory_);
            break;
        default:
            break;
    }

    grid_->setCell(player_.getX(), player_.getY(), PLAYER_CELL);
}

void game::clearScreen() {
    std::cout.flush();
    std::cout << "\033[2J\033[H";
}




