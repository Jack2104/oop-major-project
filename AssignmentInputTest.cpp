#include <iostream>
#include <string>

#include "Assignment.h"

int main() {
    Assignment assignment("Major practical", 100, "A big project");
    assignment.setGrade(100);

    std::cout << "Testing printAssignmentInfo()..." << std::endl;
    assignment.printAssignmentInfo();

    cout << endl;
    assignment.setGrade(87);
    assignment.setName("Practical Exam");
    assignment.setWeight(15);
    assignment.setDescription("In person Exam");
    cout << "Assignment: " << assignment.getName() << endl;
    cout << "Description: " << assignment.getDescription() << endl;
    cout << "Weight: " << assignment.getWeight() << endl;
    cout << "Grade: " << assignment.getGrade() << endl;

    return 0;
}
