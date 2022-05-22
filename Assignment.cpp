#include <iostream>
#include <string>

#include "Assignment.h"

using namespace std;

Assignment::Assignment() : name("[no name provided]"), grade(0), weight(0), description("[no description provided]") {};

Assignment::Assignment(string name, int weight, string description) {
    this->name = name;
    this->weight = weight;
    this->description = description;
    this->grade = 0;
};

void Assignment::setName(string name) {
    this->name = name;
}

void Assignment::setGrade(int grade) {
    if (grade > 100) {
        this->grade = 100;
    } else if (grade < 0) {
        this->grade = 0;
    } else {
        this->grade = grade;
    }
}

void Assignment::setWeight(int weight) {
    if (weight > 100) {
        this->weight = 100;
    } else if (weight < 0) {
        this->weight = 0;
    } else {
        this->weight = weight;
    }
}

void Assignment::setDescription(string description) {
    this->description = description;
}

string Assignment::getName() {
    return this->name;
}

int Assignment::getGrade() {
    if (grade > 100) {
        return 100;
    } else if (grade < 0) {
        return 0;
    }

    return this->grade;
}

int Assignment::getWeight() {
    if (weight > 100) {
        return 100;
    } else if (weight < 0) {
        return 0;
    }

    return this->weight;
}

string Assignment::getDescription() {
    return this->description;
}

void Assignment::printAssignmentInfo() {
    cout << endl << "### " << this->name << " ###" << endl;
    cout << "Weighting: " << this->weight << " / Grade: " << this->grade << "%" << endl;
    cout << "Description: " << this->description << endl;
}
