#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

const int rows = 80;
const int columns = 80;
const int cell_size = 10;

void initializeGame();
void updateGame();
void drawGame();

#endif