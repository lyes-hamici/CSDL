#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

const int rows = 150;
const int columns = 150;
const int cell_size = 5;

void initializeGame();
void updateGame();
void drawGame();

#endif