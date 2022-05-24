#include <iostream>
#include <string>
#include <vector>

#include "Utils.h"

int main() {
    std::vector<std::string> acceptedInputs;
    acceptedInputs.push_back("hello");
    acceptedInputs.push_back("test");

    std::cout << "UtilsInputTest.cpp: testing getStringInput() 1" << std::endl;
    std::string input = Utils::getStringInput("Enter a string", "cannot be only whitespace or a newline", true);
    std::cout << std::endl;

    std::cout << "UtilsInputTest.cpp: testing getStringInput() 2" << std::endl;
    std::string input2 = Utils::getStringInput("Enter a string", "cannot be only whitespace or a newline", true, acceptedInputs);
    std::cout << std::endl;

    std::cout << "UtilsInputTest.cpp: testing getIntInput() 1" << std::endl;
    int input3 = Utils::getIntInput("Enter a number", "all characters after any spaces will be ignored", true);
    std::cout << std::endl;

    std::cout << "UtilsInputTest.cpp: testing getIntInput() 2" << std::endl;
    int input4 = Utils::getIntInput("Enter a number", "all characters after any spaces will be ignored", true, 0, 100);
    std::cout << std::endl;

    std::cout << "UtilsInputTest.cpp: all tests finished" << std::endl;

    return 0;
}
