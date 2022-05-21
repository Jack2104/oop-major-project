#include <iostream>
#include <string>

#include "Admin.h"
#include "Teacher.h"
#include "Student.h"

int main() {
    Admin admin("John", "password", 1342);

    Course* course1_ptr = new Course("Philosophy 101", 1234, 4, "monday");
    Course* course2_ptr = new Course("Maths", 3452, 4, "wednesday");
    Course* course3_ptr = new Course("Programming", 2642, 4, "tuesday");
    Course* course4_ptr = new Course("Physics 101", 2753, 4, "monday");

    std::vector<Course*> courses;

    courses.push_back(course1_ptr);
    courses.push_back(course2_ptr);
    courses.push_back(course3_ptr);
    courses.push_back(course4_ptr);

    std::cout << std::endl << "AdminInputTest.cpp: testing createTeacher() 1" << std::endl;
    Teacher* teacher = admin.createTeacher(courses);
    std::cout << "Teacher name: " << teacher->getName() << ", teacher password: " << teacher->getPassword() << ", teacher ID: " << teacher->getID() << std::endl;

    std::cout << std::endl << "AdminInputTest.cpp: testing createStudent() 1" << std::endl;
    Student* student = admin.createStudent(courses);
    std::cout << "Student name: " << student->getName() << ", student password: " << student->getPassword() << ", student ID: " << student->getID() << std::endl;

    std::cout << std::endl << "AdminInputTest.cpp: testing createAdmin() 1" << std::endl;
    Admin* admin2 = admin.createAdmin();
    std::cout << "Admin name: " << admin2->getName() << ", admin2 password: " << admin2->getPassword() << ", admin2 ID: " << admin2->getID() << std::endl;

    std::cout << std::endl << "AdminInputTest.cpp: testing printTitle() 1" << std::endl;
    admin.printTitle();

    std::cout << std::endl << "AdminInputTest.cpp: testing printTitle() 1" << std::endl;
    admin.printTitle();

    std::cout << std::endl << "AdminInputTest.cpp: testing printEmail() 1" << std::endl;
    admin.printEmail();

    std::cout << std::endl << std::endl << "AdminInputTest.cpp: all tests finished" << std::endl;

    return 0;
}
