#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "Profile.h"

class Admin : public Profile {
    public:
    void createTeacher();
    void removeTeacher(std::string ID);
    void createStudent();
    void removeStudent(std::string ID);
    void createAdmin();
    void removeAdmin(std::string ID);
    std::string printTitle();
    std::string constructEmail();
};

#endif
