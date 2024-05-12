#include "algorithme.hpp"
#include "game_of_life.hpp"

#include <iostream>
#include <string>

void check_neihbourg(int x, int y, bool grid[rows][columns], bool new_grid[rows][columns])
{
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

void updateMatrice(bool grid[rows][columns], bool new_grid[rows][columns])
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            check_neihbourg(i, j, grid, new_grid);
        }
    }
    // Putting new_grid into grid()
   copyGrid(grid, new_grid);
}

void copyGrid(bool grid[rows][columns], bool new_grid[rows][columns])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            grid[i][j] = new_grid[i][j];
        }
    }
}
