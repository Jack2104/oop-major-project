#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Profile.h"
#include "Course.h"

class Student : public Profile {
    private:
    int courseCount;
    Course* courses;
    public:
    Student();
    Student(int courseCount, std::string name, std::string password, int schoolID);
    ~Student();
    void printCourses();
    void printTimetable();
    void printReport();
    void enrol(std::string courseName);
    void unenrol(std::string courseName);
    void enrol(int courseName);
    void unenrol(int courseID);
    void printTitle();
    std::string constructEmail();
};

#endif
