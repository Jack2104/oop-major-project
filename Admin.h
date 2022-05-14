#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "Profile.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;

class Admin : public Profile {
    public:
        /* Creates and returns a new Teacher object */
        Teacher createTeacher();

        /* Deletes a teacher that has the specified ID from the array teachers */
        void removeTeacher(string ID, Profile* teachers);

        /* Creates and returns a new Student object */
        Student createStudent();

        /* Deletes a student that has the specified ID from the array students */
        void removeStudent(string ID, Profile* students);

        /* Creates and returns a new Admin object */
        Admin createAdmin();

        /* Deletes an admin that has the specified ID from the array admins */
        void removeAdmin(string ID, Profile* admins);

        /* Abstract method implementation that prints the admin's name and ID */
        void printTitle();

        /* Abstract method implementation that returns the admin's email address */
        string constructEmail();
};

#endif

// slaylawashere
