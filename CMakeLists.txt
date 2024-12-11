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
)
