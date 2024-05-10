#include <raylib.h>
#include "game_of_life.hpp"
#include "pattern_manager.hpp"
#include <cstdlib>

// Game Variables
bool grid[rows][columns] = {false};
Color darkGreen = Color{20, 160, 133, 255};
Color gridColor = {128, 128, 128, 128};

void resetGrid()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            grid[i][j] = 0;
        }
    }
}

/**
 * @brief Initializes the game.
 *
 * This function initializes the game by setting up the initial state of the grid with random values.
 */
void initializeRandomGame()
{
    resetGrid();

    for (int i{0}; i < rows; i++)
    {
        for (int j{0}; j < columns; j++)
        {
            // Obtient un nombre aléatoire entre 0 et 99
            int randomValue = rand() % 100;
            // Si le nombre est inférieur à 30, on attribue 1, sinon 0
            if (randomValue <= 10)
                grid[i][j] = 1;
        }
    }
}

/**
 * @brief Initializes the game.
 *
 * This function initializes the game by setting up the initial state of the grid with a pattern stored into a txt file.
 */
void initializePatternGame(const std::string &filepath)
{

    // Reseting the grid
    resetGrid();

    std::vector<std::vector<bool>> pattern = readPattern(filepath); // Return a 2D vector

    int centerRow = rows / 2;
    int centerColumn = columns / 2;
    int startRow = centerRow - pattern.size() / 2;
    int startColumn = centerColumn - pattern[0].size() / 2;

    for (std::vector<bool>::size_type i = 0; i < pattern.size(); i++)
    {
        for (std::vector<bool>::size_type j = 0; j < pattern[i].size(); j++)
        {
            grid[startRow + i][startColumn + j] = pattern[i][j];
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
    initializeRandomGame(); // Erase this, this is completly for test purposes
}

/**
 * @brief Draws the game state
 *
 * This function draws the current state of the game to the screen.
 */
void drawGame()
{
    ClearBackground(darkGreen);
    drawCell();
    drawGrid();
}

void drawGrid()
{
    for (int i{0}; i <= rows; i++)
    {
        DrawLine(0, i * cell_size, columns * cell_size, i * cell_size, gridColor);
    }

    for (int j{0}; j <= columns; j++)
    {
        DrawLine(j * cell_size, 0, j * cell_size, rows * cell_size, gridColor);
    }
}
void drawCell()
{
    for (int i{0}; i < rows; i++)
    {
        for (int j{0}; j < columns; j++)
        {
            if (grid[i][j])
            {
                DrawRectangle(j * cell_size, i * cell_size, cell_size, cell_size, GREEN);
            }
            else
            {
                DrawRectangle(j * cell_size, i * cell_size, cell_size, cell_size, BLACK);
            }
        }
    }
}