#include <iostream>
#include <string>

#include "Course.h"
#include "Assignment.h"

using namespace std;

Course::Course(string name, int courseID, int maxAssignmentCount, string day) {
    this->name = name;
    this->courseID = courseID;
    this->day =day.
    this->maxAssignmentCount = maxAssignmentCount;
    this->currentAssignmentCount = 0;

    this->assignments = new Assignment[this->maxAssignmentCount];
}

Course::Course() {};

Course::~Course() {
    delete[] this->assignments;
}

string Course::getName() {
    return this->name;
}

int Course::getCourseID() {
    return this->courseID;
}

string Course::getDay() {
    return this->day;
}

void Course::setName(string name) {
    this->name = name;
}

void Course::setCourseID(int id) {
    this->courseID = id;
}

void Course::setDay(string day) {
    this->day = day;
}

Assignment* Course::getAssignment(string name) {
    for (int i = 0; i < this->currentAssignmentCount; i++) {
        if (this->assignments[i].getName() == name) {
            return &(this->assignments[i]);
        }
    }

    return NULL;
}

void Course::addAssignment(Assignment assignment) {
    if (this->currentAssignmentCount < this->maxAssignmentCount) {
        this->currentAssignmentCount++;
        this->assignements[this->currentAssignmentCount] = assignment;
    }
}

void Course::createAssignment() {
    if (this->currentAssignmentCount >= this->maxAssignmentCount) {
        cout << "There are already enough assignments for this course!" << endl;
        return;
    }

    this->currentAssignmentCount++;

    cout << "### Create new assignment ###" << endl;

    string name;
    cout << "Assignment name: ";

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, name) || name.empty()) {
        cout << "Sorry, that's not a valid input. Please enter an assignment name." << endl << "Assignment name: ";
    }

    cout << "  Assignment name was recorded as " << name << endl;

    int weight;
    cout << "Assignment weighting (\% - please enter a value between 0 and 100): ";
    cin >> weight;

    // Continually prompt the user for input until an integer from 0-100 is passed
    while(!weight || weight < 0 || weight > 100) {
        cin.clear(); // Clear the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore all the inputted characters

        cout << "Sorry, that's not a valid input. Please enter a value between 0 and 100." << endl << "Assignment weighting: ";
        cin >> weight;
    }

    cout << "  Assignment weighting was recorded as " << weight << endl;

    string description;
    cout << "Assignment description (please limit to one line): ";

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, description) || description.empty()) {
        cout << "Sorry, that's not a valid input. Please enter an assignment name." << endl << "Assignment description: ";
    }

    cout << "  Assignment description was recorded as " << description << endl;

    this->assignments[this->currentAssignmentCount] = new Assignment(name, 0, weight, description);

    cout << "Assignment created!" << endl;
}

void Course::removeAssignment() {
    cout << "This course has the following assignments:" << endl;

    for (int i = 0; i < this->currentAssignmentCount; i++) {
        Assignment* assignment = this->assignments[i];
        cout << assignment->getName() << endl;
    }

    string name;
    cout << "Enter the name of the assignment you'd like to delete: ";

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, name) || name.empty() || !valid) {
        cout << "Sorry, that's not a valid input. Please enter an assignment name." << endl << "Assignment name: ";
    }

    for (int i = 0; i < this->currentAssignmentCount; i++) {
        if (this->assignements[i].getName() == name) {
            delete this->assignments[i];
            this->currentAssignmentCount--;
            cout << "Assignment was deleted" << endl;
            return
        }
    }

    cout << "The assignment you entered does not exist. Please try again." << endl;
}

int Course::calculateGrade() {
    int grade = 0;

    for (int i = 0; i < this->currentAssignmentCount; i++) {
        Assignment* assignment = this->assignments[i];
        grade += assignment->getGrade() * (assignment->getWeight() / 100);
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

    cout << "### Grade for " << this->name << " ###" << endl;
    cout << "Overall grade: " << letterGrade << "(" << grade << "%)" << endl;

    for (int i = 0; i < this->currentAssignmentCount; i++) {
        Assignment* assignment = this->assignments[i];
        cout << "  " << assignment->getName() << ": " << assignment.getGrade() << "(weighted" << assignment->getWeight() << "%)" << endl;
    }
}
