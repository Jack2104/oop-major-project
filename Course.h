#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Assignment.h"

class Course {
    private:
        string name; // Course name
        int courseID; // Course specific ID 
        int assignmentCount; // Number of assignements for the course
        Assignment* assignments; // Array of assignments associated with the course
        string day; // 

    public:
        Course();
        Course(string name, int courseID, int assignmentCount);
        ~Course();

        /* Returns a specific Assignment object  */
        Assignment* getAssignment(string name);

        /* Assigns an assignment to the course */
        void addAssignment(Assignment* Assignment);

        /* Creates a new assignment */
        void createAssignment();

        /* Removes an assignment from the course */
        void removeAssignment(string name);

        /* Returns the calculated grade for the course */
        float calculateGrade();

        /* Converts and returns the calculated course grade to a grade letter */
        char percentageToLetterGrade(float percentage);

        /* prints the course grade to the user */
        void printGrade();

        /* returns course name */
        string getName();

        /* returns courseID */
        int getCourseID();

        /* returns day */
        void getDay();

        /* assigns a name to a course */
        void setName(string name);

        /* assigns a course ID to a course */
        void setCourseID(int courseID);
};

#endif
