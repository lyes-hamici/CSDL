#include <raylib.h>
#include "game_of_life.hpp"

Color darkGreen = Color{20, 160, 133, 255};

const int screenWidth = (columns) * cell_size;
const int screenHeight = (rows) * cell_size;

int main()
{
    InitWindow(screenWidth, screenHeight, "Game of Life - ORTHLY");
    SetTargetFPS(60);
    initializeGame();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGreen);
        drawGame();
        // DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}