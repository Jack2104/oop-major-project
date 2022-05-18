#include <iostream>
#include <string>

#include "Course.h"
#include "Assignment.h"

int main() {
    Course course("OOP", 1234, 4, "monday");
    
    std::cout << "Testing createAssignment()..." << std::endl;
    course.createAssignment();

    std::cout << "Testing createAssignment()..." << std::endl;
    course.createAssignment();

    std::cout << "Testing createAssignment()..." << std::endl;
    course.createAssignment();

    std::cout << "Testing createAssignment()..." << std::endl;
    course.createAssignment();

    std::cout << "Testing createAssignment()..." << std::endl;
    course.createAssignment();

    std::cout << std::endl << "Testing printAssignmentList()..." << std::endl;
    course.printAssignmentList();

    std::cout << std::endl << "Testing removeAssignment()..." << std::endl;
    course.removeAssignment();


    return 0;
}
