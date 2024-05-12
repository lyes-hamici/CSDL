#include "pattern_manager.hpp"
#include <fstream>
#include <iostream>

std::vector<std::vector<bool>> readPattern(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;
    std::vector<std::vector<bool>> pattern;

    // Read the pattern from the file
    while (std::getline(file, line))
    {
        std::vector<bool> row;
        for (char c : line)
        {
            row.push_back(c == '1');
        }
        pattern.push_back(row);
    }

    return pattern;
}

void writePattern(const std::string &filename, const std::vector<std::vector<bool>> &pattern)
{
    std::ofstream file(filename);

    // Write the pattern to the file
    for (const auto &row : pattern)
    {
        for (bool cell : row)
        {
            file << (cell ? '1' : '0');
        }
        file << '\n';
    }
}