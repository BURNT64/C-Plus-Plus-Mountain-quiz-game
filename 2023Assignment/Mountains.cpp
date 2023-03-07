#include "Mountains.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <random>

using namespace std;

Mountains::Mountains(std::vector<std::string>& filenames)
{
    // Iterate through the filenames vector using a range-based for loop
    for (const std::string& filename : filenames)
    {
        std::ifstream file(filename);
        std::string line;

        while (std::getline(file, line))
        {
            // Check the value of filename and add the line string to the appropriate
            // mountain range vector
            // add all mountains to a map 

            if (filename == "Alps.txt")
                Alps.push_back(line);

            if (filename == "Carpathians.txt")
                Carpathians.push_back(line);

            if (filename == "Icelandic Highlands.txt")
                Icelandic_Highlands.push_back(line);

            if (filename == "Pyrenees.txt")
                Pyrenees.push_back(line);

            // Add the line string to the "mountains" vector, which contains all of the
            // mountains from all of the mountain range files
            mountains.push_back(line);

            // Add an entry to the mountainRanges map that associates the mountain
            // with its corresponding range
            if (filename == "Alps.txt")
                mountainRanges[line] = "Alps";
            else if (filename == "Carpathians.txt")
                mountainRanges[line] = "Carpathians";
            else if (filename == "Icelandic Highlands.txt")
                mountainRanges[line] = "Icelandic Highlands";
            else if (filename == "Pyrenees.txt")
                mountainRanges[line] = "Pyrenees";
        }
        file.close();
    }
}

std::string Mountains::getRandomMountain()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, mountains.size() - 1);
    int randomIndex = dis(gen);
    return mountains[randomIndex];
}

bool Mountains::checkRange(std::string mountain, std::string range)
{
    // Look up the range associated with the given mountain in the mountainRanges map
    auto it = mountainRanges.find(mountain);
    if (it == mountainRanges.end())
        return false; // The given mountain does not exist in any of the ranges

    // Check whether the range associated with the given mountain matches the given range
    return it->second == range;
}