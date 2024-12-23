#include <iostream>
#include <vector>

#include "../src/game/game.h"


int main()
{
    try{
        std::vector<std::string> mapFiles = {"map1.txt", "map2.txt"};
        game game_(mapFiles);
        game_.showMainMenu();
        game_.runGame();
    }
    catch (const std::exception& e){
        std::cerr << "Error while running the game: " << e.what() << '\n';
    }
    return 0;
}