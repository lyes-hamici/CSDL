#include <raylib.h>
#include "game_of_life.hpp"
#include <iostream>

bool isPlay = false;
int frameCount = -1;
int UpdatesPerSecond = 10;

const int screenWidth = (columns)*cell_size;
const int screenHeight = (rows)*cell_size + BottomMargin;

// Buttons on the left {play, stop and next frame}
Rectangle leftButtons[3] = {
    {10, screenHeight - 50, 90, 40},
    {110, screenHeight - 50, 90, 40},
    {210, screenHeight - 50, 90, 40}};

// Boutons on the right {random, pattern et clear }
Rectangle rightButtons[3] = {
    {screenWidth - 300, screenHeight - 50, 90, 40},
    {screenWidth - 200, screenHeight - 50, 90, 40},
    {screenWidth - 100, screenHeight - 50, 90, 40}};

// Rectangle centerButtons[2] = {
//     {screenWidth - 360,screenHeight - 50, 90, 40},
//     {screenWidth - 450, screenHeight - 50, 90, 40}};

int main()
{
    InitWindow(screenWidth, screenHeight, "Game of Life - ORTHLY");
    SetTargetFPS(UpdatesPerSecond);
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
                if (i == 0) // Play
                {
                    isPlay = true;
                }
                else if (i == 1) // Stop
                {
                    isPlay = false;
                }
                else if (i == 2) // Next
                {
                    frameCount = 0;
                }
            }

            if (CheckCollisionPointRec(GetMousePosition(), rightButtons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if (i == 0) // Random
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
        if (IsKeyPressed(KEY_RIGHT))
        {
            UpdatesPerSecond = std::min(UpdatesPerSecond + 10, 120);
            SetTargetFPS(UpdatesPerSecond);
        }

        if (IsKeyPressed(KEY_LEFT))
        {
            UpdatesPerSecond = std::max(UpdatesPerSecond - 10, 1);
            SetTargetFPS(UpdatesPerSecond);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawGame();

        // Draw GUI: The buttons
        for (int i = 0; i < 3; ++i)
        {
            DrawRectangleRec(leftButtons[i], LIGHTGRAY);
            DrawRectangleRec(rightButtons[i], LIGHTGRAY);
            DrawText((i == 0) ? "play" : (i == 1) ? "stop"
                                                  : "next",
                     leftButtons[i].x + 10, leftButtons[i].y + 10, 20, DARKGRAY);
            DrawText((i == 0) ? "random" : (i == 1) ? "pattern"
                                                    : "clear",
                     rightButtons[i].x + 10, rightButtons[i].y + 10, 20, DARKGRAY);
        }

        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
