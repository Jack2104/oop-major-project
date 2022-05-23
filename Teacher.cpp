#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Teacher.h"
#include "Course.h"

using namespace std;

Teacher::Teacher() { this->maxCourseCount = 4; };

Teacher::Teacher(string name, string password, int schoolID, int maxCourseCount) : Profile(name, password, schoolID) {
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

void Teacher::joinCourse(vector<Course*> courses) {
    if (this->currentCourseCount >= this->maxCourseCount) {
        cout << "Sorry, but you can't teach any more courses" << endl;
        return;
    }

    if (courses.size() == 0) {
        cout << "There are no courses available right now - try creating one!" << endl;
        return;
    }

    cout << endl << "The following courses are available to join:" << endl;

    vector<Course*>::iterator c_ptr;

    // Print the name of every course
    for(c_ptr = courses.begin(); c_ptr < courses.end(); c_ptr++) {
        Course* course = *c_ptr;
        cout << "• " << course->getName() << endl;
    }

    cout << endl << "Select a course by entering its name: ";

    string courseName;
    
    while (!getline(cin, courseName) || courseName.empty() || courseName.find_first_not_of(' ') == string::npos || courseName.find_first_not_of('	') == string::npos) {
        // Check to see if the inputted course is in the available courses list
        for(c_ptr = courses.begin(); c_ptr < courses.end(); c_ptr++) {
            Course* course = *c_ptr;

            if (course->getName() == courseName) {
                break;
            }
        }

        cout << courseName << " is not an available course. Please try again" << endl << "Select a course by entering its name: ";
    }

    // Check to see if the inputted course is in the available courses list
    for(c_ptr = courses.begin(); c_ptr < courses.end(); c_ptr++) {
        Course* course = *c_ptr;

        if (course->getName() == courseName) {
            this->teachableCourses[this->currentCourseCount] = course; // &(*c_ptr);
            cout << "You successfully joined " << courseName << endl;
            this->currentCourseCount++;
            return;
        }
    }
}

Course* Teacher::createCourse() {
    cout << endl << "### Create new course ###" << endl;

    string name;
    cout << "Course name: ";

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, name) || name.empty() || name.find_first_not_of(' ') == string::npos || name.find_first_not_of('	') == string::npos) {
        cout << "  Sorry, that's not a valid input. Please enter a course name." << endl << "Course name: ";
    }

    cout << "  Course name was recorded as " << name << endl;

    string day;
    cout << "What day does this course run on? Please enter a day from Monday - Friday: ";
    getline(cin, day);

    transform(day.begin(), day.end(), day.begin(), ::tolower); // convert the user input to lowercase
    bool isDay = (day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday");

    if (!isDay) {
        // Continually prompt the user for input until a valid input is entered
        while (!getline(cin, day) || day.empty() || !isDay || day.find_first_not_of(' ') == string::npos || day.find_first_not_of('	') == string::npos) {
            cout << "  Sorry, that's not a valid input. Please enter a day." << endl << "What day does this course run on? Please enter a day from Monday - Friday: ";
            transform(day.begin(), day.end(), day.begin(), ::tolower); // convert the user input to lowercase
            isDay = (day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday");
        }
    }
        
    cout << "  Timetabled day was recorded as " << day << endl;

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

    cout << "  Course ID was recorded as " << id << endl;

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

    cout << "  Assignment count was recorded as " << assignmentCount << endl;

    Course* course_ptr = new Course(name, id, assignmentCount, day);

    cout << endl << "Course created!" << endl;

    return course_ptr;
}

void Teacher::leaveCourse() {
    if (this->currentCourseCount == 0) {
        cout << "You haven't joined any courses yet" << endl;
    }

    cout << "You have joined the following courses:" << endl;

    for (int i = 0; i < this->currentCourseCount; i++) {
        Course* course = this->teachableCourses[i];
        cout << course->getName() << endl;
    }

    string name;
    cout << "Enter the name of the course you'd like to leave: ";

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, name) || name.empty() || name.find_first_not_of(' ') == string::npos || name.find_first_not_of('	') == string::npos) {
        cout << "Sorry, that's not a valid input. Please enter a course name." << endl << "Course name: ";
    }

    // Find the assignment to be deleted
    for (int i = 0; i < this->currentCourseCount; i++) {
        Course* course = this->teachableCourses[i];

        if (course->getName() == name) {
            for (int j = i; j < this->currentCourseCount - 1; j++) {
                this->teachableCourses[j] = this->teachableCourses[j + 1];
            }

            // delete this->teachableCourses[i]; // Delete the assignment from memory
            
            this->currentCourseCount--;
            cout << "You successfully left that course." << endl;
            return;
        }
    }

    cout << "The course you entered does not exist. Please try again." << endl;
}

void Teacher::grade() {
    if (this->currentCourseCount == 0) {
        cout << endl << "You aren't teaching any courses yet!" << endl;
        return;
    }

    cout << endl << "### Grade an assignment ###" << endl;

    Course* course = nullptr;

    while (!course) {
        cout << "You are teaching the following courses:" << endl;

        for (int i = 0; i < this->currentCourseCount; i++) {
            Course* course = this->teachableCourses[i];
            cout << "• " << course->getName() << endl;
        }

        string name;
        cout << endl << "Select a course: ";

        // Continually prompt the user for input until a valid input is entered
        while (!getline(cin, name) || name.empty() || name.find_first_not_of(' ') == string::npos || name.find_first_not_of('	') == string::npos) {
            cout << "Sorry, that's not a valid input. Please enter a course name." << endl << "Select a course: ";
        }

        for (int i = 0; i < this->currentCourseCount; i++) {
            Course* t_course = this->teachableCourses[i];
            if (t_course->getName() == name) {
                course = t_course;
                break;
            }
        }

        if (course && course->getCurrentAssignmentCount() == 0) {
            cout << "This course doesn't have any assignments." << endl;
            break;
        } else if (course) {
            break;
        }

        cout << "You are not teaching the course that you entered, or it does not exist. Please try again." << endl << endl;
    }

    // cout << "You are teaching the following courses:" << endl;

    // for (int i = 0; i < this->currentCourseCount; i++) {
    //     Course* course = this->teachableCourses[i];
    //     cout << course->getName() << endl;
    // }

    // string name;
    // cout << "Select a course: ";

    // // Continually prompt the user for input until a valid input is entered
    // while (!getline(cin, name) || name.empty() || name.find_first_not_of(' ') == string::npos || name.find_first_not_of('	') == string::npos) {
    //     cout << "Sorry, that's not a valid input. Please enter a course name." << endl << "Select a course: ";
    // }

    // for (int i = 0; i < this->currentCourseCount; i++) {
    //     Course* t_course = this->teachableCourses[i];
    //     if (t_course->getName() == name) {
    //         course = t_course;
    //         break;
    //     }
    // }

    // if (!course) {
    //     cout << "You are not teaching the course that you entered, or it does not exist. Please try again.";
    //     return;
    // }

    cout << endl << "This course has the following assignments:" << endl;
    bool hasCourses = course->printAssignmentList();
    cout << endl;

    if (!hasCourses) {
        return;
    }

    cout << "Select an assignment to grade: ";

    string assignmentName;

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, assignmentName) || assignmentName.empty() || assignmentName.find_first_not_of(' ') == string::npos || assignmentName.find_first_not_of('	') == string::npos) {
        cout << "Sorry, that's not a valid input. Please enter an assignment name." << endl << "Select an assignment to grade: ";
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

bool Teacher::printCourseList() {
    if (currentCourseCount == 0) {
        cout << "[you're not teaching any courses]" << endl;
        return false;
    }

    for (int i = 0; i < currentCourseCount; i++) {
        Course* course = teachableCourses[i];
        cout << "• " << course->getName() << endl;
    }

    return true;
}

vector<string> Teacher::getCourseNames() {
    vector<string> courseNames;

    for (int i = 0; i < this->currentCourseCount; i++) {
        Course* course = this->teachableCourses[i];
        courseNames.push_back(course->getName());
    }

    return courseNames;
}

void Teacher::printTitle() {
    cout << endl << "### " << this->name << " (teacher) ###" << endl;
}

void Teacher::printEmail() {
    cout << "Email address: " << this->schoolID << "@teacher.edu" << endl;
}
