#include <iostream>
#include <string>
#include <vector>

#include "Student.h"
#include "Course.h"

using namespace std;

Student::Student() {
    currentCourseCount = 0;
    maxCourseCount = 0;
    name = "[no name]";
    password = "[no password]";
    schoolID = 0;
};

Student::Student(string name, string password, int schoolID, int maxCourseCount) {
    this->maxCourseCount = maxCourseCount;
    this->currentCourseCount = 0;
    this->name = name;
    this->password = password;
    this->schoolID = schoolID;
    this->courses = new Course*[maxCourseCount];
};

Student::~Student() {
    for (int i = 0; i < currentCourseCount; i++) {
        delete this->courses[i];
    }

    delete[] this->courses;
};

void Student::printCourses() {
    cout << "### Enrolled Courses ###" << endl;

    for (int i = 0 ; i < currentCourseCount ; i++) {
        cout << courses[i]->getCourseID() << " " << courses[i]->getName() << endl;
    }
};

void Student::printTimetable() {
    cout << "### Timetable ###" << endl;

    string days[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

    for (int i = 0; i < 7; i++) {
        string day = days[i];
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

void Student::enrol(vector<Course>* courses, string name) {
    if (this->currentCourseCount >= this->maxCourseCount) {
        cout << "Sorry, but you can't enrol in any more courses." << endl;
        return;
    }

    vector<Course>::iterator c_ptr;

    // Print the name of every course
    for(c_ptr = courses->begin(); c_ptr < courses->end(); c_ptr++) {
        if (c_ptr->getName() == name) {
            this->courses[this->currentCourseCount] = &(*c_ptr);
            this->currentCourseCount++;
            cout << "Successfully enrolled in course" << endl;
            return;
        }
    }

    cout << "There's no course with that name. Please try again." << endl;
};

void Student::enrol(vector<Course>* courses, int id) {
    if (this->currentCourseCount >= this->maxCourseCount) {
        cout << "Sorry, but you can't enrol in any more courses." << endl;
        return;
    }

    vector<Course>::iterator c_ptr;

    // Print the name of every course
    for(c_ptr = courses->begin(); c_ptr < courses->end(); c_ptr++) {
        if (c_ptr->getCourseID() == id) {
            this->courses[this->currentCourseCount] = &(*c_ptr);
            this->currentCourseCount++;
            cout << "Successfully enrolled in course" << endl;
            return;
        }
    }

    cout << "There's no course with that ID. Please try again." << endl;
};

void Student::unenroll() {
    cout << "You are enrolled in the following courses:" << endl;

    for (int i = 0; i < this->currentCourseCount; i++) {
        Course* course = this->courses[i];
        cout << course->getName() << endl;
    }

    string name;
    cout << "Enter the name of the course you'd like to leave: ";

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, name) || name.empty()) {
        cout << "Sorry, that's not a valid input. Please enter an course name." << endl << "Course name: ";
    }

    // Find the assignment to be deleted
    for (int i = 0; i < this->currentCourseCount; i++) {
        Course* course = this->courses[i];

        if (course->getName() == name) {
            delete this->courses[i]; // Delete the assignment from memory
            this->currentCourseCount--;
            cout << "You successfully left that course." << endl;
            return;
        }
    }

    cout << "The course you entered does not exist. Please try again." << endl;
}

void Student::printReport() {
    cout << "### " << this->getName() << "'s Report Card ###" << endl;

    for (int i = 0; i < this->currentCourseCount; i++) {
        Course* course = courses[i];
        course->printGrade();
    }
};

void Student::printTitle() {
    cout << "### " << this->name << " (Student) ###" << endl;
};

void Student::printEmail() {
    cout << "Email address: " << this->schoolID << "@student.edu" << endl;
};