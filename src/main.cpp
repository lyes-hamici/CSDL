#include "game_of_life.hpp"
#include "file_manager.hpp"
#include <iostream>

enum GameScene
{
    SCENE_GAMEPLAY,
    SCENE_FILE
};

GameScene currentScene = SCENE_GAMEPLAY;

bool isPlay = false;
int frameCount = -1;
int UpdatesPerSecond = 60;

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



int main()
{
    InitWindow(screenWidth, screenHeight, "Game of Life - ORTHLY");
    SetTargetFPS(UpdatesPerSecond);
     while (!WindowShouldClose())
    {
        switch (currentScene)
        {
        case SCENE_FILE:
            drawFileManager();
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                UpdatesPerSecond = 60;
                currentScene = SCENE_GAMEPLAY;
            }
            if (selectedFileName != "")
            {
                UpdatesPerSecond = 60;
                currentScene = SCENE_GAMEPLAY;
                initializePatternGame(selectedFileName);
                selectedFileName = "";
            }
            break;
        case SCENE_GAMEPLAY:

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
                        loadFilesFromDirectory("./patterns", "./patterns/user");
                        UpdatesPerSecond = 120;
                        currentScene = SCENE_FILE;
                    }
                    else if (i == 2) // Clear grid
                    {
                        resetGrid();
                    }
                }
            }

            if (IsKeyPressed(KEY_RIGHT))
            {
                UpdatesPerSecond = std::min(UpdatesPerSecond + 5, 120);
                SetTargetFPS(UpdatesPerSecond);
            }
            else if (IsKeyPressed(KEY_LEFT))
            {
                UpdatesPerSecond = std::max(UpdatesPerSecond - 5, 1);
                SetTargetFPS(UpdatesPerSecond);
            }
            else if (IsKeyPressed(KEY_S))
            {
                savePattern();
            }
            else if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                drawOnGrid(GetMousePosition(), true);
            }
            else if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
            {
                drawOnGrid(GetMousePosition(), false);
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
            break;
        }
       

        // DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
