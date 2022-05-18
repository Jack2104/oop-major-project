#include <iostream>
#include <string>

#include "Assignment.h"

int main() {
    {
        Assignment assignment("Major practical", 100, "A big project");

        if (assignment.getName() != "Major practical") {
            std::cout << "AssignmentUnitTest.cpp: Test 1 failed" << std::endl;
        }
    }

    {
        Assignment assignment(" ", 100, "A big project");

        if (assignment.getName() != " ") {
            std::cout << "AssignmentUnitTest.cpp: Test 2 failed" << std::endl;
        }
    }

    {
        Assignment assignment("", 100, "A big project");

        if (assignment.getName() != "") {
            std::cout << "AssignmentUnitTest.cpp: Test 3 failed" << std::endl;
        }
    }


    {
        Assignment assignment("Major practical", 100, "A big project");
        assignment.setName("Major practical 2");

        if (assignment.getName() != "Major practical 2") {
            std::cout << "AssignmentUnitTest.cpp: Test 4 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 100, "A big project");
        assignment.setName("");

        if (assignment.getName() != "") {
            std::cout << "AssignmentUnitTest.cpp: Test 5 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 100, "A big project");

        if (assignment.getWeight() != 100) {
            std::cout << "AssignmentUnitTest.cpp: Test61 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 0, "A big project");

        if (assignment.getWeight() != 0) {
            std::cout << "AssignmentUnitTest.cpp: Test 7 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 1, "A big project");

        if (assignment.getWeight() != 1) {
            std::cout << "AssignmentUnitTest.cpp: Test 8 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", -1, "A big project");

        if (assignment.getWeight() != 0) {
            std::cout << "AssignmentUnitTest.cpp: Test 9 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 65, "A big project");

        if (assignment.getWeight() != 65) {
            std::cout << "AssignmentUnitTest.cpp: Test 10 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 100, "A big project");
        assignment.setWeight(0);

        if (assignment.getWeight() != 0) {
            std::cout << "AssignmentUnitTest.cpp: Test 11 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "A big project");
        assignment.setWeight(100);

        if (assignment.getWeight() != 100) {
            std::cout << "AssignmentUnitTest.cpp: Test 12 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "A big project");
        assignment.setWeight(1000);

        if (assignment.getWeight() != 100) {
            std::cout << "AssignmentUnitTest.cpp: Test 13 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 100, "A big project");
        assignment.setWeight(1);

        if (assignment.getWeight() != 1) {
            std::cout << "AssignmentUnitTest.cpp: Test 14 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "A big project");
        assignment.setWeight(-1);

        if (assignment.getWeight() != 0) {
            std::cout << "AssignmentUnitTest.cpp: Test 15 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "A big project");

        if (assignment.getDescription() != "A big project") {
            std::cout << "AssignmentUnitTest.cpp: Test 16 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, " ");

        if (assignment.getDescription() != " ") {
            std::cout << "AssignmentUnitTest.cpp: Test 17 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "");

        if (assignment.getDescription() != "") {
            std::cout << "AssignmentUnitTest.cpp: Test 18 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "A big project");
        assignment.setDescription("A different big project");

        if (assignment.getDescription() != "A different big project") {
            std::cout << "AssignmentUnitTest.cpp: Test 19 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "A big project");
        assignment.setDescription(" ");

        if (assignment.getDescription() != " ") {
            std::cout << "AssignmentUnitTest.cpp: Test 20 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "");
        assignment.setDescription("");

        if (assignment.getDescription() != "") {
            std::cout << "AssignmentUnitTest.cpp: Test 21 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "A big project");
        assignment.setGrade(100);

        if (assignment.getGrade() != 100) {
            std::cout << "AssignmentUnitTest.cpp: Test 22 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "A big project");
        assignment.setGrade(1000);

        if (assignment.getGrade() != 100) {
            std::cout << "AssignmentUnitTest.cpp: Test 23 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "A big project");
        assignment.setGrade(50);

        if (assignment.getGrade() != 50) {
            std::cout << "AssignmentUnitTest.cpp: Test 24 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "A big project");
        assignment.setGrade(1);

        if (assignment.getGrade() != 1) {
            std::cout << "AssignmentUnitTest.cpp: Test 25 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "A big project");
        assignment.setGrade(0);

        if (assignment.getGrade() != 0) {
            std::cout << "AssignmentUnitTest.cpp: Test 26 failed" << std::endl;
        }
    }

    {
        Assignment assignment("Major practical", 50, "A big project");
        assignment.setGrade(-1);

        if (assignment.getGrade() != 0) {
            std::cout << "AssignmentUnitTest.cpp: Test 27 failed" << std::endl;
        }
    }

    return 0;
}
