#include "pattern_manager.hpp"
#include <fstream>
#include <iostream>
#include <random>

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

void writePattern(const bool grid[80][80])
{
    std::string filename = randomFileName();

    while (fileExists(filename))
    {
        filename = randomFileName();
    }

    std::ofstream file(filename);

    for (int i = 0; i < 80; i++)
    {
        for (int j = 0; j < 80; j++)
        {
            file << (grid[i][j] ? '1' : '0');
        }
        file << '\n';
    }
}

std::string randomFileName()
{
    std::string filename = "./patterns/user/file";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(1000, 9999);
    filename += std::to_string(distribution(generator));
    filename += ".txt";
    return filename;
}

bool fileExists(const std::string &filename)
{
    std::ifstream file(filename);
    return file.good();
}