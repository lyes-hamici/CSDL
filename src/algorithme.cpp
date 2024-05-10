
#include <vector>
#include <iostream>
#include <string>


void check_neihbourg(int x, int y, int rows, int columns, std::vector<std::vector<int>>& grid) {
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
            grid[x][y] = 0;
        }
    } else {
        if (count == 3) {
            grid[x][y] = 1;
        }
    }
}

void updateGame(int rows, int columns, std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(columns, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            check_neihbourg(i, j, rows, columns, grid);
        }
    }
}

int main() {
    std::vector<std::string> v = {"Hello", "World"};
    for (const auto& s : v) {
        std::cout << s << std::endl;
    }
    return 0;
}
