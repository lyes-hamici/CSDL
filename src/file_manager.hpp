#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <string>

extern std::string SelectedFileName;
void loadFilesFromDirectory(const std::string &directoryPath);
void drawFileManager();

#endif