#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "Admin.h"
#include "Profile.h"
#include "Teacher.h"
#include "Student.h"
#include "Course.h"

using namespace std;

Admin::Admin(string name, string password, int schoolID) : Profile(name, password, schoolID) {};

Teacher* Admin::createTeacher(vector<Course>* courses) {
    cout << "### Creating profile: teacher ###" << endl;

    string name;
    cout << "Name: ";

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, name) || name.empty()) {
        cout << "Sorry, that's not a valid input. Please enter a name." << endl << "Name: ";
    }

    cout << "  Name was recorded as " << name << endl;

    int id;
    cout << "School ID - please enter a number, with no spaces (any input after a space will not be included): ";
    cin >> id;

    // Continually prompt the user for input until an integer is passed
    while(!id) {
        cin.clear(); // Clear the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore all the inputted characters

        cout << "Sorry, that's not a valid input. Please enter a number, with no spaces." << endl << "School ID: ";
        cin >> id;
    }

    cout << "  School ID was recorded as " << name << endl;

    string password;
    cout << "Password: ";
    
    // Like for name, prompt the user for input until a non-empty string is entered
    while (!getline(cin, password) || password.empty()) {
        cout << "Sorry, that's not a valid input. Please enter a passwoed." << endl << "Password: ";
    }

    cout << "  Password was recorded as " << password << endl;

    Teacher* teacher_ptr = new Teacher(name, password, id);

    cout << "The following courses are available to teach:" << endl;

    vector<Course>::iterator c_ptr;

    // Print the name of every course
    for(c_ptr = courses->begin(); c_ptr < courses->end(); c_ptr++) {
        cout << c_ptr->getName() << endl;
    }

    cout << endl << "Select a course by entering its name: ";

    string courseName;

    // Continually prompt the user to enter a course until only a newline is entered (and then move on)
    while (getline(cin, courseName) && !courseName.empty()) {
        // Check to see if the inputted course is in the available courses list
        for(c_ptr = courses->begin(); c_ptr < courses->end(); c_ptr++) {
            if (c_ptr->getName() == courseName) {
                // teacher_ptr->joinCourse(c_ptr);
                cout << courseName << " was accepted" << endl << "Select a course by entering its name: ";
                break;
            }
        }

        cout << courseName << " is not an available course. Please try again" << endl << "Select a course by entering its name: ";
    }

    return teacher_ptr;
}

// Student Admin::createStudent() {
//     // Student student(name, password, id);
//     Student student;

//     return student;
// }

// Admin Admin::createAdmin() {
//     // Admin admin(name, password, id);
//     Admin admin;

//     return admin;
// }

// void Admin::removeProfile(int id, vector<Profile*> profiles) {
//     vector<Profile*>::iterator p_ptr = profiles.begin();

//     for(p_ptr = profiles.begin(); p_ptr < profiles.end(); p_ptr++) {
//         if ((*p_ptr)->getID() == id) {
//             remove(profiles.begin(), profiles.end(), *p_ptr);
//         }
//     }
// }

void Admin::printTitle() {
    cout << "### " << this->name << " (admin) ###" << endl;
}

void Admin::printEmail() {
    cout << "Email address: " << this->schoolID << "@admin.edu";
}

