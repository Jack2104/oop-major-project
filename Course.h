#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Assignment.h"

class Course {
    private:
        string name;
        int courseID;
        int assignmentCount;
        Assignment* assignments;
        string day;

    public:
        Course();
        Course(string name, int courseID, int assignmentCount);
        ~Course();
        Assignment* getAssignment(string name);
        void addAssignment(Assignment* Assignment);
        void createAssignment();
        void removeAssignment(string name);
        float calculateGrade();
        char percentageToLetterGrade(float percentage);
        void printGrade();
        string getName();
        int getCourseID();
        void getDay();
        void setName(string name);
        void setCourseID(int courseID);

};

#endif
