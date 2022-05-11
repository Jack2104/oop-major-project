#ifndef TEACHER_H
#define TEACHER_H

#include <string>

#include "Profile.h"
#include "Course.h"
#include "Assignment.h"

class Teacher : public Profile {
    private:
        int courseCount;
        Course* teachableCourses;

    public:
        Teacher();
        Teacher(int courseCount, std::string name, std::string password, int schoolID);
        ~Teacher();
        void createCourse();
        void deleteCourse();
        void printTitle();
        std::string constructEmail();
        void grade(Assignment* Assignment);
        Assignment createAssignment();
};

#endif
