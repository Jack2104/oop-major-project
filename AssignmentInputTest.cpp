#include <iostream>
#include <string>

#include "Assignment.h"

int main() {
    Assignment assignment("Major practical", 100, "A big project");
    assignment.setGrade(100);

    std::cout << "AssignmentInputTest.cpp: testing printAssignmentInfo()..." << std::endl;
    assignment.printAssignmentInfo();

    std::cout << std::endl << "AssignmentInputTest.cpp: all tests finished" << std::endl;

    return 0;
}
