#ifndef STUDENT_H
#define STUDENT_H

#include <string>

#include "Profile.h"
#include "Course.h"

using namespace std;

class Student : public Profile {
    private:
        int maxCourseCount; // Number of courses that the student can enrol in
        int currentCourseCount;
        Course** courses; // Array of courses the student is enrolled in

    public:
        Student();
        Student(string name, string password, int schoolID, int maxCourseCount);
        ~Student();

        /* Prints the courses that the student is enrolled in to the console */
        void printCourses();

        /* Prints the student's timetable to the console */
        void printTimetable();

        /* Prints the student's report card to the console */
        void printReport();

        /* Enrols the student in a course by name */
        void enrol(vector<Course>* courses, string name);

        /* Enrols the student in a course by ID */
        void enrol(vector<Course>* courses, int courseID);

        /* Unenrolls the student from a course by ID */
        void unenroll();

        /* Abstract method implementation that prints the students's name */
        void printTitle();

        /* Abstract method implementation that prints the students's email address */
        void printEmail();
};

#endif
