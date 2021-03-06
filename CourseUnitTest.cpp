#include <iostream>
#include <string>

#include "Course.h"
#include "Assignment.h"

int main() {
    {
        Course course("Intro to Programming", 1234, 4, "monday");

        if (course.getName() != "Intro to Programming") {
            std::cout << "CourseUnitTest.cpp: Test 1 failed" << std::endl;
        }
    }

    {
        Course course(" ", 1234, 4, "monday");

        if (course.getName() != " ") {
            std::cout << "CourseUnitTest.cpp: Test 2 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setName("Philosophy 101");

        if (course.getName() != "Philosophy 101") {
            std::cout << "CourseUnitTest.cpp: Test 3 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setName(" ");

        if (course.getName() != " ") {
            std::cout << "CourseUnitTest.cpp: Test 4 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");

        if (course.getCourseID() != 1234) {
            std::cout << "CourseUnitTest.cpp: Test 5 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 0, 4, "monday");

        if (course.getCourseID() != 0) {
            std::cout << "CourseUnitTest.cpp: Test 6 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1, 4, "monday");

        if (course.getCourseID() != 1) {
            std::cout << "CourseUnitTest.cpp: Test 7 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", -1, 4, "monday");

        if (course.getCourseID() != 1) {
            std::cout << "CourseUnitTest.cpp: Test 8 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", -1234, 4, "monday");

        if (course.getCourseID() != 1234) {
            std::cout << "CourseUnitTest.cpp: Test 9 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setCourseID(0);

        if (course.getCourseID() != 0) {
            std::cout << "CourseUnitTest.cpp: Test 10 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setCourseID(1);

        if (course.getCourseID() != 1) {
            std::cout << "CourseUnitTest.cpp: Test 11 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setCourseID(-1);

        if (course.getCourseID() != 1) {
            std::cout << "CourseUnitTest.cpp: Test 12 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setCourseID(-1234);

        if (course.getCourseID() != 1234) {
            std::cout << "CourseUnitTest.cpp: Test 13 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");

        if (course.getDay() != "monday") {
            std::cout << "CourseUnitTest.cpp: Test 14 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "tuesday");

        if (course.getDay() != "tuesday") {
            std::cout << "CourseUnitTest.cpp: Test 15 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setDay("tuesday");

        if (course.getDay() != "tuesday") {
            std::cout << "CourseUnitTest.cpp: Test 16 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setDay("haha");

        if (course.getDay() != "monday") {
            std::cout << "CourseUnitTest.cpp: Test 17 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        char grade = course.percentageToLetterGrade(85);

        if (grade != 'A') {
            std::cout << "CourseUnitTest.cpp: Test 18 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        char grade = course.percentageToLetterGrade(0);

        if (grade != 'E') {
            std::cout << "CourseUnitTest.cpp: Test 19 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        char grade = course.percentageToLetterGrade(110);

        if (grade != 'A') {
            std::cout << "CourseUnitTest.cpp: Test 20 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        char grade = course.percentageToLetterGrade(-1);

        if (grade != 'E') {
            std::cout << "CourseUnitTest.cpp: Test 21 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        char grade = course.percentageToLetterGrade(-110);

        if (grade != 'E') {
            std::cout << "CourseUnitTest.cpp: Test 22 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        Assignment* assignment = new Assignment("Major practical", 100, "A big project");
        assignment->setGrade(100);

        course.addAssignment(assignment);

        int grade = course.calculateGrade();

        if (grade != 100) {
            std::cout << "CourseUnitTest.cpp: Test 23 failed" << std::endl;
        }
    }

    return 0;
}
