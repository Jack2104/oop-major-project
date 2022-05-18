#include <iostream>
#include <string>

#include "Course.h"
#include "Assignment.h"

int main() {
    Course course("OOP", 1234, 4, "monday");
    
    std::cout << "Testing createAssignment()..." << std::endl;
    course.createAssignment();

    return 0;
}
