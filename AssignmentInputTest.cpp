#include <iostream>
#include <string>

#include "Assignment.h"

int main() {
    Assignment assignment("Major practical", 100, "A big project");
    assignment.setGrade(100);

    std::cout << "Testing printAssignmentInfo()..." << std::ednl;
    assignment.printAssignmentInfo();

    return 0;
}
