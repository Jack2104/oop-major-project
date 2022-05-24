#include <iostream>
#include <string>
#include <algorithm>

#include "Course.h"
#include "Assignment.h"
#include "Utils.h"

using namespace std;

Course::Course(string name, int courseID, int maxAssignmentCount, string day) {
    this->name = name;
    this->courseID = courseID;
    this->day = day;
    this->maxAssignmentCount = maxAssignmentCount;
    this->currentAssignmentCount = 0;

    this->assignments = new Assignment*[this->maxAssignmentCount];
}

Course::Course() {};

Course::~Course() {
    for (int i = 0; i < this->currentAssignmentCount; i++) {
        delete this->assignments[i];
    }

    delete[] this->assignments;
}

string Course::getName() {
    return this->name;
}

int Course::getCourseID() {
    if (courseID < 0) {
        return -1 * courseID;
    }

    return courseID;
}

string Course::getDay() {
    return this->day;
}

void Course::setName(string name) {
    this->name = name;
}

void Course::setCourseID(int id) {
    if (courseID < 0) {
        this->courseID = -1 * id;
    } else {
        this->courseID = id;
    }
}

void Course::setDay(string day) {
    transform(day.begin(), day.end(), day.begin(), ::tolower); // convert the user input to lowercase
    bool isDay = (day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday");

    if (isDay) {
        this->day = day;
    }
}

Assignment* Course::getAssignment(string name) {
    for (int i = 0; i < this->currentAssignmentCount; i++) {
        Assignment* assignment_ptr = this->assignments[i];

        if (assignment_ptr->getName() == name) {
            return this->assignments[i];
        }
    }

    return nullptr;
}

void Course::addAssignment(Assignment* assignment_ptr) {
    if (this->currentAssignmentCount < this->maxAssignmentCount) {
        this->assignments[this->currentAssignmentCount] = assignment_ptr;
        this->currentAssignmentCount++;
    }
}

void Course::createAssignment() {
    if (this->currentAssignmentCount >= this->maxAssignmentCount) {
        cout << "There are already enough assignments for this course!" << endl;
        return;
    }

    cout << endl << "### Create new assignment ###" << endl;

    string name = Utils::getStringInput("Assignment name", "can be anything", true);
    string description = Utils::getStringInput("Desctription", "please keep to one line", true);
    int weight = Utils::getIntInput("Assignment weighting", "\% - please enter a value between 0 and 100", true, 0, 100);

    this->assignments[this->currentAssignmentCount] = new Assignment(name, weight, description);
    this->currentAssignmentCount++;

    cout << "Assignment created!" << endl;
}

void Course::removeAssignment() {
    cout << endl << "This course has the following assignments:" << endl;
    this->printAssignmentList();

    string name = Utils::getStringInput("Assignment name", "the assignment to delete", false);

    // Find the assignment to be deleted
    for (int i = 0; i < this->currentAssignmentCount; i++) {
        Assignment* assignment = this->assignments[i];

        if (assignment->getName() == name) {
            for (int j = i; j < this->currentAssignmentCount - 1; j++) {
                this->assignments[j] = this->assignments[j + 1];
            }

            this->currentAssignmentCount--;
            cout << "Assignment was deleted" << endl;
            return;
        }
    }

    cout << "The assignment you entered does not exist. Please try again." << endl;
}

int Course::calculateGrade() {
    int grade = 0;

    for (int i = 0; i < this->currentAssignmentCount; i++) {
        Assignment* assignment_ptr = assignments[i];

        int assignmentGrade = assignment_ptr->getGrade();
        float assignmentWeight = (float)(assignment_ptr->getWeight()) / 100;

        grade += (int)(assignmentGrade * assignmentWeight); // Multiply the assignment grade by it's weighting
    }

    return grade;
}

char Course::percentageToLetterGrade(int percentage) {
    if (percentage >= 85) {
        return 'A';
    } else if (percentage >= 70) {
        return 'B';
    } else if (percentage >= 55) {
        return 'C';
    } else if (percentage >= 40) {
        return 'D';
    }

    return 'E';
}

void Course::printGrade() {
    int grade = this->calculateGrade();
    char letterGrade = this->percentageToLetterGrade(grade);

    cout << endl << "### Grade for " << this->name << " ###" << endl;
    cout << "Overall grade: " << letterGrade << " (" << grade << "%)" << endl;

    for (int i = 0; i < this->currentAssignmentCount; i++) {
        Assignment* assignment = this->assignments[i];
        cout << "  " << assignment->getName() << ": " << assignment->getGrade() << "% (weighted " << assignment->getWeight() << "%)" << endl;
    }
}

bool Course::printAssignmentList() {
    if (currentAssignmentCount == 0) {
        cout << "[this course has no assignments]" << endl;
        return false;
    }

    for (int i = 0; i < currentAssignmentCount; i++) {
        Assignment* assignment = assignments[i];
        cout << "• " << assignment->getName() << endl;
    }

    return true;
}

int Course::getCurrentAssignmentCount() {
    return this->currentAssignmentCount;
}
