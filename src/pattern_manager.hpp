#ifndef PATTERN_MANAGER_HPP
#define PATTERN_MANAGER_HPP

#include <vector>
#include <string>

std::vector<std::vector<bool>> readPattern(const std::string &filename);
void writePattern(const std::vector<std::vector<bool>> &pattern);

#endif