cmake_minimum_required(VERSION 3.27)
project(Rogue_like_project VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(MAIN_FILE app/main.cpp)

file(GLOB_RECURSE SOURCES src/**/*.cpp)
file(GLOB_RECURSE HEADERS src/**/*.h)

add_executable(MazeRunner ${MAIN_FILE} ${SOURCES} ${HEADERS})
