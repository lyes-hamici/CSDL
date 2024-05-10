#include <raylib.h>
#include "game_of_life.hpp"
#include <iostream>

const int screenWidth = (columns)*cell_size;
const int screenHeight = (rows)*cell_size + BottomMargin;

// Buttons on the left {play, stop and next frame}
Rectangle leftButtons[3] = {
    {10, screenHeight - 50, 80, 40},
    {100, screenHeight - 50, 80, 40},
    {190, screenHeight - 50, 80, 40}};

// Boutons on the right {random, pattern et clear }
Rectangle rightButtons[3] = {
    {screenWidth - 270, screenHeight - 50, 80, 40},
    {screenWidth - 180, screenHeight - 50, 80, 40},
    {screenWidth - 90, screenHeight - 50, 80, 40}};

bool isPlay = false;
int frameCount = -1;

int main()
{
    InitWindow(screenWidth, screenHeight, "Game of Life - ORTHLY");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        if (isPlay || frameCount == 0)
        {
            updateGame();
            frameCount = -1;
        }

        // It verifies if the user click on a button
        for (int i = 0; i < 3; ++i)
        {
            if (CheckCollisionPointRec(GetMousePosition(), leftButtons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if (i == 0) //Play
                {
                    isPlay = true;
                }
                else if (i == 1) //Stop
                {
                    isPlay = false;
                }
                else if (i == 2) //Next
                {
                    frameCount = 0;
                }
            }

            if (CheckCollisionPointRec(GetMousePosition(), rightButtons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if (i == 0) //Random
                {
                    initializeRandomGame();
                }
                else if (i == 1) // Pattern load
                {
                }
                else if (i == 2) // Clear grid
                {
                    resetGrid();
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawGame();

        // Draw GUI: The buttons
        for (int i = 0; i < 3; ++i)
        {
            DrawRectangleRec(leftButtons[i], LIGHTGRAY);
            DrawRectangleRec(rightButtons[i], LIGHTGRAY);
            DrawText((i == 0) ? "play" : (i == 1) ? "stop" : "next", leftButtons[i].x + 10, leftButtons[i].y + 10, 20, DARKGRAY);
            DrawText((i == 0) ? "random" : (i == 1) ? "pattern" : "clear", rightButtons[i].x + 10, rightButtons[i].y + 10, 20, DARKGRAY);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
