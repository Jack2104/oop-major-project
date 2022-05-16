#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Assignment.h"

using namespace std;

class Course {
    private:
        string name; // Course name
        int courseID; // Course specific ID 
        int maxAssignmentCount; // Number of assignements for the course
        int currentAssignmentCount;
        Assignment* assignments; // Array of assignments associated with the course
        string day; // 

    public:
        Course();
        Course(string name, int courseID, int maxAssignmentCount, string day);
        ~Course();

        /* Returns a specific Assignment object  */
        Assignment* getAssignment(string name);

        /* Assigns an assignment to the course */
        void addAssignment(Assignment assignment);

        /* Creates a new assignment */
        void createAssignment();

        /* Removes an assignment from the course */
        void removeAssignment();

        /* Returns the calculated grade for the course, as a percentage */
        int calculateGrade();

        /* Converts and returns the calculated course grade to a grade letter */
        char percentageToLetterGrade(int percentage);

        /* Prints the course grade to the user */
        void printGrade();

        /* Returns the course name */
        string getName();

        /* Returns the courseID */
        int getCourseID();

        /* Returns the day that the class runs */
        string getDay();

        /* Assigns a name to a course */
        void setName(string name);

        /* Assigns a course ID to a course */
        void setCourseID(int courseID);

        /* Assigns a day to a course */
        void setDay(string name);
};

#endif
