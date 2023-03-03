#include "Mountains.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <algorithm>
#include <thread>
using namespace std;

int main()
{
    cout << "---------------------------------------------------------------\n";
    cout << "Guess the random mountain!!!! Created by Will Allwood 2022-2023\n";
    cout << "---------------------------------------------------------------\n\n";
    cout << "Welcome to the Mountain game!\n\n";
    cout << "You will be repeatedly presented with random mountain names and must guess which of four mountain ranges it is in\n\n";

    string UserResponse;
    cout << "Are you ready to take the quiz?\n\n"
        "yes/no" << endl;
    cin >> UserResponse;

    if (UserResponse == "yes")
    {
        cout << endl;
        cout << "Wonderful let the game begin!!!" << endl;
        cout << "You will be given a series of random mountains based of 4 mountain ranges" << endl;
        cout << "These mountain ranges are: Alps(A), Carpathians(C), Icelandic Highlands(I), and Pyrenees(P)" << endl;
        cout << "To answer, simply enter the letter corresponding to the mountain range (can be lower or upper case)" << endl;
        cout << "Points are awarded for every correct question answered within 10 seconds" << endl;
        cout << "If you take more than 10 seconds to answer you recieve no points" << endl;
        cout << "your points will be tallied up based on how many questions you answered/got right" << endl;
        cout << "This program is designed to run until you wish to exit/quit the program" << endl;
        cout << "If you wish to exit the program at any time simply type exit/quit instead of an answer" << endl;
        cout << "Good luck!!!\n" << endl;
    }
    else
    {
        cout << "Thats a shame... come back when you are ready to play" << endl;
        return 0;
    }

    std::vector<std::string> filenames = { "Alps.txt", "Carpathians.txt", "Icelandic Highlands.txt", "Pyrenees.txt" };
    // create a Mountains object
    Mountains mountains(filenames);

    int score = 0; // keep track of the user's score
    int questions = 0; // keep track of the number of questions asked
    std::string mountain; // mountain name
    std::string range; // mountain range

    std::vector<std::pair<std::string, double>> correct_answers; // keep track of correct answers and their response times

    while (true)
    {
        // get a random mountain name
        mountain = mountains.getRandomMountain();
        std::cout << "Which range is " << mountain << " in? (A, C, I, or P) ";

        // measure response time
        auto start = std::chrono::high_resolution_clock::now();
        std::cin >> range;
        auto end = std::chrono::high_resolution_clock::now();

        // convert input letter to full mountain range name
        if (range == "A" || range == "a")
            range = "Alps";
        else if (range == "C" || range == "c")
            range = "Carpathians";
        else if (range == "I" || range == "i")
            range = "Icelandic Highlands";
        else if (range == "P" || range == "p")
            range = "Pyrenees";

        // calculate response time in seconds
        double response_time = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

        // check if the user wants to exit
        if (range == "exit" || range == "quit")
            break;
        questions++;

        // check if the response time is within 10 seconds
        if (response_time > 10.0) {
            std::cout << "\nSorry, you took too long to answer.\n";
        }
        else {
            // check if the mountain belongs to the specified range
            if (mountains.checkRange(mountain, range)) {
                std::cout << "\nCorrect, " << mountain << " is in the " << range << " range.\n";
                score++;

                // store correct answer and response time in the vector
                correct_answers.push_back(std::make_pair(mountain, response_time));
            }
            else {
                std::cout << "\nIncorrect, " << mountain << " is not in the " << range << " range.\n";
            }
        }
        std::cout << "Your score is " << score << "/" << questions << ".\n";
    }

    // print out the user's results
    std::cout << "\n\n\n";
    std::cout << "Results:\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Total questions asked: " << questions << "\n";
    std::cout << "Total correct answers: " << score << "\n";
    std::cout << "Percentage correct: " << (double)score / questions * 100 << "%\n";

    // sort correct_answers vector by response time
    std::sort(correct_answers.begin(), correct_answers.end(), [](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
        return a.second < b.second;
        });

    // print out correct answers and response times
    std::cout << "\nCorrect answers and response times:\n";
    std::cout << "----------------------------------------\n";
    for (auto& answer : correct_answers) {
        std::cout << answer.first << ": " << answer.second << " seconds\n";
    }

    std::cout << "\nThank you for playing" << endl;

    return 0;
}