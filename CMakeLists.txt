cmake_minimum_required(VERSION 3.27)
project(Rogue_like_project VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rogue_like_project app/main.cpp
        src/include/cell_names.h
        src/grid/grid.h
        src/grid/grid.cpp
        src/map/map.h
        src/map/map.cpp
        src/map_file_manager/map_file_manager.h
        src/map_file_manager/map_file_manager.cpp
        src/player/player.h
        src/player/player.cpp
        src/game/game.h
        src/game/game.cpp
        src/statistic/statistic.h
        src/statistic/statistic.cpp
        src/stat_type/stat_type.h
        src/w_item/item.h
        src/Items/health_potion/health_potion.h
        src/Items/health_potion/health_potion.cpp
        src/inventory/inventory.h
        src/inventory/inventory.cpp
        src/Items/food/food.h
        src/Items/food/food.cpp
        src/Additionals/pair_hash/pair_hash.h
)
