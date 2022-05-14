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

int Profile::getID() { return name; };
void Profile::setID(string name) { this->schoolID = schoolID; }
