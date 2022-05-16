#ifndef TEACHER_H
#define TEACHER_H

#include <string>

#include "Profile.h"
#include "Course.h"
#include "Assignment.h"

using namespace std;

class Teacher : public Profile {
    private:
        // int courseCount; // Number of courses that the teacher can teach at a time
        int currentCourseCount;
        Course* teachableCourses; // Array of courses that the teacher can teach

    public:
        Teacher();
        Teacher(string name, string password, int schoolID);
        ~Teacher();

        /* Adds a course to teachableCourses */
        void joinCourse();

        /* Creates and returns a Course object */
        void createCourse();

        /* Deletes a course from the array courses */
        void deleteCourse(string courseName, Profile* courses);

        /* Prompts the user to grade a student's assignment */
        void grade(Assignment* assignment);

        /* Creates and returns an Assignment object */
        Assignment createAssignment();

        /* Abstract method implementation that prints the Teacher's name */
        void printTitle();

        /* Abstract method implementation that returns the teacher's email address */
        string constructEmail();
};

#endif
