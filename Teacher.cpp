#include <iostream>
#include <string>

#include "Teacher.h"
#include "Course.h"

using namespace std;

Teacher::Teacher() : name("[no name]"), password("[no password]"), schoolID(0), maxCourseCount(4) {};

Teacher::Teacher(string name, string password, int schoolID, int maxCourseCount) {
    this->name = name;
    this->password = password;
    this->schoolID = schoolID;
    this->maxCourseCount = maxCourseCount;
    this->currentCourseCount = 0;

    this->teachableCourses = new Course*[maxCourseCount];
};

Teacher::~Teacher() {
    for (int i = 0; i < currentCourseCount; i++) {
        delete this->teachableCourses[i];
    }

    delete[] this->teachableCourses;
};

void Teacher::joinCourse(vector<Course>* courses) {
    if (this->currentCourseCount >= this->maxAssignmentCount) {
        cout << "Sorry, but you can't teach any more courses" << endl;
    }

    this->currentCourseCount++;

    cout << "The following courses are available to join:" << endl;

    vector<Course>::iterator c_ptr;

    // Print the name of every course
    for(c_ptr = courses->begin(); c_ptr < courses->end(); c_ptr++) {
        cout << c_ptr->getName() << endl;
    }

    cout << endl << "Select a course by entering its name: ";

    string courseName;

    while (!getline(cin, courseName) || courseName.empty()) {
        // Check to see if the inputted course is in the available courses list
        for(c_ptr = courses->begin(); c_ptr < courses->end(); c_ptr++) {
            if (c_ptr->getName() == courseName) {
                this->teachableCourses[this->currentCourseCount] = c_ptr;
                cout << "You successfully joined " << courseName << endl;
                break;
            }
        }

        cout << courseName << " is not an available course. Please try again" << endl << "Select a course by entering its name: ";
    }
};

void Teacher::createCourse() {

};

void Teacher::deleteCourse() {

};

void Teacher::grade(Assignment* assignment) {

};

void Teacher::printTitle() {
    cout << "### " << this->name << " (teacher) ###" << endl;
}

void Teacher::printEmail() {
    cout << "Email address: " << this->schoolID << "@teacher.edu" << endl;
}
