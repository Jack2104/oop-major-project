#include <iostream>
#include <string>
#include <vector>

#include "Utils.h"

int main() {
    std::cout << "UtilsInputTest.cpp: testing getStringInput() 1" << std::endl;
    std::string input = Utils::getStringInput("Enter a string", "cannot be only whitespace or a newline");
    std::cout << "Input: " << input << std::endl;

    std::cout << "UtilsInputTest.cpp: testing getStringInput() 2" << std::endl;
    std::vector<string> acceptedInputs({"hello", "test"});
    std::string input = Utils::getStringInput("Enter a string", "cannot be only whitespace or a newline", acceptedInput);
    std::cout << "Input: " << input << std::endl;

    std::cout << "UtilsInputTest.cpp: testing getIntInput() 1" << std::endl;
    std::string input = Utils::getIntInput("Enter a number", "all characters after any spaces will be ignored");
    std::cout << "Input: " << input << std::endl;

    std::cout << "UtilsInputTest.cpp: testing getIntInput() 2" << std::endl;
    std::string input = Utils::getIntInput("Enter a number", "all characters after any spaces will be ignored", 0, 100);
    std::cout << "Input: " << input << std::endl;

    return 0;
}
