# MazeRunner

MazeRunner is a console-based game, where player has to find an exit before his hunger and health went to zero, which means game over.

## Description

MazeRunner is a console game inspired by old escape type games. The player navigates through the maps which are created by .txt files by following rules:  
[.] - Empty cell on which player can move  
[#] - Obstacle cell, represent a wall  
[>] - Gate, navigate to the next level  
[H] - Represent Health Potion, which player can pick up and use whenever he want's to  
[F] - Same as "H" but this one represent Food in game

## Controls 

[Arrows] - Use arrows to move around  
[X] - Show pause menu  
[1] - Use Health Potion  
[2] - Eat Food

## Features

- Maps & items on map created easily with a .txt file
- Basic inventory and item system 
- Player health and hunger system

## Project structure

- app/ – contains the main.cpp file that launches the game
- src/ – contains the game source files
- maps/ – contains the map files used in the game
- CMakeLists.txt – the CMake configuration file

## System Requirements

- A compiler supporting C++17
- CMake version 3.27 or later

## Installation

1. Clone the repository: git clone https://github.com/YoshiRH/MazeRunner.git
2. Navigate to the project directory: cd MazeRunner
3. Create a build directory and move into it: 
   - mkdir build  
   - cd build
4. Generate Makefiles using CMake: cmake ..
5. Compile the project: make
6. Run the game: ./MazeRunner
