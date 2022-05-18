#include <iostream>
#include <string>

#include "Course.h"
#include "Assignment.h"

int main() {
    Course course("OOP", 1234, 4, "monday");
    
    std::cout << "CourseInputTest.cpp: testing createAssignment() 1" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "CourseInputTest.cpp: testing createAssignment() 2" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "CourseInputTest.cpp: testing createAssignment() 3" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "CourseInputTest.cpp: testing createAssignment() 4" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "CourseInputTest.cpp: testing createAssignment() 5" << std::endl;
    course.createAssignment();

    std::cout << std::endl << "CourseInputTest.cpp: testing printAssignmentList() 1" << std::endl;
    course.printAssignmentList();

    std::cout << std::endl << "CourseInputTest.cpp: testing printGrade() 1" << std::endl;
    course.printGrade();

    std::cout << std::endl << "CourseInputTest.cpp: testing removeAssignment() 1" << std::endl;
    course.removeAssignment();

    std::cout << std::endl << "CourseInputTest.cpp: testing removeAssignment() 2" << std::endl;
    course.removeAssignment();

    std::cout << std::endl << "CourseInputTest.cpp: testing removeAssignment() 3" << std::endl;
    course.removeAssignment();

    std::cout << std::endl << "CourseInputTest.cpp: testing removeAssignment() 4" << std::endl;
    course.removeAssignment();

    std::cout << std::endl << "CourseInputTest.cpp: testing printAssignmentList() 2" << std::endl;
    course.printAssignmentList();

    std::cout << std::endl << "CourseInputTest.cpp: all testing finished" << std::endl;

    return 0;
}
