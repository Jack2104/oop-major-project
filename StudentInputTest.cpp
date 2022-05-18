#include <iostream>
#include <string>
#include <vector>

#include "Student.h"
#include "Course.h"
#include "Assignment.h"

int main() {
    Student student("Bob", "password1", 1234, 4);

    Course course1("Philosophy 101", 1234, 4, "monday");
    Course course2("Maths", 3452, 4, "wednesday");
    Course course3("Programming", 2642, 4, "tuesday");
    Course course4("Physics 101", 2753, 4, "monday");

    Assignment* philosophyAssignment1 = new Assignment("Essay", 70, "A philosophy essay");
    Assignment* philosophyAssignment2 = new Assignment("Oral arguments", 30, "An oral presentation");

    Assignment* mathsAssignment1 = new Assignment("Maths test", 50, "A standard maths test");
    Assignment* mathsAssignment2 = new Assignment("Written assignment", 50, "A maths written assignment");

    Assignment* programmingAssignment1 = new Assignment("Practical exam", 20, "Easy coding problems");
    Assignment* programmingAssignment2 = new Assignment("Major project", 80, "A big undertaking");

    Assignment* physicsAssignment1 = new Assignment("Physics test", 50, "A standard physics test");
    Assignment* physicsAssignment2 = new Assignment("SHE task", 50, "A standard SHE task");

    philosophyAssignment1->setGrade(84);
    philosophyAssignment2->setGrade(90);

    mathsAssignment1->setGrade(60);
    mathsAssignment2->setGrade(60);

    programmingAssignment1->setGrade(100);
    programmingAssignment2->setGrade(95);

    physicsAssignment1->setGrade(55);
    physicsAssignment2->setGrade(71);

    course1.addAssignment(philosophyAssignment1);
    course1.addAssignment(philosophyAssignment2);

    course2.addAssignment(mathsAssignment1);
    course2.addAssignment(mathsAssignment2);

    course3.addAssignment(programmingAssignment1);
    course3.addAssignment(programmingAssignment2);

    course4.addAssignment(physicsAssignment1);
    course4.addAssignment(physicsAssignment2);

    std::vector<Course> courses;


    courses.push_back(course1);
    courses.push_back(course2);

    std::cout << &course3 << ", " << &course4 << std::endl;

    courses.push_back(course3);
    courses.push_back(course4);


    student.enrol(&courses, "Philosophy 101");
    student.enrol(&courses, "Maths");
    student.enrol(&courses, 2642);
    student.enrol(&courses, 2753);

    std::cout << "7" << std::endl;

    std::cout << "StudentInputTest.cpp: testing printReport() 1" << std::endl;
    student.printReport();

    std::cout << "StudentInputTest.cpp: testing printTimetable() 1" << std::endl;
    student.printTimetable();

    student.unenroll();
    student.unenroll();

    std::cout << "StudentInputTest.cpp: testing printReport() 2" << std::endl;
    student.printReport();

    std::cout << "StudentInputTest.cpp: testing printTimetable() 2" << std::endl;
    student.printTimetable();

    std::cout << "StudentInputTest.cpp: testing printTitle() 1" << std::endl;
    student.printTitle();

    std::cout << "StudentInputTest.cpp: testing printEmail() 1" << std::endl;
    student.printEmail();

    std::cout << std::endl << "StudentInputTest.cpp: all tests finished";

    return 0;
}
