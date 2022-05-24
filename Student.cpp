#include <iostream>
#include <string>
#include <vector>

#include "Student.h"
#include "Course.h"

using namespace std;

Student::Student() : Profile() {
    currentCourseCount = 0;
    maxCourseCount = 0;
};

Student::Student(string name, string password, int schoolID, int maxCourseCount) : Profile(name, password, schoolID) {
    this->maxCourseCount = maxCourseCount;
    this->currentCourseCount = 0;
    this->courses = new Course*[maxCourseCount];
};

Student::~Student() {
    for (int i = 0; i < currentCourseCount; i++) {
        delete this->courses[i];
    }

    delete[] this->courses;
};

void Student::printCourses() {
    cout << endl << "### Enrolled Courses ###" << endl;

    if (currentCourseCount == 0) {
        cout << "You aren't enrolled in any courses" << endl;
        return;
    }

    for (int i = 0 ; i < currentCourseCount ; i++) {
        cout << courses[i]->getCourseID() << " " << courses[i]->getName() << endl;
    }
};

void Student::printTimetable() {
    cout << endl << "### Timetable ###" << endl;

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

void Student::enrol(vector<Course*> courses, string name) {
    if (this->currentCourseCount >= this->maxCourseCount) {
        cout << "Sorry, but you can't enrol in any more courses." << endl;
        return;
    }

    vector<Course*>::iterator c_ptr;

    // Print the name of every course
    for(c_ptr = courses.begin(); c_ptr < courses.end(); c_ptr++) {
        Course* course = *c_ptr;

        if (course->getName() == name) {
            for (int i = 0; i < this->currentCourseCount; i++) {
                Course* enrolled_course = this->courses[i];

                if (enrolled_course->getName() == course->getName()) {
                    cout << "You're already enrolled in this course" << endl;
                    return;
                }
            }

            this->courses[this->currentCourseCount] = course; //&(*c_ptr);
            this->currentCourseCount++;
            cout << "Successfully enrolled in course" << endl;
            return;
        }
    }

    cout << "There's no course with that name. Please try again." << endl;
};

void Student::enrol(vector<Course*> courses, int id) {
    if (this->currentCourseCount >= this->maxCourseCount) {
        cout << "Sorry, but you can't enrol in any more courses." << endl;
        return;
    }

    vector<Course*>::iterator c_ptr;

    // Print the name of every course
    for(c_ptr = courses.begin(); c_ptr < courses.end(); c_ptr++) {
        Course* course = *c_ptr;

        if (course->getCourseID() == id) {
            for (int i = 0; i < this->currentCourseCount; i++) {
                Course* enrolled_course = this->courses[i];

                if (enrolled_course->getCourseID() == course->getCourseID()) {
                    cout << "You're already enrolled in this course" << endl;
                    return;
                }
            }

            this->courses[this->currentCourseCount] = course; //&(*c_ptr);
            this->currentCourseCount++;
            cout << "Successfully enrolled in course" << endl;
            return;
        }
    }

    cout << "There's no course with that ID. Please try again." << endl;
};

void Student::unenroll() {
    if (this->currentCourseCount == 0) {
        cout << "You aren't enrolled in any courses" << endl;
        return;
    }

    cout << "You are enrolled in the following courses:" << endl;

    for (int i = 0; i < this->currentCourseCount; i++) {
        Course* course = this->courses[i];
        cout << "• " << course->getName() << endl;
    }

    string name;
    cout << "Enter the name of the course you'd like to leave: ";

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, name) || name.empty() || name.find_first_not_of(' ') == string::npos || name.find_first_not_of('	') == string::npos) {
        cout << "Sorry, that's not a valid input. Please enter an course name." << endl << "Course name: ";
    }

    // Find the assignment to be deleted
    for (int i = 0; i < this->currentCourseCount; i++) {
        Course* course = this->courses[i];

        if (course->getName() == name) {
            for (int j = i; j < this->currentCourseCount - 1; j++) {
                this->courses[j] = this->courses[j + 1];
            }

            // delete this->courses[i]; // Delete the assignment from memory
            
            this->currentCourseCount--;
            cout << "You successfully left that course." << endl;
            return;
        }
    }

    cout << "The course you entered does not exist. Please try again." << endl;
}

void Student::printReport() {
    cout << endl << "<====== " << this->name << "'s Report Card ======>" << endl;

    for (int i = 0; i < this->currentCourseCount; i++) {
        Course* course = courses[i];
        course->printGrade();
        cout << endl;
    }
};

void Student::printTitle() {
    cout << endl << "### " << this->name << " (Student) ###" << endl;
};

void Student::printEmail() {
    cout << "Email address: " << this->schoolID << "@student.edu" << endl;
};