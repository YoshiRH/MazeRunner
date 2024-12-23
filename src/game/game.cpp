#include "game.h"

game::game(const std::vector<std::string> &map_files)
        : maps_{map_files}, current_map_index_{0}, running_{true}, player_{0, 0} {

}

// Load map
void game::loadFile(int index) {
    if (index < 0 || index > maps_.size())
        throw std::runtime_error("Index of the map is invalid");

    current_map_ = std::make_shared<map>(GRID_SIZE, GRID_SIZE);
    current_map_->loadFromFile(maps_[current_map_index_]);

    grid_ = std::make_unique<grid>(current_map_);
}

int game::getInput() {
    int key = _getch();

    if (key == 224) {
        key = _getch();

        switch (key) {
            case 72:
                return 1;
            case 80:
                return 2;
            case 75:
                return 3;
            case 77:
                return 4;
            default:
                break;
        }
    } else if (key == 'x' || key == 'X')
        return 5;

    return 0;
}

void game::runGame() {
    while (running_) {
        grid_->displayMap(player_.getX(), player_.getY());
        player_.displayStats();
        int input = getInput();

        if (input == 5) {
            showPauseMenu();
            continue;
        }

        grid_->clearCell(player_.getX(), player_.getY());
        movePlayer(static_cast<DIRECTIONS>(input));

        if(player_.isDead()) {
            showGameOverMenu();
            continue;
        }

        if (grid_->getCell(player_.getX(), player_.getY()) == NEXT_LEVEL_CELL) {
            nextLevel();
            continue;
        }

        grid_->setCell(player_.getX(), player_.getY(), PLAYER_CELL);
    }

}

void game::nextLevel() {
    ++current_map_index_;
    if (current_map_index_ > maps_.size()) {
        std::cout << "Congratulations! that's the end of the game.\n";
        exit(0);
    }

    loadFile(current_map_index_);

    player_ = player();
    grid_->setCell(player_.getX(), player_.getY(), PLAYER_CELL);
}

void game::showPauseMenu() {
    while (true) {
        std::cout.flush();
        system("cls");
        std::cout << "=== PAUSE MENU ===\n";
        std::cout << "1. Resume game\n";
        std::cout << "2. Restart level\n";
        std::cout << "3. Back to title\n";
        std::cout << "4. Exit game\n";
        std::cout << "Chose option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                return;
            case 2:
                loadFile(current_map_index_);
                player_ = player();
                grid_->setCell(player_.getX(), player_.getY(), PLAYER_CELL);
                return;
            case 3:
                showMainMenu();
                return;
            case 4:
                exit(0);
            default:
                std::cout << "Incorrect input, try again\n";
        }
    }
}

void game::showMainMenu() {
    while (true) {
        std::cout.flush();
        system("cls");
        std::cout << "=== MAIN MENU ===\n";
        std::cout << "1. New game\n";
        std::cout << "2. Exit game\n";
        std::cout << "Chose option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                loadFile(current_map_index_);
                player_ = player(0, 0);
                grid_->setCell(player_.getX(), player_.getY(), PLAYER_CELL);
                return;
            case 2:
                exit(0);
            default:
                std::cout << "Incorrect input, try again\n";
        }
    }
}

void game::showGameOverMenu() {
    while(true) {
        std::cout.flush();
        system("cls");
        std::cout << "=== GAME OVER, YOU DIED ===\n";
        std::cout << "1. New game\n";
        std::cout << "2. Exit game\n";
        std::cout << "Chose option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                current_map_index_ = 0;
                loadFile(current_map_index_);
                player_ = player(0, 0);
                grid_->setCell(player_.getX(), player_.getY(), PLAYER_CELL);
                return;
            case 2:
                exit(0);
            default:
                std::cout << "Incorrect input, try again\n";
        }
    }
}

void game::movePlayer(DIRECTIONS dir) {
    switch (dir) {
        case 1:
            if (player_.getY() > 0 && grid_->getCell(player_.getX(), player_.getY() - 1) != OBSTACLE_CELL)
                player_.move(dir);
            break;
        case 2:
            if (player_.getY() < GRID_SIZE - 1 && grid_->getCell(player_.getX(), player_.getY() + 1) != OBSTACLE_CELL)
                player_.move(dir);
            break;
        case 3:
            if (player_.getX() > 0 && grid_->getCell(player_.getX() - 1, player_.getY()) != OBSTACLE_CELL)
                player_.move(dir);
            break;
        case 4:
            if (player_.getX() < GRID_SIZE - 1 && grid_->getCell(player_.getX() + 1, player_.getY()) != OBSTACLE_CELL)
                player_.move(dir);
            break;
        default:
            std::cerr << "Invalid direction\n";
    }
}




