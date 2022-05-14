#include <iostream>
#include <string>

#include "Profile.h"

using namespace std;

void Profile::Profile(string name, string password, int schoolID) {
    this->name = name;
    this->password = password;
    this->schoolID = schoolID;
};

string Profile::getName() { return name; };
void Profile::setName(string name) { this->name = name; }

string Profile::getPassword() { return name; };
void Profile::setPassword(string name) { this->password = password; }

int Profile::getID() {
    if (this->schoolID < 0) {
        return -1 * this->schoolID;
    }

    return this->schoolID;
};
void Profile::setID(int schoolID) {
    if (schoolID < 0) {
        this->schoolID = -1 * schoolID;
    } else {
        this->schoolID = schoolID;
    }
}
