#include <raylib.h>
#include "game_of_life.hpp"
#include <iostream>

const int screenWidth = (columns) * cell_size;
const int screenHeight = (rows) * cell_size + BottomMargin;

// Bouton gauche
Rectangle leftButtons[3] = {
    {10, screenHeight - 50, 80, 40},
    {100, screenHeight - 50, 80, 40},
    {190, screenHeight - 50, 80, 40}
};

// Bouton droit
Rectangle rightButtons[3] = {
    {screenWidth - 270, screenHeight - 50, 80, 40},
    {screenWidth - 180, screenHeight - 50, 80, 40},
    {screenWidth - 90, screenHeight - 50, 80, 40}
};

bool isPlay = false;
int frameCount = -1;

int main()
{
    InitWindow(screenWidth, screenHeight, "Game of Life - ORTHLY");
    SetTargetFPS(60);
    // initializeRandomGame();
    while (!WindowShouldClose())
    {
        if (isPlay || frameCount == 0)
        {
            updateGame();
            frameCount = -1;
        }

        // Vérifier l'interaction avec les boutons
        for (int i = 0; i < 3; ++i)
        {
            if (CheckCollisionPointRec(GetMousePosition(), leftButtons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if (i == 0) {
                    std::cout << "test" << std::endl;
                    // Action du bouton "play"
                } else if (i == 1) {
                    std::cout << "test1" << std::endl;
                    // Action du bouton "stop"
                } else if (i == 2) {
                    // Action du bouton "next"
                }
            }

            if (CheckCollisionPointRec(GetMousePosition(), rightButtons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if (i == 0) {
                    // Action du bouton "random"
                } else if (i == 1) {
                    // Action du bouton "clear"
                } else if (i == 2) {
                    // Action du bouton "pattern"
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawGame();

        // Dessiner les boutons
        for (int i = 0; i < 3; ++i)
        {
            DrawRectangleRec(leftButtons[i], LIGHTGRAY);
            DrawRectangleRec(rightButtons[i], LIGHTGRAY);
            DrawText((i == 0) ? "play" : (i == 1) ? "stop" : "next", leftButtons[i].x + 10, leftButtons[i].y + 10, 20, DARKGRAY);
            DrawText((i == 0) ? "random" : (i == 1) ? "clear" : "pattern", rightButtons[i].x + 10, rightButtons[i].y + 10, 20, DARKGRAY);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
