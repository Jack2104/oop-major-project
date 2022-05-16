#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "Admin.h"
// #include "Profile.h"
// #include "Teacher.h"
// #include "Student.h"

using namespace std;

Admin::Admin(string name, string password, int schoolID) : Profile(name, password, schoolID) {};

Teacher Admin::createTeacher(vector<Course>* courses) {
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

    while(!id || id.empty()){
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

    cout << "  Password was recorded as " << name << endl;

    cout << "The following courses are available to teach:" << endl;

    vector<Profile>::iterator c_ptr;
    int i = 1;

    for(c_ptr = *courses.begin(); c_ptr < *courses.end(); c_ptr++) {
        cout << i << ". " << c_ptr->getName() << endl;
        i++;
    }

    cout << endl << "Select a course by entering it's name: "


    

}

Student Admin::createStudent() {

}

Admin Admin::createAdmin() {

}

void Admin::removeProfile(string id, vector<Profile>* profiles) {
    vector<Profile>::iterator p_ptr;

    for(p_ptr = *profiles.begin(); p_ptr < *profiles.end(); ptr++) {
        if (ptr->getID() == id) {
            remove(*profiles.begin(), *profiles.end(), *prt)
        }
    }
}

void Admin::printTitle() {
    cout << this->name << " (admin)" << endl;
}

string Admin::constructEmail() {
    return this->schoolID + "@admin.com";
}

