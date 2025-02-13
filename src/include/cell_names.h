#pragma once

constexpr int GRID_SIZE = 21; // Default size of out map

// Meanings of cells on map
constexpr char EMPTY_CELL = '.';
constexpr char PLAYER_CELL = 'x';
constexpr char OBSTACLE_CELL = '#';
constexpr char NEXT_LEVEL_CELL = '>';
constexpr char HIDDEN_CELL = ' ';
constexpr char HEALTH_POTION_CELL = 'H';
constexpr char FOOD_CELL = 'F';

// Enum with directions that is used for moving player on map
// UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4
enum GET_FROM_INPUT {
    UP = 1,
    DOWN,
    LEFT,
    RIGHT,
    START_POSITION,
    PAUSE_MENU,
    WRONG_INPUT,
    USE_POTION,
    EAT_FOOD
};