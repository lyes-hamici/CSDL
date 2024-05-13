#ifndef PATTERN_MANAGER_HPP
#define PATTERN_MANAGER_HPP

#include <vector>
#include <string>

std::vector<std::vector<bool>> readPattern(const std::string &filename);
void writePattern(const bool grid[80][80]);
std::string randomFileName();
bool fileExists(const std::string &filename);

#endif