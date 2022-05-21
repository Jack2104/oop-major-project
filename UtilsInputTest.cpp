#include <iostream>
#include <string>
#include <vector>

#include "Utils.h"

int main() {
    std::vector<std::string> acceptedInputs;
    acceptedInputs.push_back("hello");
    acceptedInputs.push_back("test");

    std::cout << "UtilsInputTest.cpp: testing getStringInput() 1" << std::endl;
    std::string input = Utils::getStringInput("Enter a string", "cannot be only whitespace or a newline");
    std::cout << "Input: " << input << std::endl;

    std::cout << "UtilsInputTest.cpp: testing getStringInput() 2" << std::endl;
    std::string input2 = Utils::getStringInput("Enter a string", "cannot be only whitespace or a newline", acceptedInputs);
    std::cout << "Input: " << input2 << std::endl;

    std::cout << "UtilsInputTest.cpp: testing getIntInput() 1" << std::endl;
    int input3 = Utils::getIntInput("Enter a number", "all characters after any spaces will be ignored");
    std::cout << "Input: " << input3 << std::endl;

    std::cout << "UtilsInputTest.cpp: testing getIntInput() 2" << std::endl;
    int input4 = Utils::getIntInput("Enter a number", "all characters after any spaces will be ignored", 0, 100);
    std::cout << "Input: " << input4 << std::endl;

    return 0;
}
