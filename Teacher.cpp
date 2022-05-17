#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Teacher.h"
#include "Course.h"

using namespace std;

Teacher::Teacher() { this->maxCourseCount = 4; };

Teacher::Teacher(string name, string password, int schoolID, int maxCourseCount) : Profile(name, password, schoolID) {
    // this->name = name;
    // this->password = password;
    // this->schoolID = schoolID;
    this->maxCourseCount = maxCourseCount;
    this->currentCourseCount = 0;

    this->teachableCourses = new Course*[maxCourseCount];
}

Teacher::~Teacher() {
    for (int i = 0; i < currentCourseCount; i++) {
        delete this->teachableCourses[i];
    }

    delete[] this->teachableCourses;
}

void Teacher::joinCourse(vector<Course>* courses) {
    if (this->currentCourseCount >= this->maxCourseCount) {
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
                this->teachableCourses[this->currentCourseCount] = &(*c_ptr);
                cout << "You successfully joined " << courseName << endl;
                break;
            }
        }

        cout << courseName << " is not an available course. Please try again" << endl << "Select a course by entering its name: ";
    }
}

Course Teacher::createCourse() {
    cout << "### Create new course ###" << endl;

    string name;
    cout << "Course name: ";

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, name) || name.empty()) {
        cout << "  Sorry, that's not a valid input. Please enter a course name." << endl << "Course name: ";
    }

    cout << "  Course name was recorded as " << name << endl;

    int id;
    cout << "Course ID - please enter a number, with no spaces (any input after a space will not be included): ";
    cin >> id;

    // Continually prompt the user for input until an integer is passed
    while(!id) {
        cin.clear(); // Clear the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore all the inputted characters

        cout << "Sorry, that's not a valid input. Please enter a number, with no spaces." << endl << "Course ID: ";
        cin >> id;
    }

    cout << "  Course ID was recorded as " << name << endl;

    int assignmentCount;
    cout << "How many assignments can this course have? Please enter a number, with no spaces (any input after a space will not be included): ";
    cin >> assignmentCount;

    // Continually prompt the user for input until an integer is passed
    while(!assignmentCount) {
        cin.clear(); // Clear the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore all the inputted characters

        cout << "Sorry, that's not a valid input. Please enter a number, with no spaces." << endl << "Assignment count: ";
        cin >> assignmentCount;
    }

    cout << "  Assignment count was recorded as " << name << endl;

    string day;
    cout << "What day does this course run on? Please enter a day from Monday - Friday: ";

    transform(day.begin(), day.end(), day.begin(), ::tolower); // convert the user input to lowercase
    bool isDay = (day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday");

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, name) || name.empty() || (name != "monday")) {
        cout << "  Sorry, that's not a valid input. Please enter a day." << endl << "What day does this course run on? Please enter a day from Monday - Friday: ";
    }

    cout << "  Timetabled day was recorded as " << name << endl;

    Course course(name, id, assignmentCount, day);

    return course;
}

void Teacher::leaveCourse() {
    cout << "You have joined the following courses:" << endl;

    for (int i = 0; i < this->currentCourseCount; i++) {
        Course* course = this->teachableCourses[i];
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
        Course* course = this->teachableCourses[i];

        if (course->getName() == name) {
            delete this->teachableCourses[i]; // Delete the assignment from memory
            this->currentCourseCount--;
            cout << "You successfully left that course." << endl;
            return;
        }
    }

    cout << "The course you entered does not exist. Please try again." << endl;
}

void Teacher::grade() {
    cout << "### Grade an assignment ###" << endl;

    cout << "You are teaching the following courses:" << endl;

    for (int i = 0; i < this->currentCourseCount; i++) {
        Course* course = this->teachableCourses[i];
        cout << course->getName() << endl;
    }

    string name;
    cout << "Select a course: ";

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, name) || name.empty()) {
        cout << "Sorry, that's not a valid input. Please enter a course name." << endl << "Course name: ";
    }

    Course* course = nullptr;

    for (int i = 0; i < this->currentCourseCount; i++) {
        Course* t_course = this->teachableCourses[i];
        if (t_course->getName() == name) {
            course = t_course;
            break;
        }
    }

    if (!course) {
        cout << "You are not teaching the course that you entered, or it does not exist. Please try again.";
        return;
    }

    cout << "This course has the following assignments:";
    course->printAssignmentList();
    cout << "Select an assignment to grade:";

    string assignmentName;

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, assignmentName) || assignmentName.empty()) {
        cout << "Sorry, that's not a valid input. Please enter an assignment name." << endl << "Assignment name: ";
    }

    Assignment* assignment = course->getAssignment(assignmentName);

    if (!assignment) {
        cout << "That assignment is not a part of the selected course" << endl;
        return;
    }

    int grade;
    cout << "Grade (%) - please enter a number, with no spaces, between 0 and 100 (any input after a space will not be included): ";
    cin >> grade;

    // Continually prompt the user for input until an integer is passed
    while(!grade || grade < 0 || grade > 100) {
        cin.clear(); // Clear the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore all the inputted characters

        cout << "  Sorry, that's not a valid input. Please enter a number, with no spaces." << endl << "Grade (%): ";
        cin >> grade;
    }

    assignment->setGrade(grade);

    cout << "Assignment was successfully graded (" << grade << "%)" << endl;
}

void Teacher::printTitle() {
    cout << "### " << this->name << " (teacher) ###" << endl;
}

void Teacher::printEmail() {
    cout << "Email address: " << this->schoolID << "@teacher.edu" << endl;
}
