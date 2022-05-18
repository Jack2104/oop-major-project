#include <iostream>
#include <string>

#include "Course.h"
#include "Assignment.h"

int main() {
    Course course("OOP", 1234, 4, "monday");
    
    std::cout << "[testing createAssignment() 1]" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "[testing createAssignment() 2]" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "[testing createAssignment() 3]" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "[testing createAssignment() 4]" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "[testing createAssignment() 5]" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "[testing printAssignmentList() 1]" << std::endl;
    course.printAssignmentList();

    std::cout << std::endl << "[testing removeAssignment() 1]" << std::endl;
    course.removeAssignment();


    return 0;
}
