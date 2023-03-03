#pragma once
#include <vector>
#include <string>
using namespace std;

class Mountains
{
	std::vector<std::string> mountains;
	std::vector<std::string> Alps;
	std::vector<std::string> Icelandic_Highlands;
	std::vector<std::string> Carpathians;
	std::vector<std::string> Pyrenees;

public:
	//Time complexity: Mountains is O(n) where n is the total number of lines in the input files. 
	//This is because the constructor reads each line of the input files and stores them in the textFiles vector,
	//which takes O(n) time. It then copies the strings from the textFiles vector to the mountains vector, 
	//which also takes O(n) time. Therefore, the overall time complexity of the constructor is O(n).

	Mountains(std::vector<std::string>& filenames);

	//Time complexity: getRandomMountain is O(1) because it generates a random index within the range of the mountains vector 
	//and returns the mountain name at that index, which takes constant time. therefore the time complexity of this constructor is O(1)

	std::string getRandomMountain();

	//Time complexity: checkRange is O(n) where n is the number of mountain names in the mountains vector.
	//This is because the function iterates through all of the mountain names in the mountains vector
	//and compares each mountain name to the mountain argument, which takes O(n) time.
	//Therefore the correct time complexity of this constructor is O(n)

	bool checkRange(std::string mountain, std::string range);
};
