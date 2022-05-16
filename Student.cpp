#include <iostream>
#include <string>

#include "Student.h"

using namespace std;

Student::Student() {
    courseCount = 0;
    name = "?";
    password = "?";
    schoolID = 0;
};

Student::Student(int courseCount, string name, string password, int schoolID) {
    this->courseCount = courseCount;
    this->name = name;
    this->password = password;
    this->schoolID = schoolID;
};

Student::~Student() {};

void Student::printCourses() {
    for (int i = 0 ; i < courseCount ; i++) {
        cout << "Course: " << courses[i].getCourseID() << " " << courses[i].getName() << endl;
    }
};

void Student::enrol(string courseName) {
    
};