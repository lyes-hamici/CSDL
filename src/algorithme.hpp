#ifndef ALGORITHME_H
#define ALGORITHME_H

#include <vector>

void updateMatrice(int rows, int columns, bool grid[80][80], bool new_grid[80][80]);
void check_neihbourg(int x, int y, int rows, int columns, bool grid[80][80], bool new_grid[80][80]);

#endif