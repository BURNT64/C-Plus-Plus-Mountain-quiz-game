#pragma once
#include <vector>
#include <string>
#include <map>
using namespace std;

class Mountains
{
	std::vector<std::string> mountains;
	std::map<std::string, std::string> mountainRanges;
	std::vector<std::string> Alps;
	std::vector<std::string> Icelandic_Highlands;
	std::vector<std::string> Carpathians;
	std::vector<std::string> Pyrenees;
public:

	Mountains(std::vector<std::string>& filenames);

	std::string getRandomMountain();

	bool checkRange(std::string mountain, std::string range);
};