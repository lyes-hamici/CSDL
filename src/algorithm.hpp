#ifndef ALGORITHME_H
#define ALGORITHME_H

void updateMatrice(bool grid[80][80], bool new_grid[80][80]);
void check_neihbourg(int x, int y, bool grid[80][80], bool new_grid[80][80]);
void copyGrid(bool grid[80][80], bool new_grid[80][80]);

#endif