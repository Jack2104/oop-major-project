#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "Admin.h"
#include "Profile.h"
#include "Teacher.h"
#include "Student.h"
#include "Course.h"
#include "Utils.h"

using namespace std;

Admin::Admin(string name, string password, int schoolID) : Profile(name, password, schoolID) {};

Teacher* Admin::createTeacher(vector<Course*> courses) {
    cout << endl << "### Creating profile: teacher ###" << endl;

    string name = Utils::getStringInput("Name", "or a username", true);
    string password = Utils::getStringInput("Password", "case sensitive", true);

    int id = Utils::getIntInput("School ID", "please enter a number, with no spaces", true);
    int maxCourseCount = Utils::getIntInput("Maximum course count", "please enter a number, with no spaces", true);

    Teacher* teacher_ptr = new Teacher(name, password, id, maxCourseCount);

    return teacher_ptr;
}

Student* Admin::createStudent(vector<Course*> courses) {
    cout << endl << "### Creating profile: student ###" << endl;

    string name = Utils::getStringInput("Name", "or username", true);
    string password = Utils::getStringInput("Password", "case sensitive", true);

    int id = Utils::getIntInput("School ID", "please enter a number, with no spaces", true);
    int maxCourseCount = maxCourseCount = Utils::getIntInput("Maximum course count", "please enter a number, with no spaces", true);
    
    Student* student_ptr = new Student(name, password, id, maxCourseCount);

    return student_ptr;
}

Admin* Admin::createAdmin() {
    cout << endl << "### Creating profile: admin ###" << endl;

    string name = Utils::getStringInput("Name", "or username", true);
    string password = Utils::getStringInput("Password", "case sensitive", true);
    int id = Utils::getIntInput("School ID", "please enter a number, with no spaces", true);

    Admin* admin_ptr = new Admin(name, password, id);

    return admin_ptr;
}

void Admin::printTitle() {
    cout << endl << "### " << this->name << " (admin) ###" << endl;
}

void Admin::printEmail() {
    cout << "Email address: " << this->schoolID << "@admin.edu" << endl;
}

