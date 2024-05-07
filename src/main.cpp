#include <raylib.h>
#include "game_of_life.hpp"



const int screenWidth = (columns) * cell_size;
const int screenHeight = (rows) * cell_size + BottomMargin;

int main()
{
    InitWindow(screenWidth, screenHeight, "Game of Life - ORTHLY");
    SetTargetFPS(60);
    initializeRandomGame();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        drawGame();
        // DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}