// Copyright (c) 2022 Peter Sobowale All rights reserved.
//
// Created by: Peter Sobowale
// Created on: Nov 14,  2022
// This program asks the user to guess a number
// it then checks if they get it wrong, they are told so.

#include <iostream>
#include <random>

int main() {
    // Generates a random number from 0 to 9
    int randomNumber;
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);
    randomNumber = idist(rgen);
    // declare variables
    int loopCounter = 0, userNumber;
    std::string userNumString;

    while (true) {
        // get the user number as a string
        std::cout << "Enter a whole number between 0 and 9: ";
        std::cin >> userNumString;
        try {
            // convert from string to int
            userNumber = std::stoi(userNumString);
            // if statement for between 0 and 9
            if (userNumber >= 0 && userNumber <= 9) {
                loopCounter++;
                // if they guess correctly display it
                if (userNumber == randomNumber) {
                    std::cout << userNumber << " is correct, good job!";
                    break;
                } else {
                    // if they guess incorrectly display it
                    std::cout << userNumber << " is incorrect.";
                    std::cout << std::endl;
                    // track how many times they go through the loop
                    std::cout << "Tracking ";
                    std::cout << loopCounter << " times through the loop";
                    std::cout << std::endl;
                }
            } else {
                // Display if they didn't guess between 0 and 9
                std::cout << "This number is not between 0 and 9\n";
            }
            // Tell the user that they didn't input a valid integer
        } catch (std::invalid_argument) {
            std::cout << userNumString << " is invalid";
            std::cout << std::endl;
        }
    }
}
