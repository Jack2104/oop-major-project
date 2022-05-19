#include <iostream>
#include <string>

#include "Teacher.h"
#include "Course.h"
#include "Assignment.h"

int main() {
    Teacher teacher("Mr Goh", "itsgohtime", 1234, 4);

    Course* course1_ptr = new Course("Philosophy 101", 1234, 4, "monday");
    Course* course2_ptr = new Course("Maths", 3452, 4, "wednesday");
    Course* course3_ptr = new Course("Programming", 2642, 4, "tuesday");
    Course* course4_ptr = new Course("Physics 101", 2753, 4, "monday");

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

    course1_ptr->addAssignment(philosophyAssignment1);
    course1_ptr->addAssignment(philosophyAssignment2);

    course2_ptr->addAssignment(mathsAssignment1);
    course2_ptr->addAssignment(mathsAssignment2);

    course3_ptr->addAssignment(programmingAssignment1);
    course3_ptr->addAssignment(programmingAssignment2);

    course4_ptr->addAssignment(physicsAssignment1);
    course4_ptr->addAssignment(physicsAssignment2);

    std::vector<Course*> courses;

    courses.push_back(course1_ptr);
    courses.push_back(course2_ptr);
    courses.push_back(course3_ptr);
    courses.push_back(course4_ptr);

    std::cout << std::endl << "TeacherInputTest.cpp: testing joinCourse() 1" << std::endl;
    teacher.joinCourse(courses);

    std::cout << std::endl << std::endl << "TeacherInputTest.cpp: testing joinCourse() 2" << std::endl;
    teacher.joinCourse(courses);

    std::cout << std::endl << std::endl << "TeacherInputTest.cpp: testing joinCourse() 3" << std::endl;
    teacher.joinCourse(courses);

    std::cout << std::endl << std::endl << "TeacherInputTest.cpp: testing joinCourse() 4" << std::endl;
    teacher.joinCourse(courses);

    std::cout << std::endl << std::endl << "TeacherInputTest.cpp: testing joinCourse() 5" << std::endl;
    teacher.joinCourse(courses);

    std::cout << std::endl << "TeacherInputTest.cpp: testing createCourse() 1" << std::endl;
    Course* course_ptr = teacher.createCourse();
    courses.push_back(course_ptr);

    std::cout << "Course name: " << course_ptr->getName() << ", course ID: " << course_ptr->getCourseID() << ", course day: " << course_ptr->getDay() << std::endl;

    std::cout << std::endl << "TeacherInputTest.cpp: testing leaveCourse() 1" << std::endl;
    teacher.leaveCourse();

    std::cout << std::endl << "TeacherInputTest.cpp: testing joinCourse() 6" << std::endl;
    teacher.joinCourse(courses);

    std::cout << std::endl << "TeacherInputTest.cpp: testing grade() 1" << std::endl;
    teacher.grade();

    std::cout << std::endl << "TeacherInputTest.cpp: testing grade() 2" << std::endl;
    teacher.grade();

    std::cout << std::endl << "TeacherInputTest.cpp: testing printTitle() 1" << std::endl;
    teacher.printTitle();

    std::cout << std::endl << "TeacherInputTest.cpp: testing printEmail() 1" << std::endl;
    teacher.printEmail();

    std::cout << std::endl << "TeacherInputTest.cpp: all tests finished" << std::endl;

    return 0;
}
