#ifndef STUDENT_H
#define STUDENT_H

#include <string>

#include "Profile.h"
#include "Course.h"

using namespace std;

class Student : public Profile {
    private:
        int courseCount; // Number of courses that the student can enrol in
        Course** courses; // Array of courses the student is enrolled in

    public:
        Student();
        Student(int courseCount, string name, string password, int schoolID);
        ~Student();

        /* Prints the courses that the student is enrolled in to the console */
        void printCourses();

        /* Prints the student's timetable to the console */
        void printTimetable();

        /* Prints the student's report card to the console */
        void printReport();

        /* Enrols the student in a course by name */
        void enrol(string courseName);

        /* Unenrolls the student from a course by name */
        void unenroll(string courseName);

        /* Enrols the student in a course by ID */
        void enrol(int courseID);

        /* Unenrolls the student from a course by ID */
        void unenroll(int courseID);

        /* Abstract method implementation that prints the Teacher's name */
        void printTitle();

        /* Abstract method implementation that prints the teacher's email address */
        void printEmail();
};

#endif
