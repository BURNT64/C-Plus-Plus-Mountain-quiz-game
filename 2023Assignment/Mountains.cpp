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
    // Create a pointer to a vector of strings called "rangeVector" and initialize it to null
    std::vector<std::string>* rangeVector;

    // Check the value of the "range" string and set "rangeVector" to point to the
    // appropriate mountain range vector based on the value of "range"
    if (range == "Alps")
        rangeVector = &Alps;
    else if (range == "Icelandic Highlands")
        rangeVector = &Icelandic_Highlands;
    else if (range == "Carpathians")
        rangeVector = &Carpathians;
    else if (range == "Pyrenees")
        rangeVector = &Pyrenees;
    else
        return false;

    for (const std::string& m : *rangeVector)
    {
        if (m == mountain)
            return true;
    }
    return false;
}