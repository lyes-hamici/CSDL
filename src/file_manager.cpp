#include <raylib.h>
#include <iostream>
#include <vector>
#include <filesystem>
#include "file_manager.hpp"

namespace fs = std::filesystem;

std::string SelectedFileName = "";
std::vector<std::string> files;
size_t selectedFileIndex = 0;

void loadFilesFromDirectory(const std::string &directoryPath)
{
    files.clear();
    for (const auto &entry : fs::directory_iterator(directoryPath))
    {
        if (entry.path().extension() == ".txt")
        {
            files.push_back(entry.path().filename().string());
        }
    }
}

void drawFileManager()
{
    ClearBackground(RED);
    // Draw files
    for (size_t i = 0; i < files.size(); i++) // Change type to size_t
    {
        if (i == selectedFileIndex)
        {
            DrawText(">", 10, 10 + 20 * i, 20, BLACK);
        }
        DrawText(files[i].c_str(), 30, 10 + 20 * i, 20, BLACK);
    }

    // Handle input
    if (IsKeyPressed(KEY_UP))
    {
        if (selectedFileIndex > 0) // Check if selectedFileIndex is greater than 0 before decrementing
            selectedFileIndex--;
    }
    if (IsKeyPressed(KEY_DOWN))
    {
        if (selectedFileIndex < files.size() - 1) // Check if selectedFileIndex is less than files.size() - 1 before incrementing
            selectedFileIndex++;
    }
    if (IsKeyPressed(KEY_ENTER))
    {
        SelectedFileName = files[selectedFileIndex];
        // Change scene here
    }
}