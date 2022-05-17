#include <iostream>
#include <string>

#include "Course.h"
#include "Assignment.h"

int main() {
    {
        Course course("Intro to Programming", 1234, 4, "monday");

        if (profile.getName() != "Intro to Programming") {
            std::cout << "CourseTest.cpp: Test 1 failed" << std::endl;
        }
    }

    {
        Course course(" ", 1234, 4, "monday");

        if (profile.getName() != " ") {
            std::cout << "CourseTest.cpp: Test 2 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setName("Philosophy 101")

        if (profile.getName() != "Philosophy 101") {
            std::cout << "CourseTest.cpp: Test 3 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setName(" ")

        if (profile.getName() != " ") {
            std::cout << "CourseTest.cpp: Test 4 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");

        if (profile.getCourseID() != 1234) {
            std::cout << "CourseTest.cpp: Test 5 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 0, 4, "monday");

        if (profile.getCourseID() != 0) {
            std::cout << "CourseTest.cpp: Test 6 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1, 4, "monday");

        if (profile.getCourseID() != 1) {
            std::cout << "CourseTest.cpp: Test 7 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", -1, 4, "monday");

        if (profile.getCourseID() != 1) {
            std::cout << "CourseTest.cpp: Test 8 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", -1234, 4, "monday");

        if (profile.getCourseID() != 1234) {
            std::cout << "CourseTest.cpp: Test 9 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setCourseID(0);

        if (profile.getCourseID() != 0) {
            std::cout << "CourseTest.cpp: Test 10 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setCourseID(1);

        if (profile.getCourseID() != 1) {
            std::cout << "CourseTest.cpp: Test 11 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setCourseID(-1);

        if (profile.getCourseID() != 1) {
            std::cout << "CourseTest.cpp: Test 12 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setCourseID(-1234);

        if (profile.getCourseID() != 1234) {
            std::cout << "CourseTest.cpp: Test 13 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");

        if (profile.getDay() != "monday") {
            std::cout << "CourseTest.cpp: Test 14 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "tuesday");

        if (profile.getDay() != "tuesday") {
            std::cout << "CourseTest.cpp: Test 15 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setDay("tuesday")

        if (profile.getDay() != "tuesday") {
            std::cout << "CourseTest.cpp: Test 16 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        course.setDay("haha")

        if (profile.getDay() != "monday") {
            std::cout << "CourseTest.cpp: Test 17 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        char grade = course.percentageToLetterGrade(85);

        if (grade != 'A') {
            std::cout << "CourseTest.cpp: Test 18 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        char grade = course.percentageToLetterGrade(0);

        if (grade != 'E') {
            std::cout << "CourseTest.cpp: Test 19 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        char grade = course.percentageToLetterGrade(110);

        if (grade != 'A') {
            std::cout << "CourseTest.cpp: Test 20 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        char grade = course.percentageToLetterGrade(-1);

        if (grade != 'E') {
            std::cout << "CourseTest.cpp: Test 21 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        char grade = course.percentageToLetterGrade(-110);

        if (grade != 'E') {
            std::cout << "CourseTest.cpp: Test 22 failed" << std::endl;
        }
    }

    {
        Course course("Intro to Programming", 1234, 4, "monday");
        Assignment assignment("Major practical", 100, "A big project");
        assignment.setGrade(100);

        char grade = course.calculateGrade(&assignment);

        if (grade != 100) {
            std::cout << "CourseTest.cpp: Test 23 failed" << std::endl;
        }
    }

    return 0;
}
