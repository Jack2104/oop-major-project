#include <iostream>
#include <string>

#include "Profile.h"

using namespace std;

Profile::Profile() {
    name = "?";
    password = "?";
    schoolID = 0;
};

Profile::Profile(string name, string password, int schoolID) {
    this->name = name;
    this->password = password;
    this->schoolID = schoolID;
};

string Profile::getName() { return name; };
void Profile::setName(string name) { this->name = name; }

string Profile::getPassword() { return password; };
void Profile::setPassword(string password) { this->password = password; }

int Profile::getID() {
    if (schoolID < 0) {
        return -1 * schoolID;
    }

    return schoolID;
};
void Profile::setID(int schoolID) {
    if (schoolID < 0) {
        this->schoolID = -1 * schoolID;
    } else {
        this->schoolID = schoolID;
    }
}

// Abstract methods
void Profile::printTitle() {};
void Profile::constructEmail() {};
