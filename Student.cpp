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

Student::Student(int maxCourseCount, string name, string password, int schoolID) {
    this->maxCourseCount = maxCourseCount;
    this->currentCourseCount = 0;
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

void Student::printTimetable() {
    cout << "### Timetable ###" << endl;

    string days[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

    for (int i = 0; i < 7; i++) {
        day = days[i];
        cout << day << ": ";

        for (int i = 0; i < this->currentCourseCount; i++) {
            Course* course = this->courses[i];

            if (course->getDay() == day) {
                cout << course->getName() << ", ";
            }
        }

        cout << endl;
    }
}

void Student::enrol(string courseName) {
    
};

void Student::printReport() {
    cout << "### " << this->getName() << "'s Report Card ###" << endl;
    for (int i = 0 ; i < 10 ; i++) {
        cout << courses[i]->getCourseID() << " " << courses[i]->getName() << " [" << courses[i]->printGrade() << "]" << endl; 
    }
};

void Student::printTitle() {
    cout << "### " << this->name << " (Student) ###" << endl;
};

void Student::printEmail() {
    cout << "Email address: " << this->schoolID << "@student.edu" << endl;
};