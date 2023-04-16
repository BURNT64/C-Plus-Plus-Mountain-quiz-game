#pragma once
#include <vector>
#include <string>
#include <utility>
using namespace std;

class Functions
{
	void printIntroduction(const std::string& playerName);
	std::string getUserResponse();
	void printRangePrompt(const std::string& mountain);
	std::string getRangeInput();
	void convertRangeInput(std::string& range);
	bool handleUserInput(const std::string& range, Mountains& mountains, int& correctScore, int& incorrectScore, int& questions, std::vector<std::pair<std::string, double>>& correct_answers, std::vector<std::pair<std::string, double>>& incorrect_answers);
};