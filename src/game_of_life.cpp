#include <raylib.h>
#include "game_of_life.hpp"

// Game Variables
bool grid[rows][columns] = {false};

/**
 * @brief Initializes the game.
 *
 * This function initializes the game by setting up the initial state of the grid with random values.
 */
void initializeGame()
{
    for (int i{0}; i < rows; i++)
    {
        for (int j{0}; j < columns; j++)
        {
            grid[i][j] = GetRandomValue(0, 1);
        }
    }
}

/**
 * @brief Updates the game state
 *
 * This function updates the grid state based on the rules of the Game of Life.
 */
void updateGame()
{
    // Update your game state here based on the rules of the Game of Life
}

/**
 * @brief Draws the game state
 *
 * This function draws the current state of the game to the screen.
 */
void drawGame()
{
    for (int i{0}; i < rows; i++)
    {
        for (int j{0}; j < columns; j++)
        {
            if (grid[i][j])
            {
                DrawRectangle(i * cell_size, j * cell_size, cell_size, cell_size, WHITE);
            }
            else 
            {
                DrawRectangle(i * cell_size, j * cell_size, cell_size, cell_size, BLACK);
            }
        }
    }
}