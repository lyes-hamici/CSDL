#include "algorithme.hpp"
#include "game_of_life.hpp"

#include <vector>
#include <iostream>
#include <string>

void check_neihbourg(int x, int y, int rows, int columns, bool grid[80][80], bool new_grid[80][80]) {
    int count = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            int new_x = x + i;
            int new_y = y + j;
            if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < columns) {
                count += grid[new_x][new_y];
            }
        }
    }
    count -= grid[x][y];
    if (grid[x][y] == 1) {
        if (count < 2 || count > 3) {
            new_grid[x][y] = 0;
        }
        else {
            new_grid[x][y] = 1;
        }
    }
    else {
        if (count == 3) {
            new_grid[x][y] = 1;
        }
    }
}

void updateMatrice(int rows, int columns, bool grid[80][80], bool new_grid[80][80]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            check_neihbourg(i, j, rows, columns, grid, new_grid);
        }
    }
    std::cout << "old grid: " << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    grid = new_grid;
    std::cout << "new grid: " << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
