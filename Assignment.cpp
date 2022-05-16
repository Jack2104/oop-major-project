#include <iostream>
#include <string>

#include "Assignment.h"

using namespace std;

Assignment::Assignment() : name("[no name]"), grade(0), weight(0), description("[no description]") {};

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
    this->grade = grade;
}

void Assignment::setWeight(int weight) {
    this->weight = weight;
}

void Assignment::setDescription(string description) {
    this->description = description;
}

string Assignment::getName() {
    return this->name;
}

int Assignment::getGrade() {
    return this->grade;
}

int Assignment::getWeight() {
    return this->weight;
}

string Assignment::getDescription() {
    return this->description;
}

void Assignment::printAssignmentInfo() {
    cout << "### " << this->name << " ###" << endl;
    cout << "Weighting: " << this->weight << " / Grade: " << this->grade << "%" << endl;
    cout << "Description: " << this->description << endl;
}
