#include <iostream>
#include <string>
#include <vector>

#include "Profile.h"
#include "Admin.h"
#include "Teacher.h"
#include "Student.h"
#include "Course.h"
#include "Assignment.h"
#include "Utils.h"

using namespace std;

int main() {
    vector<Admin*> admins;
    vector<Teacher*> teachers;
    vector<Student*> students;
    vector<Course*> courses;

    // Course* course1_ptr = new Course("Philosophy 101", 1234, 4, "monday");
    // Course* course2_ptr = new Course("Maths", 3452, 4, "wednesday");
    // Course* course3_ptr = new Course("Programming", 2642, 4, "tuesday");
    // Course* course4_ptr = new Course("Physics 101", 2753, 4, "monday");

    // courses.push_back(course1_ptr);
    // courses.push_back(course2_ptr);
    // courses.push_back(course3_ptr);
    // courses.push_back(course4_ptr);

    Admin* admin = new Admin("admin", "password", 0);
    admins.push_back(admin);

    cout << "{}======== Welcome to SMS-cli ========{}" << endl;
    cout << "A command-line based school management system" << endl << endl;

    while (true) {
        cout << "What would you like to sign in as?" << endl << "(if this is your first time, the default admin account is called 'admin' and its password is 'password')" << endl << endl;
        cout << "1. Admin" << endl << "2. Teacher" << endl << "3. Student" << endl << endl;

        vector<string> validAccInputs;
        validAccInputs.push_back("1");
        validAccInputs.push_back("2");
        validAccInputs.push_back("3");

        string accTypeInput = Utils::getStringInput("Select a number", "must be one of the displayed options", false, validAccInputs);

        cout << endl << "### Login ###" << endl;

        // cout << "Enter your name: ";
        string name = Utils::getStringInput("Name", "the name you signed up with", true);

        // cout << "Enter your password: ";
        string password = Utils::getStringInput("Password", "cannot be whitespace only", true);

        Profile* selectedProfile = nullptr;

        // Sign in and set the logged in profile
        switch (accTypeInput) {
            case "1":
                vector<Admin*>:: iterator a_ptr;

                for (a_ptr = admins.begin(); a_ptr < admins.end(); a_ptr++) {
                    if (a_ptr->getName() == name && a_ptr->getPassword() == password) {
                        selectedProfile = &(*a_ptr);
                        break;
                    }
                }
                break;

            case "2":
                vector<Teacher*>:: iterator t_ptr;

                for (t_ptr = teachers.begin(); t_ptr < teachers.end(); t_ptr++) {
                    if (t_ptr->getName() == name && t_ptr->getPassword() == password) {
                        selectedProfile = &(*t_ptr);
                        break;
                    }
                }
                break;

            case "3":
                vector<Student*>:: iterator s_ptr;

                for (s_ptr = students.begin(); s_ptr < students.end(); s_ptr++) {
                    if (s_ptr->getName() == name && s_ptr->getPassword() == password) {
                        selectedProfile = &(*s_ptr);
                        break;
                    }
                }
                break;
        }

        // There was no user with the name and password that was entered, so start again
        if (!selectedProfile) {
            cout << 
            continue;
        }


    }

    return 0;
}
