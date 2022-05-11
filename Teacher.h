#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include "Profile.h"
#include "Course.h"

class Teacher : public Profile {
    public:
    Teacher();
    Teacher(int courseCount, string name, string password, int schoolID);
    ~Teacher();
    private:
    int courseCount;
    Course* teachableCourses;         
};

#endif
