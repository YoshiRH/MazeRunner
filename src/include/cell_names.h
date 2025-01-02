#pragma once

constexpr int GRID_SIZE = 21; // Default size of out map

// Meanings of cells on map
constexpr char EMPTY_CELL = '.';
constexpr char PLAYER_CELL = 'x';
constexpr char OBSTACLE_CELL = '#';
constexpr char NEXT_LEVEL_CELL = '>';
constexpr char HIDDEN_CELL = ' ';

// Enum with directions that is used for moving player on map
// UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4
enum DIRECTIONS {
    UP = 1,
    DOWN,
    LEFT,
    RIGHT,
    START_POSITION
};