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

    Admin* defaultAdmin = new Admin("admin", "password", 1234);
    admins.push_back(defaultAdmin);

    // Course* course1_ptr = new Course("Philosophy 101", 1234, 4, "monday");
    // Course* course2_ptr = new Course("Maths", 3452, 4, "wednesday");
    // Course* course3_ptr = new Course("Programming", 2642, 4, "tuesday");
    // Course* course4_ptr = new Course("Physics 101", 2753, 4, "monday");

    // courses.push_back(course1_ptr);
    // courses.push_back(course2_ptr);
    // courses.push_back(course3_ptr);
    // courses.push_back(course4_ptr);

    cout << endl << "{}======== Welcome to SMS-cli ========{}" << endl;
    cout << "A command-line based school management system" << endl;

    // Keeps the program running until the console is closed
    while (true) {
        cout << endl << "What would you like to sign in as?" << endl << "(if this is your first time, the default admin account is called 'admin' and its password is 'password')" << endl << endl;
        cout << "1. Admin" << endl << "2. Teacher" << endl << "3. Student" << endl << endl;

        int accTypeInput = Utils::getIntInput("Select a number", "must be one of the displayed options", false, 1, 3);

        cout << endl << "### Login ###" << endl;

        string name = Utils::getStringInput("Name", "the name you signed up with", false);
        string password = Utils::getStringInput("Password", "cannot be whitespace only", false);

        // Only one of these variables will be assigned a value. This is done becaues subclass-specific
        // functions are used, and so a Profile* pointer cannot be used. Initializing these three variables
        // could be avoided, but it would require more deeply-nested code, and so for the sake of readability
        // the current implementation was decided upon
        Admin* selectedAdmin = nullptr;
        Teacher* selectedTeacher = nullptr;
        Student* selectedStudent = nullptr;

        // Note: while there is repetition in the following switch statement (which, yes, does introduce technical debt), it is relatively harmless imo
        if (accTypeInput == 1) {
            vector<Admin*>::iterator a_ptr;

            for (a_ptr = admins.begin(); a_ptr < admins.end(); a_ptr++) {
                if ((*a_ptr)->getName() == name && (*a_ptr)->getPassword() == password) {
                    selectedAdmin = *a_ptr;
                    break;
                }
            }
        } else if (accTypeInput == 2) {
            vector<Teacher*>::iterator t_ptr;

            for (t_ptr = teachers.begin(); t_ptr < teachers.end(); t_ptr++) {
                if ((*t_ptr)->getName() == name && (*t_ptr)->getPassword() == password) {
                    selectedTeacher = *t_ptr;
                    break;
                }
            }
        } else if (accTypeInput == 3) {
            vector<Student*>:: iterator s_ptr;

            for (s_ptr = students.begin(); s_ptr < students.end(); s_ptr++) {
                if ((*s_ptr)->getName() == name && (*s_ptr)->getPassword() == password) {
                    selectedStudent = *s_ptr;
                    break;
                }
            }
        }

        // There was no user with the name and password that was entered, so start again
        if (!selectedAdmin && !selectedTeacher && !selectedStudent) {
            cout << "There's no profile with that name and password. Please try again." << endl << endl;
            continue;
        }

        // One the user completes an action, they are brought back to the beginning (here), so that they don't have to sign in again
        while (true) {
            // Handle the user actions
            if (accTypeInput == 1) { // Admin
                selectedAdmin->printTitle();
                selectedAdmin->printEmail();

                cout << endl << "Please select one of the following actions:" << endl;

                cout << "1. Create a new admin profile" << endl;
                cout << "2. Create a new teacher profile" << endl;
                cout << "3. Create a new student profile" << endl;
                cout << "4. Go back" << endl << endl;

                int adminAction = Utils::getIntInput("Select a number", "must be one of the displayed options", false, 1, 4);

                if (adminAction == 1) {
                    Admin* newAdmin = selectedAdmin->createAdmin();
                    admins.push_back(newAdmin);
                } else if (adminAction == 2) {
                    Teacher* newTeacher = selectedAdmin->createTeacher(courses);
                    teachers.push_back(newTeacher);
                } else if (adminAction == 3) {
                    Student* newStudent = selectedAdmin->createStudent(courses);
                    students.push_back(newStudent);
                } else if (adminAction == 4) {
                    break; // Go back to the action selection screen
                }
            } else if (accTypeInput == 2) { // Teacher
                selectedTeacher->printTitle();
                selectedTeacher->printEmail();

                cout << endl << "Please select one of the following actions:" << endl;

                cout << "1. Join a course" << endl;
                cout << "2. Leave a course" << endl;
                cout << "3. Create a new course" << endl;
                cout << "4. Create a new assignment" << endl;
                cout << "5. Grade an assignment" << endl;
                cout << "6. Go back" << endl << endl;

                int teacherAction = Utils::getIntInput("Select a number", "must be one of the displayed options", false, 1, 6);

                if (teacherAction == 1) {
                    selectedTeacher->joinCourse(courses);
                } else if (teacherAction == 2) {
                    selectedTeacher->leaveCourse();
                } else if (teacherAction == 3) {
                    Course* newCourse = selectedTeacher->createCourse(courses);
                    
                    if (newCourse)
                        courses.push_back(newCourse);
                } else if (teacherAction == 4) {
                    cout << endl << "You are teaching the following courses:" << endl;
                    
                    bool hasCourses = selectedTeacher->printCourseList();

                    cout << endl;

                    if (!hasCourses) {
                        cout << "Join a course to create a new assignment." << endl;
                        continue;
                    }

                    vector<string> courseNames = selectedTeacher->getCourseNames();

                    string courseInput = Utils::getStringInput("Select a course to create an assignment for", "must be one of the above courses", false, courseNames);

                    Course* selectedCourse = nullptr;

                    vector<Course*>::iterator c_ptr;

                    for (c_ptr = courses.begin(); c_ptr < courses.end(); c_ptr++) {
                        if ((*c_ptr)->getName() == courseInput) {
                            selectedCourse = *c_ptr;
                            break;
                        }
                    }

                    selectedCourse->createAssignment();
                } else if (teacherAction == 5) {
                    selectedTeacher->grade();
                } else if (teacherAction == 6) {
                    break; // Go back to the action selection screen
                }
            } else if (accTypeInput == 3) { // Student
                selectedStudent->printTitle();
                selectedStudent->printEmail();

                cout << endl << "Please select one of the following actions:" << endl;

                cout << "1. View courses" << endl;
                cout << "2. View timetable" << endl;
                cout << "3. View report" << endl;
                cout << "4. Enrol in a course" << endl;
                cout << "5. Unnroll in a course" << endl;
                cout << "6. Go back" << endl << endl;

                int studentAction = Utils::getIntInput("Select a number", "must be one of the displayed options", false, 1, 6);

                cout << endl;

                if (studentAction == 1) {
                    selectedStudent->printCourses();
                } else if (studentAction == 2) {
                    selectedStudent->printTimetable();
                } else if (studentAction == 3) {
                    selectedStudent->printReport();
                } else if (studentAction == 4) {
                    cout << "Would you like to enrol in a course by name or ID?" << endl;
                    cout << "1. Course name" << endl;
                    cout << "2. Course ID" << endl << endl;

                    int enrollmentType = Utils::getIntInput("Select a number", "must be one of the displayed options", false, 1, 2);

                    cout << "The following courses are available to enrol in:" << endl;

                    vector<Course*>::iterator c_ptr;

                    // Print all the course names/IDs to the console
                    for (c_ptr = courses.begin(); c_ptr < courses.end(); c_ptr++) {
                        if (enrollmentType == 1) {
                            cout << "• " << (*c_ptr)->getName() << endl;
                            continue;
                        }

                        cout << "• " << (*c_ptr)->getCourseID() << endl;
                    }

                    cout << endl;

                    // Determine which enrol() function to use (run-time polymorphism)
                    if (enrollmentType == 1) {
                        string courseName = Utils::getStringInput("Course name", "enter one of the above course names", false);
                        selectedStudent->enrol(courses, courseName);
                    } else if (enrollmentType == 2) {
                        int courseID = Utils::getIntInput("Course ID", "enter one of the above course IDs", false);
                        selectedStudent->enrol(courses, courseID);
                    }
                } else if (studentAction == 5) {
                    selectedStudent->unenroll();
                } else if (studentAction == 6) {
                    break; // Go back to the action selection screen
                }
            }
        }
    }

    return 0;
}
