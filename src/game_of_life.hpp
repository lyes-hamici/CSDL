#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H
#include <string>
#include <raylib.h>

const int rows = 80;
const int columns = 80;
const int cell_size = 10;
const int BottomMargin = 60;

void resetGrid();
void initializeRandomGame();
void initializePatternGame(const std::string &filePath);
void updateGame();
void reverseUpdate();
void drawOnGrid(Vector2 mousePosition, bool draw);
void drawGame();
void drawGrid();
void drawCell();
void savePattern();

#endif