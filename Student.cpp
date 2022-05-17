#include <iostream>
#include <string>

#include "Student.h"

using namespace std;

Student::Student() {
    courseCount = 0;
    name = "[no name]";
    password = "[no password]";
    schoolID = 0;
};

Student::Student(int courseCount, string name, string password, int schoolID) {
    this->courseCount = courseCount;
    this->name = name;
    this->password = password;
    this->schoolID = schoolID;
    this->courses = new Course*[courseCount];
};

Student::~Student() {
    for (int i = 0; i < courseCount; i++) {
        delete this->courses[i];
    }

    delete[] this->courses;
};

void Student::printCourses() {
    cout << "### Enrolled Courses ###" << endl;
    for (int i = 0 ; i < courseCount ; i++) {
        cout << courses[i]->getCourseID() << " " << courses[i]->getName() << endl;
    }
};

void Student::enrol(string courseName) {
    
};

void Student::printTitle() {
    cout << "### " << this->name << " (Student) ###" << endl;
}

void Student::printEmail() {
    cout << "Email address: " << this->schoolID << "@student.edu" << endl;
}