#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>

#include "Profile.h"
#include "Course.h"
#include "Assignment.h"

using namespace std;

class Teacher : public Profile {
    private:
        int maxCourseCount; // Number of courses that the teacher can teach at a time
        int currentCourseCount;
        Course** teachableCourses; // Array of courses that the teacher can teach

    public:
        Teacher();
        Teacher(string name, string password, int schoolID, int maxCourseCount);
        ~Teacher();

        /* Adds a course to teachableCourses */
        void joinCourse(vector<Course*> courses);

        /* Remoes a course from teachableCourses */
        void leaveCourse();

        /* Creates and returns a Course object */
        Course* createCourse(vector<Course*> courses);

        /* Prompts the user to grade a student's assignment */
        void grade();

        /* Creates and returns an Assignment object */
        // Assignment createAssignment();

        /* Prints the list of coruses that the teacher has joined */
        bool printCourseList();

        /* Returns a vector of all the teachable course names */
        vector<string> getCourseNames();

        /* Abstract method implementation that prints the Teacher's name */
        void printTitle();

        /* Abstract method implementation that prints the teacher's email address */
        void printEmail();
};

#endif
