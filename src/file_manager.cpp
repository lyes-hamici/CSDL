#include <raylib.h>
#include <iostream>
#include <vector>
#include <filesystem>
#include "file_manager.hpp"

namespace fs = std::filesystem;

std::string selectedFileName = "";
std::vector<std::string> patternFiles, Userfiles;
size_t selectedFileIndex1 = 0, selectedFileIndex2 = 0;
bool isColumn1Selected = true;
void loadFilesFromDirectory(const std::string &directoryPath1, const std::string &directoryPath2)
{
    patternFiles.clear();
    Userfiles.clear();
    for (const auto &entry : fs::directory_iterator(directoryPath1))
    {
        if (entry.path().extension() == ".txt")
        {
            patternFiles.push_back(entry.path().filename().string());
        }
    }
    for (const auto &entry : fs::directory_iterator(directoryPath2))
    {
        if (entry.path().extension() == ".txt")
        {
            Userfiles.push_back(entry.path().filename().string());
        }
    }
}

void drawFileManager()
{
    ClearBackground(BLACK);
    // Draw files
    for (size_t i = 0; i < patternFiles.size(); i++)
    {
        if (isColumn1Selected && i == selectedFileIndex1)
        {
            DrawText(">", 10, 10 + 20 * i, 20, WHITE);
        }
        DrawText(patternFiles[i].c_str(), 30, 10 + 20 * i, 20, WHITE);
    }
    for (size_t i = 0; i < Userfiles.size(); i++)
    {
        if (!isColumn1Selected && i == selectedFileIndex2)
        {
            DrawText(">", 310, 10 + 20 * i, 20, WHITE);
        }
        DrawText(Userfiles[i].c_str(), 330, 10 + 20 * i, 20, WHITE);
    }

    // Handle input
    if (IsKeyPressed(KEY_UP))
    {
        if (isColumn1Selected && selectedFileIndex1 > 0)
            selectedFileIndex1--;
        else if (!isColumn1Selected && selectedFileIndex2 > 0)
            selectedFileIndex2--;
    }
    if (IsKeyPressed(KEY_DOWN))
    {
        if (isColumn1Selected && selectedFileIndex1 < patternFiles.size() - 1)
            selectedFileIndex1++;
        else if (!isColumn1Selected && selectedFileIndex2 < Userfiles.size() - 1)
            selectedFileIndex2++;
    }
    if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_RIGHT)) && !Userfiles.empty())
    {
        isColumn1Selected = !isColumn1Selected;
    }
    if (IsKeyPressed(KEY_ENTER))
    {
        selectedFileName = isColumn1Selected ? "./patterns/" + patternFiles[selectedFileIndex1] : "./patterns/user/" + Userfiles[selectedFileIndex2];
    }
}