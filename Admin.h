#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>

#include "Profile.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;

class Admin : public Profile {
    public:
        Admin(string name, string password, int schoolID);

        /* Creates and returns a new Teacher object */
        Teacher* createTeacher(vector<Course>* courses);

        /* Creates and returns a new Student object */
        Student createStudent();

        /* Creates and returns a new Admin object */
        Admin createAdmin();

        /* Deletes a profile that has the specified ID from the array profiles */
        // void removeProfile(int id, vector<Profile*> profiles);

        /* Abstract method implementation that prints the admin's name and ID */
        void printTitle();

        /* Abstract method implementation that returns the admin's email address */
        string constructEmail();
};

#endif

// slaylawashere
