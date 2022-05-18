#include <iostream>
#include <string>

#include "Course.h"
#include "Assignment.h"

int main() {
    Course course("OOP", 1234, 4, "monday");
    
    std::cout << "[testing createAssignment()]" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "[testing createAssignment()]" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "[testing createAssignment()]" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "[testing createAssignment()v" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "[testing createAssignment()]" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "[testing printAssignmentList()]" << std::endl;
    course.printAssignmentList();

    std::cout << std::endl << "[testing removeAssignment()]" << std::endl;
    course.removeAssignment();


    return 0;
}
