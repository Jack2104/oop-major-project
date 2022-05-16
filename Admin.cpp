#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "Admin.h"
// #include "Profile.h"
// #include "Teacher.h"
// #include "Student.h"
#include "Course.h"

using namespace std;

Admin::Admin(string name, string password, int schoolID) : Profile(name, password, schoolID) {};

Teacher* Admin::createTeacher(vector<Course>* courses) {
    cout << "### Creating profile: teacher ###" << endl;

    string name;
    cout << "Name: ";

    while (!getline(cin, name) || name.empty()) {
        cout << "Sorry, that's not a valid input. Please enter a name." << endl << "Name: ";
    }

    cout << "  Name was recorded as " << name << endl;

    int id;
    cout << "School ID - please enter a number, with no spaces (any input after a space will not be included): ";
    cin >> id;

    while(!id) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Sorry, that's not a valid input. Please enter a number, with no spaces." << endl << "School ID: ";
        cin >> id;
    }

    cout << "  School ID was recorded as " << name << endl;

    string password;
    cout << "Password: ";
    
    while (!getline(cin, password) || password.empty()) {
        cout << "Sorry, that's not a valid input. Please enter a passwoed." << endl << "Password: ";
    }

    cout << "  Password was recorded as " << password << endl;

    Teacher* teacher_ptr = new Teacher(name, password, id);

    cout << "The following courses are available to teach:" << endl;

    vector<Course>::iterator c_ptr;
    int i = 1;

    for(c_ptr = courses->begin(); c_ptr < courses->end(); c_ptr++) {
        cout << i << ". " << c_ptr->getName() << endl;
        i++;
    }

    cout << endl << "Select a course by entering its name: ";

    string courseName;

    while (getline(cin, courseName) && !courseName.empty()) {
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

// void Admin::removeProfile(string id, vector<Profile*> profiles) {
//     vector<Profile*>::iterator p_ptr = profiles.begin();

//     for(p_ptr = profiles.begin(); p_ptr < profiles.end(); p_ptr++) {
//         if ((*p_ptr)->getID() == id) {
//             remove(profiles.begin(), profiles.end(), p_ptr);
//         }
//     }
// }

void Admin::printTitle() {
    cout << this->name << " (admin)" << endl;
}

string Admin::constructEmail() {
    return to_string(this->schoolID) + "@admin.com";
}

